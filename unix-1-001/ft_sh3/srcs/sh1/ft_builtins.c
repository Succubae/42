/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 17:51:44 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 17:40:47 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

void	delete_char_tab_tab(char **com);
void	change_back_term_info(void);

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
	int		i;

	i = -1;
	if (ft_check_setenv_ag(arg) != 0)
		return ;
	while (i++, (*env)[i] != NULL)
	{
		if (ft_strncmp((*env)[i], arg[1], ft_strlen(arg[1])) == 0)
		{
			if (arg[3][0] == '0')
				return ;
			else
			{
				for_a_better_setenv(arg, env, i);
				return ;
			}
		}
	}
	ft_realloc_env(env, arg);
}

void	ft_unsetenv(char ***env, char **arg)
{
	if (ft_strcmp(arg[1], "PWD") == 0 || ft_strcmp(arg[1], "OLDPWD") == 0
		|| ft_strcmp(arg[1], "USER") == 0 || ft_strcmp(arg[1], "HOME") == 0)
	{
		FP2("Protected Variable. Aborting..\n", 2);
		return ;
	}
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
	delete_char_tab_tab(envcpy);
}

void	ft_exit(char ***env, char **arg)
{
	(void)env;
	(void)arg;
	change_back_term_info();
	exit(0);
}
