/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:40:50 by rgary             #+#    #+#             */
/*   Updated: 2014/01/28 09:50:25 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int		read_file(int const fd, char **line, char *buf)
{
	int		n;
	int		ret;
	char	*tmp;

	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ret == -1)
			return (-1);
		n = ft_strichr(buf, '\n');
		if (n == -1)
		{
			tmp = ft_strnjoin(*line, buf, ret);
			free(*line);
			*line = tmp;
		}
		else
		{
			*line = ft_strnjoin(*line, buf, n);
			ft_strcpy(buf, buf + n + 1);
			return (1);
		}
	}
	ft_bzero(buf, BUF_SIZE);
	return (**line != '\0');
}

static t_buf	*new_t_buf(const int fd)
{
	t_buf	*buf;

	buf = (t_buf*)malloc(sizeof(t_buf));
	buf->buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	(buf->buf)[0] = '\0';
	(buf->buf)[BUF_SIZE] = '\0';
	buf->fd = fd;
	buf->next = NULL;
	return (buf);
}

static char		*choose_buf(int const fd, t_buf **buflst)
{
	t_buf	*tmp;

	if (*buflst)
	{
		tmp = *buflst;
		while (tmp->next)
		{
			if (tmp->fd == fd)
				return (tmp->buf);
			else
				tmp = tmp->next;
		}
		if (tmp->fd == fd)
			return (tmp->buf);
		else
			tmp->next = new_t_buf(fd);
		return (tmp->next->buf);
	}
	else
		*buflst = new_t_buf(fd);
	return ((*buflst)->buf);
}

int				get_next_line(int const fd, char **line)
{
	static t_buf	**buflst = NULL;
	int				n;
	char			*buf;

	if (BUF_SIZE < 1 || !(*line = ft_strnew(0)))
		return (-1);
	if (!buflst)
	{
		buflst = (t_buf**)malloc(sizeof(t_buf*));
		*buflst = NULL;
	}
	buf = choose_buf(fd, buflst);
	n = ft_strichr(buf, '\n');
	if (n != -1)
	{
		*line = ft_strsub(buf, 0, n);
		ft_strcpy(buf, buf + n + 1);
		return (1);
	}
	else if (buf[0])
		*line = ft_strdup(buf);
	return (read_file(fd, line, buf));
}
