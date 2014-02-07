/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 17:46:36 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 16:33:11 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
			break ;
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
