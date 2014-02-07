/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_info_stats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 10:48:10 by rgary             #+#    #+#             */
/*   Updated: 2013/12/14 18:47:10 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include "ft_ls.h"

char		ft_find_type(int st_mode)
{
	char	c;

	if (S_ISREG(st_mode))
		c = '-';
	else if (S_ISDIR(st_mode))
		c = 'd';
	else if (S_ISBLK(st_mode))
		c = 'b';
	else if (S_ISCHR(st_mode))
		c = 'c';
	else if (S_ISFIFO(st_mode))
		c = 'p';
	else if (S_ISLNK(st_mode))
		c = 'l';
	else if (S_ISSOCK(st_mode))
		c = 's';
	else
		c = '-';
	return (c);
}

char		*ft_find_right(t_stat *stats, char *str, char *join)
{
	char	buf[100];

	str = ft_strnew(12);
	str[0] = ft_find_type(stats->st_mode);
	str[1] = (stats->st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (stats->st_mode & S_IWUSR) ? 'w' : '-';
	if (stats->st_mode & S_IXUSR)
		str[3] = (S_UID(stats->st_mode) ? 's' : 'x');
	else
		str[3] = (S_UID(stats->st_mode) ? 'S' : '-');
	str[4] = (stats->st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (stats->st_mode & S_IWGRP) ? 'w' : '-';
	if (stats->st_mode & S_IXGRP)
		str[6] = (S_GID(stats->st_mode) ? 's' : 'x');
	else
		str[6] = (S_GID(stats->st_mode) ? 'S' : '-');
	str[7] = (stats->st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (stats->st_mode & S_IWOTH) ? 'w' : '-';
	if (stats->st_mode & S_IXOTH)
		str[9] = (S_VTX(stats->st_mode) ? 't' : 'x');
	else
		str[9] = (S_VTX(stats->st_mode) ? 'T' : '-');
	str[10] = (listxattr(join, buf, 100, XATTR_NOFOLLOW) <= 0 ? ' ' : '@');
	str[11] = '\0';
	return (str);
}

void		ft_fill_params_struct(char **argv, t_params *p, int i, int j)
{
	if (argv[i][j] == 'l')
		p->l = 1;
	if (argv[i][j] == 'a')
		p->a = 1;
	if (argv[i][j] == 'r')
		p->r = 1;
	if (argv[i][j] == 'R')
		p->R = 1;
	if (argv[i][j] == 't')
		p->t = 1;
}
