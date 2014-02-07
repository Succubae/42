/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 17:17:20 by rgary             #+#    #+#             */
/*   Updated: 2014/01/14 10:10:14 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "ft_sh1.h"

int		ft_compare_cd_operation(char *arg, char **lib_cd, char ***env, int j)
{
	int		k;
	t_cd	*cd[4] = {ft_slash, ft_dot, ft_tild, ft_other};

	k = 1;
	if (arg == NULL)
	{
		ft_null(env, arg);
		k--;
	}
	else
	{
		if (ft_strncmp(arg, lib_cd[j], 1) == 0)
		{
			cd[j](env, arg);
			k--;
		}
	}
	return (k);
}

void	ft_not_builtins(char **path, char **arg, char ***env)
{
	int		status;
	int		sig;
	int		i;

	sig = 0;
	if ((i = fork()) > 0)
		waitpid(-1, &status, WNOHANG & WUNTRACED);
	else if (i == 0)
		ft_execute(path, arg, env);
}

void	ft_execute(char **path, char **arg, char ***env)
{
	int		i;
	int		retf;
	int		retx;
	int		retexec;
	char	*join;

	i = 0;
	while (path[i] != NULL)
	{
		join = ft_strjoin(path[i], arg[0]);
		if ((retf = access(join, F_OK)) == 0)
		{
			if ((retx = access(join, X_OK)) == 0)
				retexec = execve(ft_strjoin(path[i], arg[0]), arg, (*env));
		}
		i++;
	}
	if (retf == -1)
		FP("Minishell: Command not found \"%s\"\n", arg[0]);
	else if (retx == -1)
		FP("Minishell: Permission denied to execute \"%s\"", arg[0]);
	else if (retexec == -1)
		FP("Minishell: Execve Error: Unable to execute \"%s\"\n", arg[0]);
	exit(1);
}

void	ft_copy_environ(char **environ, char ***env)
{
	int		i;
	int		j;

	i = j = 0;
	while (environ[i] != NULL)
		i++;
	if (!((*env) = (char**)malloc(sizeof(char*) * i + 1)))
		ft_error_malloc(AM);
	i = 0;
	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '\0')
			j++;
		if (!((*env)[i] = (char*)malloc(sizeof(char) * j)))
			ft_error_malloc(AM);
		j = -1;
		while (environ[i][++j] != '\0')
			(*env)[i][j] = environ[i][j];
		(*env)[i][j] = '\0';
		i++;
	}
	(*env)[i] = NULL;
}
