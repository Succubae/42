/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dir_content_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:03:57 by rgary             #+#    #+#             */
/*   Updated: 2013/12/09 09:52:56 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "ft_ls.h"
#include "libft.h"

t_list2		*ft_lst_push_back_dir(t_list2 *lnk, t_list2 *new)
{
	t_list2		*save;

	save = lnk;
	if (lnk == NULL)
		return (new);
	while (lnk->next != NULL)
		lnk = lnk->next;
	lnk->next = new;
	new->prev = lnk;
	return (save);
}

t_list2		*ft_lstnew_dir(const char *name, t_list2 *tmp)
{
	if (name == 0)
		tmp->name = NULL;
	else
		tmp->name = ft_strdup(name);
	tmp->right = NULL;
	tmp->owner = NULL;
	tmp->group = NULL;
	tmp->time = NULL;
	tmp->link = NULL;
	tmp->size = 0;
	tmp->major = NULL;
	tmp->minor = NULL;
	tmp->blk = 0;
	tmp->timestamp = 0;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_list2		*ft_build_list(char *str, t_list2 *lnk, char *dir, t_params *p)
{
	t_list2		*new;
	t_list2		*tmp;

	tmp = (t_list2*)malloc(sizeof(t_list2));
	tmp = ft_lstnew_dir(str, tmp);
	tmp = ft_fill_stats(tmp, dir, p);
	new = ft_lst_push_back_dir(lnk, tmp);
	return (new);
}

t_list2		*ft_list_dir_content(t_list2 *lnk, char *dir, t_params* p)
{
	DIR			*current_dir;
	t_dirent	*dp;
	char		*str;

	current_dir = opendir(dir);
	if (current_dir)
	{
		ft_print_dir_name(dir, p);
		while ((dp = readdir(current_dir)) != NULL)
		{
			str = (char*)dp->d_name;
			lnk = ft_build_list(str, lnk, dir, p);
		}
		closedir(current_dir);
		free(dp);
	}
	else
		ft_print_error_permission(dir);
	return (lnk);
}
