/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 10:23:34 by rgary             #+#    #+#             */
/*   Updated: 2013/12/26 10:52:12 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ft_sh1.h"

int		ft_check_builtins(char ***env, char **arg)
{
	int		i;
	int		j;
	char	*lst[5] = {"cd", "setenv", "unsetenv", "env", "exit"};
	t_func	*tab[5] = {ft_cd, ft_setenv, ft_unsetenv, ft_env, ft_exit};

	i = j = 0;
	while (i < 5)
	{
		if (ft_strcmp(arg[0], lst[i]) == 0)
		{
			tab[i](env, arg);
			j++;
		}
		i++;
	}
	return (j);
}

void	mod_path(char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i] != NULL)
	{
		tmp = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i] = tmp;
		i++;
	}
}

void	do_shit(char **env, char **path)
{
	char	**arg;
	char	*in;
	int		*pid;
	int		ret;
	int		i;

	pid = NULL;
	while (FP("%s > ", GE("PWD")), (ret = get_next_line(0, &in)) > 0)
	{
		i = 0;
		arg = ft_strsplit(in, ' ');
		if (arg[0] != NULL)
		{
			i = ft_check_builtins(&env, arg);
			if (!i)
				ft_not_builtins(path, arg, &env);
		}
	}
	exit(1);
}

int		main(void)
{
	char		**env;
	char		**path;
	extern char	**environ;
	int			i;

	path = NULL;
	ft_signal_init();
	ft_copy_environ(environ, &env);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			path = ft_strsplit(env[i] + 5, ':');
		i++;
	}
	if (path)
	{
		mod_path(path);
		do_shit(env, path);
	}
	else
		FP("Error in environment declaration, can't find PATH\n");
	return (0);
}
