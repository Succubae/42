/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 13:23:09 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 12:14:10 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "rtv1.h"

t_obj	*lst_push_back(t_obj *lst, t_obj *bgn_lst)
{
	t_obj	*save;

	if (!bgn_lst)
		return (lst);
	else
	{
		save = bgn_lst;
		while (save->next != NULL)
			save = save->next;
		save->next = lst;
	}
	return (bgn_lst);
}

t_obj	*find_type(t_obj *lst, char *buf)
{
	char	*type[7] = {"camera", "sphere", "plane", "cone", "cylinder"
						, "cube", NULL};
	int		j;

	j = 0;
	while (j != 6)
	{
		if (ft_strcmp(buf + 1, type[j]) == 0)
		{
			lst->type = j;
			break ;
		}
		j++;
	}
	return (lst);
}

t_obj	*build_lnk(char *buf)
{
	t_obj	*lst;

	lst = (t_obj*)malloc(sizeof(t_obj));
	lst = find_type(lst, buf);
	lst->next = NULL;
	return (lst);
}

t_obj	*fill_data(char *buf, t_obj *lst)
{
	char	**tab;
	ft_data	*f[7] = {camera_data, sphere_data, plane_data, cone_data
					, cylinder_data, cube_data, NULL};

	if (lst == NULL)
		return (NULL);
	tab = ft_strsplit(buf, ';');
	lst = f[lst->type](lst, tab, buf);
	return (lst);
}

t_obj	*get_obj_from_file(char *file)
{
	int		fd;
	char	*buf;
	t_obj	*lst;
	t_obj	*bgn_lst;

	lst = NULL;
	bgn_lst = NULL;
	if ((fd = check_file(file)) == -1)
		file_error("Can't open file : ", file);
	while (get_next_line(fd, &buf) > 0)
	{
		if (buf[0] == '/' || buf[0] == '*')
			;
		else if (buf[0] == '&')
			lst = build_lnk(buf);
		else if (buf[0] == '-' || (buf[0] >= '0' && buf[0] <= '9'))
		{
			lst = fill_data(buf, lst);
			bgn_lst = lst_push_back(lst, bgn_lst);
		}
		free(buf);
		buf = NULL;
	}
	return (bgn_lst);
}
