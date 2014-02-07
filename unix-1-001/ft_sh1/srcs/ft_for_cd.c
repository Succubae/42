/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 13:31:42 by rgary             #+#    #+#             */
/*   Updated: 2013/12/24 11:08:52 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_sh1.h"

void	ft_null(char ***env, char *arg)
{
	char	*join;

	(void)arg;
	if (ft_getenv("HOME", (*env)) == NULL)
		return ;
	if (chdir(ft_getenv("HOME", (*env))) < 0)
	{
		ft_error_chdir("HOME");
		return ;
	}
	join = ft_getenv("HOME", (*env));
	ft_setenv(env, ft_b_setenv_tab("PWD", join, 1));
}

void	ft_slash(char ***env, char *arg)
{
	char	*join;

	if (chdir(arg) < 0)
	{
		ft_error_chdir(arg);
		return ;
	}
	join = ft_cleanup_pwd(arg);
	ft_setenv(env, ft_b_setenv_tab("OLDPWD", ft_getenv("PWD", (*env)), 1));
	ft_setenv(env, ft_b_setenv_tab("PWD", join, 1));
}

void	ft_dot(char ***env, char *arg)
{
	char	*join;

	join = ft_strjoin(ft_getenv("PWD", (*env)), ft_strjoin("/", arg));
	if (chdir(join) < 0)
	{
		ft_error_chdir(join);
		return ;
	}
	join = ft_cleanup_pwd(join);
	ft_setenv(env, ft_b_setenv_tab("OLDPWD", ft_getenv("PWD", (*env)), 1));
	ft_setenv(env, ft_b_setenv_tab("PWD", join, 1));
}

void	ft_tild(char ***env, char *arg)
{
	char	*sub;
	char	*join;

	sub = ft_strsub(arg, 1, 500);
	join = ft_strjoin(ft_getenv("HOME", (*env)), ft_strjoin("/", sub));
	if (chdir(join) < 0)
	{
		ft_error_chdir(join);
		return ;
	}
	ft_setenv(env, ft_b_setenv_tab("OLDPWD", ft_getenv("PWD", (*env)), 1));
	ft_setenv(env, ft_b_setenv_tab("PWD", join, 1));
}

void	ft_other(char ***env, char *arg)
{
	char	*join;

	join = ft_strjoin(ft_getenv("PWD", (*env)), ft_strjoin("/", arg));
	if (chdir(join) < 0)
	{
		ft_error_chdir(arg);
		return ;
	}
	ft_setenv(env, ft_b_setenv_tab("OLDPWD", ft_getenv("PWD", (*env)), 1));
	ft_setenv(env, ft_b_setenv_tab("PWD", join, 1));
}
