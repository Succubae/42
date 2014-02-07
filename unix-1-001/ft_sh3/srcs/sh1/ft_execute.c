/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 17:17:20 by rgary             #+#    #+#             */
/*   Updated: 2014/02/06 20:07:43 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	int		i;

	if ((i = fork()) > 0)
		waitpid(-1, &status, WNOHANG & WUNTRACED);
	else if (i == 0)
		ft_execute(path, arg, env);
}

int		check_for_absolute_path(char **arg, char ***env, int *retf, int *retx)
{
	int		retexec;

	retexec = 0;
	if (((*retf) = access(arg[0], F_OK)) == 0)
	{
		if (((*retx) = access(arg[0], X_OK)) == 0)
			retexec = execve(arg[0], arg, (*env));
	}
	return (retexec);
}

void	ft_execute(char **path, char **arg, char ***env)
{
	int		i;
	int		retf;
	int		retx;
	int		retexec;
	char	*join;

	i = 0;
	retexec = check_for_absolute_path(arg, env, &retf, &retx);
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
		ft_error_exit("Command doesn't exist");
	if (retx == -1)
		ft_error_exit("Permission denied");
	if (retexec == -1)
		ft_error_exit("Execve error: Unknown");
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
