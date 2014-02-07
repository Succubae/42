/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursivity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 10:22:41 by rgary             #+#    #+#             */
/*   Updated: 2013/12/09 10:37:16 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include "ft_ls.h"

t_recurs	*ft_btree(t_dirent *dp, t_recurs *recurs, char *dir, t_params* p)
{
	char		*join;
	t_stat		*stats;

	recurs->content = ft_build_list(DN, recurs->content, dir, p);
	if ((dp->d_type == DT_DIR && ft_strcmp(DN, ".") != 0
		 && ft_strcmp(DN, "..") != 0) || dp->d_type == 0)
	{
		stats = ft_create_stat_struct();
		if (lstat(dir, stats) == -1)
			perror(dir);
		else
		{
			if (ft_find_type(stats->st_mode) == 'd' && ft_strcmp(DN, ".") != 0
				&& ft_strcmp(DN, "..") != 0)
			{
				join = ft_strjoin(ft_strjoin(dir, "/"), DN);
				recurs->dirlist = ft_build_dirlist(join, recurs->dirlist);
				free(join);
			}
		free(stats);
		}
	}
	return (recurs);
}

t_recurs	*ft_create_tree(t_recurs *recurs)
{
	recurs = (t_recurs*)malloc(sizeof(t_recurs));
	recurs->content = NULL;
	recurs->dirlist = NULL;
	return (recurs);
}

void		ft_print_error_permission(char *dir)
{
	dir = ft_strsub(dir, (ft_strirchr(dir, '/') + 1), ft_strlen(dir));
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putendl_fd(": Permission denied", 2);
}

void		ft_print_dir_name(char *dir, t_params *p)
{
	int		i;

	i = ft_strirchr(dir, '/');
	if (dir[i + 1] == '.' && p->a == 0)
		;
	else
	{
		if (p->round != 0)
		{
			ft_putendl("");
			ft_putstr(dir);
			ft_putendl(":");
		}
		p->round = 1;
	}
}

void		ft_create_recursivity(char *dir, t_params *p)
{
	DIR			*current_dir;
	t_dirent	*dp;
	t_recurs	*recurs;

	recurs = ft_create_tree(recurs);
	if ((current_dir = opendir(dir)) == NULL)
	{
		perror(dir);
		return ;
	}
	ft_print_dir_name(dir, p);
	while ((dp = readdir(current_dir)) != NULL)
		ft_btree(dp, recurs, dir, p);
	closedir(current_dir);
	free(dp);
	ft_print_list_recurs(recurs->content, p, dir);
	recurs->dirlist = ft_sort_list(recurs->dirlist, p);
	while (recurs->dirlist)
	{
		if (recurs->dirlist->name)
			ft_create_recursivity(recurs->dirlist->name, p);
		recurs->dirlist = recurs->dirlist->next;
	}
}
