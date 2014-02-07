/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:47:22 by rgary             #+#    #+#             */
/*   Updated: 2014/01/16 10:28:14 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

void	ft_chopchop(char ***env, char *arg)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	i = j = 0;
	while (arg[i] != '=')
		i++;
	if ((s1 = (char*)malloc(sizeof(char) * i)) == NULL)
		ft_error_malloc("allocate enougth space for s1 in ft_chopchop");
	ft_bzero(s1, i);
	while (arg[i + j + 1] != '\0')
		j++;
	if ((s2 = (char*)malloc(sizeof(char) * j)) == NULL)
		ft_error_malloc("allocate enougth space for s2 in ft_chopchop");
	ft_bzero(s2, j);
	i = j = -1;
	while (i++, arg[i] != '=')
		s1[i] = arg[i];
	while (j++, arg[i + j + 1] != '\0')
		s2[j] = arg[i + j + 1];
	ft_setenv(env, ft_b_setenv_tab(s1, s2, 1));
}

void	ft_chopchop_env(char **env, char ***envcpy)
{
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (((*envcpy) = (char**)malloc(sizeof(char*) * 2)) == NULL)
		ft_error_malloc("allocate enougth space in ft_chopchop_env");
	(*envcpy)[0] = ft_strdup(env[i]);
	(*envcpy)[1] = NULL;
}

void	ft_execute_or_print_env(char **env, char **arg, int i, int j)
{
	if (arg[i] != NULL)
	{
		ft_execute_cmd_from_env(&env, arg, i);
		j++;
	}
	if (j == 1)
		ft_print_env(env);
}

void	ft_execute_cmd_from_env(char ***env, char **arg, int j)
{
	int		i;
	char	**path;

	i = 0;
	while ((*env)[i] != NULL)
	{
		if (ft_strncmp((*env)[i], "PATH", 4) == 0)
			path = ft_strsplit((*env)[i] + 5, ':');
		i++;
	}
	if (path)
	{
		mod_path(path);
		ft_not_builtins(path, &arg[j], env);
	}
}

void	ft_print_env(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
}
