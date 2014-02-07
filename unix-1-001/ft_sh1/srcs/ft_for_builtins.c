/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 11:21:46 by rgary             #+#    #+#             */
/*   Updated: 2013/12/26 10:47:41 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_sh1.h"

extern char	**environ;

char	*ft_getenv(char *s, char **env)
{
	int		i;
	int		j;

	i = j = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(s, env[i], ft_strlen(s)) == 0)
		{
			j = ft_strichr(env[i], '=');
			return (s = env[i] + j + 1);
		}
		i++;
	}
	return (NULL);
}

char	**ft_b_setenv_tab(char *varname, char *varvalue, int ow)
{
	char	**arg;

	if (!(arg = (char**)malloc(sizeof(char*) * 5)))
	{
		ft_error_malloc("set environment variables");
		return (NULL);
	}
	arg[0] = NULL;
	arg[1] = varname;
	arg[2] = varvalue;
	arg[3] = ft_itoa(ow);
	arg[4] = NULL;
	return (arg);
}

int		ft_check_setenv_ag(char **arg, char **varn, char **varvalue, int *ow)
{
	if (arg[1] && arg[2] && arg[3])
	{
		*varn = ft_strtoupper(ft_strdup(arg[1]));
		*varvalue = ft_strdup(arg[2]);
		*ow = ft_atoi(arg[3]);
	}
	else
	{
		FP("Setenv error.\n");
		FP("Usage : setenv (char*)name (char*)value (int)overwrite\n");
		return (-1);
	}
	return (0);
}

void	ft_realloc_env_rev(char ***env, char *varname)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while ((*env)[i] != NULL)
		i++;
	if (!(tmp = (char**)malloc(sizeof(char*) * i)))
		ft_error_malloc("unset environment variable");
	i = j = 0;
	while ((*env)[i] != NULL)
	{
		if (ft_strncmp((*env)[i], varname, ft_strlen(varname)) == 0)
			i++;
		tmp[j] = (*env)[i];
		i++;
		j++;
	}
	tmp[j] = NULL;
	free((*env));
	(*env) = tmp;
}

void	ft_realloc_env(char ***env, char* varname, char* varvalue)
{
	char	**tmp;
	int		i;
	int		l;

	i = 0;
	while ((*env)[i] != NULL)
		i++;
	if (!(tmp = (char**)malloc(sizeof(char*) * (i + 2))))
		ft_error_malloc("set new environment variable");
	i = 0;
	while ((*env)[i] != NULL)
	{
		tmp[i] = (*env)[i];
		i++;
	}
	l = ft_strlen(varname) + ft_strlen(varvalue);
	if (!(tmp[i] = (char*)malloc(sizeof(char) * (l + 2))))
		ft_error_malloc("set new environment variable");
	tmp[i] = ft_strjoin(varname, ft_strjoin("=", varvalue));
	tmp[i][l + 2] = '\0';
	tmp[i + 1] = NULL;
	(*env) = tmp;
}
