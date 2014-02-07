/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dirlist_content_list.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 13:56:06 by rgary             #+#    #+#             */
/*   Updated: 2013/12/09 09:31:00 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "ft_ls.h"

t_list2		*ft_lst_push_back_dirlist(t_list2 *lnk, t_list2 *new)
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

t_list2		*ft_fill_dirstat(t_list2 *tmp, char *str)
{
	t_stat		stats;
	char		*date;

	if (lstat(str, &stats) == -1)
		perror(str);
	else
	{
		if ((date = ctime(&stats.st_mtime)) == NULL)
			tmp->time = ctime(0);
		else
		{
			tmp->timestamp = stats.st_mtime;
			date = ft_strsub(date, 4, 12);
			tmp->time = date;
		}
	}
	return (tmp);
}

t_list2		*ft_build_dirlist(char *str, t_list2 *lnk)
{
	t_list2		*new;
	t_list2		*tmp;

	tmp = (t_list2*)malloc(sizeof(t_list2));
	tmp = ft_lstnew_dir(str, tmp);
	tmp = ft_fill_dirstat(tmp, str);
	new = ft_lst_push_back_dir(lnk, tmp);
	return (new);
}
