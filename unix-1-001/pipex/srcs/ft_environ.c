/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:18:32 by rgary             #+#    #+#             */
/*   Updated: 2013/12/30 17:51:35 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

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

char	**ft_getenv(char *s, char **env)
{
	int		i;
	int		j;
	char	**path;

	i = j = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(s, env[i], ft_strlen(s)) == 0)
		{
			j = ft_strichr(env[i], '=');
			path = ft_strsplit(env[i] + j + 1, ':');
			mod_path(path);
			return (path);
		}
		i++;
	}
	return (NULL);
}
