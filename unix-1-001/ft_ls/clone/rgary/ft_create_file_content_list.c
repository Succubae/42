/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_file_content_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:03:57 by rgary             #+#    #+#             */
/*   Updated: 2013/12/09 09:33:56 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "ft_ls.h"
#include "libft.h"

t_list2		*ft_build_list_file(char *str, t_list2 *lnk, char *dir, t_params* p)
{
	t_list2		*new;
	t_list2		*tmp;

	tmp = (t_list2*)malloc(sizeof(t_list2));
	tmp = ft_lstnew_dir(str, tmp);
	tmp = ft_fill_stats_file(tmp, dir, p);
	new = ft_lst_push_back_dir(lnk, tmp);
	return (new);
}

void		ft_change_link_name(char *join, t_stat *stats, t_list2 *lnk)
{
	int			r;
	char		*linkname;

	linkname = (char*)malloc(sizeof(char) * (stats->st_size + 1));
	if ((r = readlink(join, linkname, stats->st_size + 1)) != -1)
		lnk->name = ft_strjoin(ft_strjoin(join, " -> "), linkname);
	if (ft_strichr(lnk->name, '/') != -1)
	{
		lnk->name = ft_strrchr(lnk->name, '/');
		lnk->name = ft_strsub(lnk->name, 1, 250);
	}

}

t_list2		*ft_fill_stats_file(t_list2 *lnk, char *dir, t_params* p)
{
	t_stat			stats;
	t_passwd		*passwd;
	t_group			*group;

	if (lstat(dir, &stats) == -1)
	{
		perror(dir);
		return (lnk);
	}
	else
	{
		ft_fill_r_l_t(lnk, &stats, dir, p);
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
