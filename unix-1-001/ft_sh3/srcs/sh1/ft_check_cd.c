/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 10:57:53 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 17:20:23 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

static char	*for_sad(char **arg, char *tmp, char **env, int j)
{
	char	*join;

	join = ft_getenv("PWD", env);
	if (join[ft_strlen(join)] != '/')
	{
		tmp = ft_strjoin(join, "/");
		free(join);
		join = ft_strjoin(tmp, arg[j + 1]);
	}
	else
	{
		free(join);
		join = ft_getenv("PWD", env);
		tmp = ft_strjoin(join, "/");
		free(join);
		join = ft_strjoin(tmp, arg[j + 1]);
	}
	return (join);
}

int			ft_check_cd(char **env, char **arg)
{
	int			i;
	int			j;
	char		*join;
	char		*tmp;

	i = j = 0;
	if (arg[j + 1] == NULL)
		return (1);
	while (arg[j + 1][0] == '-')
		j++;
	join = ft_getenv("PWD", env);
	if (join == NULL)
	{
		FP2("PWD unset. Aborting.\n", 2);
		return (0);
	}
	free(join);
	join = for_sad(arg, tmp, env, j);
	free(tmp);
	return (1);
}

void		ft_go_oldpwd(char ***env)
{
	char	*tmp;
	char	*tmp2;
	char	**cmd;

	tmp = ft_getenv("OLDPWD", (*env));
	if (tmp == NULL)
		return ((void)FP2("OLDPWD unset. Aborting.\n", 2));
	if (chdir(tmp) < 0)
	{
		ft_error_chdir(tmp);
		return ;
	}
	FP("%s\n", tmp);
	tmp2 = ft_getenv("PWD", (*env));
	if (tmp2 == NULL)
	{
		FP2("PWD unset. Aborting.\n", 2);
		return ;
	}
	cmd = ft_b_setenv_tab("OLDPWD", tmp2, 1);
	ft_setenv(env, cmd);
	for_a_better_other(cmd);
	cmd = ft_b_setenv_tab("PWD", tmp, 1);
	ft_setenv(env, cmd);
	for_a_better_other(cmd);
}
