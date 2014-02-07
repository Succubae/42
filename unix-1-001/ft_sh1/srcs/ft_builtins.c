/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 17:51:44 by rgary             #+#    #+#             */
/*   Updated: 2013/12/28 14:02:52 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "ft_sh1.h"

void	ft_cd(char ***env, char **arg)
{
	int		i;
	int		j;
	int		k;
	char	*lib_cd[3] = {"/", ".", "~"};

	i = k = 1;
	j = 0;
	if (arg[i] != NULL)
	{
		if (arg[i][0] == '-' && arg[i][1] == '\0')
		{
			ft_go_oldpwd(env);
			k = 0;
		}
	}
	while (j < 3 && k == 1)
	{
		k = ft_compare_cd_operation(arg[i], lib_cd, env, j);
		j++;
	}
	if (j == 3 && arg[i] != NULL)
		ft_other(env, arg[i]);
}

void	ft_setenv(char ***env, char **arg)
{
	char	*varname;
	char	*varvalue;
	int		overwrite;
	int		i;

	i = 0;
	if (ft_check_setenv_ag(arg, &varname, &varvalue, &overwrite) != 0)
		return ;
	while ((*env)[i] != NULL)
	{
		if (ft_strncmp((*env)[i], varname, ft_strlen(varname)) == 0)
		{
			if (overwrite == 0)
				return ;
			if (overwrite != 0)
			{
				(*env)[i] = ft_strjoin(varname, ft_strjoin("=", varvalue));
				return ;
			}
		}
		i++;
	}
	ft_realloc_env(env, varname, varvalue);
	(void)arg;
}

void	ft_unsetenv(char ***env, char **arg)
{
	if (ft_check_var_exist(arg[1], (*env)) == 1)
		ft_realloc_env_rev(env, arg[1]);
	else
		ft_error_unsetenv(arg[1]);
}

void	ft_env(char ***env, char **arg)
{
	int		i;
	int		j;
	char	**envcpy;

	i = j = 1;
	if (arg[i] != NULL && ft_strncmp(arg[i], "-i", 2) == 0)
	{
		ft_chopchop_env((*env), &envcpy);
		i++;
		j++;
	}
	else
		ft_copy_environ((*env), &envcpy);
	if (arg[i] != NULL)
	{
		while (arg[i] != NULL && ft_strichr(arg[i], '=') != -1)
		{
			ft_chopchop(&envcpy, arg[i]);
			i++;
		}
	}
	ft_execute_or_print_env(envcpy, arg, i, j);
	free(envcpy);
}

void	ft_exit(char ***env, char **arg)
{
	(void)env;
	(void)arg;
	exit(0);
}
