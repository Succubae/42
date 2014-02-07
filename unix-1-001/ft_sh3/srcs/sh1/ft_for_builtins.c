/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 11:21:46 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 17:44:31 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

void	delete_char_tab_tab(char**);

char	*ft_getenv(char *s, char **env)
{
	int		i;
	int		j;
	char	*ret;

	i = j = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(s, env[i], ft_strlen(s)) == 0)
		{
			j = ft_strichr(env[i], '=');
			ret = ft_strdup(env[i] + j + 1);
			return (ret);
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
	arg[1] = ft_strdup(varname);
	arg[2] = ft_strdup(varvalue);
	free(varvalue);
	arg[3] = (char*)malloc(sizeof(char) * 2);
	if (ow == 1)
	{
		arg[3][0] = '1';
		arg[3][1] = '\0';
	}
	else
	{
		arg[3][0] = '0';
		arg[3][1] = '\0';
	}
	arg[4] = NULL;
	return (arg);
}

int		ft_check_setenv_ag(char **arg)
{
	if (arg[1] && arg[2] && arg[3])
		return (0);
	else
	{
		ft_error("Setenv error.\n");
		ft_error("Usage : setenv (char*)name (char*)value (int)overwrite\n");
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
		if ((*env)[i] == NULL)
			break ;
		tmp[j] = ft_strdup((*env)[i]);
		j++;
		i++;
	}
	tmp[j] = NULL;
	delete_char_tab_tab((*env));
	(*env) = tmp;
}

void	ft_realloc_env(char ***env, char **arg)
{
	char	**tmp;
	char	*s1;
	int		i;
	int		l;

	i = 0;
	while ((*env)[i] != NULL)
		i++;
	if (!(tmp = (char**)malloc(sizeof(char*) * (i + 2))))
		ft_error_malloc("set new environment variable");
	i = -1;
	while (i++, (*env)[i] != NULL)
		tmp[i] = ft_strdup((*env)[i]);
	l = ft_strlen(arg[1]) + ft_strlen(arg[2]);
	if (!(tmp[i] = (char*)malloc(sizeof(char) * (l + 1))))
		ft_error_malloc("set new environment variable");
	s1 = ft_strjoin("=", arg[2]);
	tmp[i] = ft_strjoin(arg[1], s1);
	free(s1);
	tmp[i][l + 2] = '\0';
	tmp[i + 1] = NULL;
	delete_char_tab_tab((*env));
	(*env) = tmp;
}
