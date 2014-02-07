/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:40:50 by rgary             #+#    #+#             */
/*   Updated: 2013/12/06 16:41:49 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static	int	fill_buf(int const fd, char **line, char *buf)
{
	int		i;
	int		res;
	char	*tmp;

	while ((res = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (res == -1)
			return (-1);
		i = ft_strichr(buf, '\n');
		if (i == -1)
		{
			tmp = ft_strjoin(*line, buf);
			free(*line);
			*line = tmp;
		}
		else
		{
			tmp = ft_strnjoin(*line, buf, i);
			free(*line);
			*line = tmp;
			ft_strcpy(buf, buf + i + 1);
			return (1);
		}
	}
	return (res);
}

int			get_next_line(int const fd, char **line)
{
	static char		*buf;
	int				i;

	*line = ft_strnew(0);
	if (!(buf))
	{
		buf = (char*)malloc(sizeof(char) * BUF_SIZE + 1);
		buf[BUF_SIZE] = '\0';
	}
	else
	{
		i = ft_strichr(buf, '\n');
		if (i != -1)
		{
			*line = ft_strsub(buf, 0, i);
			ft_strcpy(buf, buf + i + 1);
			return (1);
		}
		else
			*line = ft_strdup(buf);
	}
	return (fill_buf(fd, line, buf));
}
