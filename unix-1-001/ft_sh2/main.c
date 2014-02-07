/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:06:30 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 16:40:08 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

int		main(void)
{
	int			i;
	extern char **environ;
	char		**env;
	char		**path;

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
	{
		mod_path(path);
		do_more_shit(env, path);
	}
	else
		ft_error_exit("Unable to find PATH in environment. Abort.");
	return (0);
}
