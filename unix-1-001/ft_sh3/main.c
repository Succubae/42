/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:06:30 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 13:03:04 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh3.h"

void		free_path(char **path)
{
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		free(path[i]);
		i++;
	}
}

static void	main_call(t_termdata *td, char **env, char **path)
{
	td = malloc_struct();
	td = change_term_info(td);
	mod_path(path);
	do_even_more_shit(env, path);
}

int			main(void)
{
	int			i;
	extern char **environ;
	char		**env;
	char		**path;
	t_termdata	*td;

	path = NULL;
	ft_signal_init();
	ft_copy_environ(environ, &env);
	i = -1;
	while (i++, env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			path = ft_strsplit(env[i] + 5, ':');
	}
	if (path)
		main_call(td, env, path);
	else
		ft_error_exit("Unable to find PATH in environment. Abort.");
	free_path(path);
	change_back_term_info(path);
	return (0);
}
