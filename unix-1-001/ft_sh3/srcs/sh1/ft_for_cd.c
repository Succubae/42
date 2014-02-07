/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 13:31:42 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 17:08:36 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

void	ft_null(char ***env, char *arg)
{
	char	*tmp;
	char	**cmd;

	(void)arg;
	if ((tmp = ft_getenv("HOME", (*env))) == NULL)
		return ;
	if (chdir(tmp) < 0)
	{
		ft_error_chdir("HOME");
		return ;
	}
	cmd = ft_b_setenv_tab("PWD", tmp, 1);
	ft_setenv(env, cmd);
	for_a_better_other(cmd);
}

void	ft_slash(char ***env, char *arg)
{
	char	*join;
	char	*tmp;
	char	**cmd;

	if (chdir(arg) < 0)
	{
		ft_error_chdir(arg);
		return ;
	}
	join = ft_cleanup_pwd(arg);
	tmp = ft_getenv("PWD", (*env));
	cmd = ft_b_setenv_tab("OLDPWD", tmp, 1);
	ft_setenv(env, cmd);
	for_a_better_other(cmd);
	cmd = ft_b_setenv_tab("PWD", join, 1);
	ft_setenv(env, cmd);
	for_a_better_other(cmd);
}

void	ft_dot(char ***env, char *arg)
{
	char	*join;
	char	*tmp;
	char	*tmp2;
	char	**cmd;

	tmp = ft_getenv("PWD", (*env));
	tmp2 = ft_strjoin("/", arg);
	join = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	if (chdir(join) < 0)
	{
		ft_error_chdir(join);
		return ;
	}
	join = ft_cleanup_pwd(join);
	tmp = ft_getenv("PWD", (*env));
	cmd = ft_b_setenv_tab("OLDPWD", tmp, 1);
	ft_setenv(env, cmd);
	for_a_better_other(cmd);
	cmd = ft_b_setenv_tab("PWD", join, 1);
	ft_setenv(env, cmd);
	for_a_better_other(cmd);
}

void	ft_tild(char ***env, char *arg)
{
	ft_null(env, arg);
}

void	ft_other(char ***env, char *arg)
{
	char	*join;
	char	**cmd;
	char	*tmp;
	char	*tmp2;

	tmp = ft_getenv("PWD", (*env));
	tmp2 = ft_strjoin("/", arg);
	join = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	if (chdir(join) < 0)
	{
		free(join);
		if (arg[0] != '~')
			ft_error_chdir(arg);
		return ;
	}
	tmp = ft_getenv("PWD", (*env));
	cmd = ft_b_setenv_tab("OLDPWD", tmp, 1);
	ft_setenv(env, cmd);
	for_a_better_other(cmd);
	cmd = ft_b_setenv_tab("PWD", join, 1);
	ft_setenv(env, cmd);
	for_a_better_other(cmd);
}
