/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:53:46 by rgary             #+#    #+#             */
/*   Updated: 2013/12/09 10:48:35 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include "ft_ls.h"

t_stat		*ft_create_stat_struct(void)
{
	t_stat		*stats;

	stats = (t_stat*)malloc(sizeof(t_stat));
	stats->st_dev = 0;
	stats->st_ino = 0;
	stats->st_mode = 0;
	stats->st_nlink = 0;
	stats->st_uid = 0;
	stats->st_gid = 0;
	stats->st_rdev = 0;
	stats->st_size = 0;
	stats->st_blocks = 0;
	stats->st_blksize = 0;
	stats->st_flags = 0;
	stats->st_gen = 0;
	return (stats);
}

void	ft_find_time(t_list2 *lnk, t_stat *stats, char *date)
{
	char		*save;
	char		*save2;

	lnk->timestamp = stats->st_mtime;
	if ((lnk->timestamp - time(NULL) > 1)
		|| (lnk->timestamp - time(NULL) < -15811200))
	{
		save = ft_strsub(date, 4, 7);
		save2 = ft_strjoin(" ", ft_strsub(date, 20, 4));
		date = ft_strjoin(save, save2);
		lnk->time = date;
	}
	else
	{
		lnk->timestamp = *(&stats->st_mtime);
		date = ft_strsub(date, 4, 12);
		lnk->time = date;
	}
}

void		ft_fill_r_l_t(t_list2 *lnk, t_stat *stats, char *join, t_params *p)
{
	char		*str;
	char		*date;

	str = NULL;
	str = ft_find_right(stats, str, join);
	lnk->link = ft_itoa(stats->st_nlink);
	lnk->right = ft_strdup(str);
	if ((date = ctime(&stats->st_mtime)) == NULL)
		lnk->time = ctime(0);
	else
	{
		ft_find_time(lnk, stats, date);
	}
	lnk->major = ft_itoa(major(stats->st_rdev));
	lnk->minor = ft_itoa(minor(stats->st_rdev));
	lnk->blk = stats->st_blocks;
	if (lnk->right[0] == 'l' && p->l == 1)
		ft_change_link_name(join, stats, lnk);
}

char		*ft_build_dirname(t_list2 *lnk, char *dir)
{
	char	*join;

	join = NULL;
	if (ft_strcmp(dir, "./") == 0)
		join = ft_strjoin(dir, lnk->name);
	else if (dir[ft_strlen(dir) - 1] != '/')
		join = ft_strjoin(ft_strjoin(dir, "/"), lnk->name);
	else
		join = ft_strjoin(dir, lnk->name);
	return (join);
}

t_list2		*ft_fill_stats(t_list2 *lnk, char *dir, t_params *p)
{
	char			*join;
	t_stat			stats;
	t_passwd		*passwd;
	t_group			*group;

	join = ft_build_dirname(lnk, dir);
	if (lstat(join, &stats) == -1)
		perror(join);
	else
	{
		ft_fill_r_l_t(lnk, &stats, join, p);
		if ((passwd = getpwuid(stats.st_uid)) == NULL)
			lnk->owner = ft_itoa(stats.st_uid);
		else
			lnk->owner = passwd->pw_name;
		if ((group = getgrgid(stats.st_gid)) == NULL)
			lnk->group = ft_itoa(stats.st_gid);
		else
			lnk->group = group->gr_name;
		lnk->size = ft_itoa(stats.st_size);
	}
	return (lnk);
}
