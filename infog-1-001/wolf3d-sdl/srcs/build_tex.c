/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 14:51:27 by rgary             #+#    #+#             */
/*   Updated: 2014/01/10 13:44:34 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
/*#include "wolf3d.h"*/

char	**read_xpm_file_for_color(const char *file)
{
	int		i;
	int		j;
	int		k;
	char	**color;

	i = j = 0;
	k = 2;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	while (ft_strcmp(line, "/* columns rows colors chars-per-pixel */") != 0)
        get_next_line(fd, &line);
	get_next_line(fd, &line);
	while (ft_strcmp(line, "/* pixel */") != 0)
	{
		color = (char**)malloc(sizeof(char*) * k);
		while (i < 11)
			color
	}
}

"1 c #4040FC",

char	**read_xpm_file(const char *file)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**tex;

	i = j = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	while (ft_strcmp(line, "/* pixel */") != 0)
		get_next_line(fd, &line);
	get_next_line(fd, &line);
	tex = (char**)malloc(sizeof(char*) * 65);
	while (i < 65)
	{
		j = 0;
		tex = (char*)malloc(sizeof(char) * 65);
		while (j++, j < 65)
			tex[i][j - 1] = line[j];
		tex[i][j] = '\0';
		i++;
		get_next_line(fd, &line);
	}
	close(fd);
	return (tex);
}
