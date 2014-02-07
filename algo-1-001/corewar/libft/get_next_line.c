/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:01:34 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/07 15:32:56 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

ssize_t	check_buff(char *);
void	smart_join(char **, char *);
char	*handle_previous(char *, char **, char *);
int		read_file(t_nextline **, char **, int);

int		get_next_line(int const fd, char **line)
{
	static t_nextline	*nline = 0;
	char				end;

	if (!line)
		return (-1);
	if (!nline)
	{
		nline = (t_nextline *) malloc(sizeof(t_nextline));
		nline->kill = 0;
		nline->prev = 0;
	}
	*line = ft_strdup("\0");
	nline->prev = handle_previous(nline->prev, line, &end);
	if (end)
		return (1);
	if (nline->kill)
	{
		nline->kill = 0;
		return (0);
	}
	return (read_file(&nline, line, fd));
}

int		read_file(t_nextline **nline, char **line, int fd)
{
	char		*tmp_buff;
	ssize_t		i;
	int			read_res;

	if ((tmp_buff = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
	while ((read_res = read(fd, tmp_buff, BUFF_SIZE)) >= 0)
	{
		i = check_buff(tmp_buff);
		if ((i == BUFF_SIZE) && (tmp_buff[i] != EOL))
			smart_join(line, tmp_buff);
		else if ((tmp_buff[i] == EOL) || (tmp_buff[i] == '\0'))
		{
			smart_join(line, ft_strsub(tmp_buff, 0, i));
			if (i < BUFF_SIZE)
			{
				(*nline)->kill = (i == read_res);
				i += 1;
				(*nline)->prev = ft_strsub(tmp_buff, i, (read_res - i));
				return (1);
			}
		}
		ft_bzero(tmp_buff, BUFF_SIZE + 1);
	}
	return (read_res);
}

char	*handle_previous(char *prev, char **line, char *end)
{
	ssize_t	i;
	ssize_t	prev_len;

	*end = 0;
	if (prev)
	{
		prev_len = (ssize_t) ft_strlen(prev);
		i = check_buff(prev);
		if (i == prev_len)
		{
			smart_join(line, prev);
			prev = NULL;
		}
		else
		{
			smart_join(line, ft_strsub(prev, 0, i));
			prev = ft_strsub(prev, (i + 1), (prev_len - i));
			*end = 1;
		}
	}
	return (prev);
}

void	smart_join(char **line, char *prev)
{
	char	*tmp;

	tmp = ft_strjoin(*line, prev);
	free(*line);
	*line = ft_strdup(tmp);
	free(tmp);
}

ssize_t	check_buff(char *tmp_buff)
{
	ssize_t	i;

	i = 0;
	if (tmp_buff)
	{
		while (tmp_buff[i] && (tmp_buff[i] != EOL))
			i++;
	}
	return (i);
}
