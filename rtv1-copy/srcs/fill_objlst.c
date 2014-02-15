/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:52:07 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 14:30:06 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	*sphere_data(t_obj *lst, char **tab, char *buf)
{
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] == NULL
		|| tab[4] == NULL || tab[5] == NULL || tab[6] == NULL)
		file_error("Parser error in scene file near : ", buf);
	lst->posx = ft_atof(tab[0]);
	lst->posy = ft_atof(tab[1]);
	lst->posz = ft_atof(tab[2]);
	lst->radius = ft_atof(tab[3]);
	lst->r = ft_atoi(tab[4]);
	lst->g = ft_atoi(tab[5]);
	lst->b = ft_atoi(tab[6]);
	return (lst);
}

t_obj	*plane_data(t_obj *lst, char **tab, char *buf)
{
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] == NULL
		|| tab[4] == NULL || tab[5] == NULL || tab[6] == NULL || tab[7] == NULL
		|| tab[8] == NULL)
		file_error("Parser error in scene file near : ", buf);
	lst->pos = new_vect(ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2]));
	lst->nor = new_vect(ft_atof(tab[3]), ft_atof(tab[4]), ft_atof(tab[5]));
	norm_vect(lst->nor);
	lst->r = ft_atoi(tab[6]);
	lst->g = ft_atoi(tab[7]);
	lst->b = ft_atoi(tab[8]);
	return (lst);

}
t_obj	*cone_data(t_obj *lst, char **tab, char *buf)
{
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] == NULL
		|| tab[4] == NULL || tab[5] == NULL || tab[6] == NULL || tab[7] == NULL)
		file_error("Parser error in scene file near : ", buf);
	lst->posx = ft_atof(tab[0]);
	lst->posy = ft_atof(tab[1]);
	lst->posz = ft_atof(tab[2]);
	lst->radius = ft_atof(tab[3]);
	lst->height = ft_atof(tab[4]);
	lst->r = ft_atoi(tab[5]);
	lst->g = ft_atoi(tab[6]);
	lst->b = ft_atoi(tab[7]);
	return (lst);
}

t_obj	*cylinder_data(t_obj *lst, char **tab, char *buf)
{
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] == NULL
		|| tab[4] == NULL || tab[5] == NULL || tab[6] == NULL || tab[7] == NULL)
		file_error("Parser error in scene file near : ", buf);
	lst->posx = ft_atof(tab[0]);
	lst->posy = ft_atof(tab[1]);
	lst->posz = ft_atof(tab[2]);
	lst->radius = ft_atof(tab[3]);
	lst->height = ft_atof(tab[4]);
	lst->r = ft_atoi(tab[5]);
	lst->g = ft_atoi(tab[6]);
	lst->b = ft_atoi(tab[7]);
	return (lst);
}

t_obj	*cube_data(t_obj *lst, char **tab, char *buf)
{
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] == NULL
		|| tab[4] == NULL || tab[5] == NULL)
		file_error("Parser error in scene file near : ", buf);
	lst->posx = ft_atof(tab[0]);
	lst->posy = ft_atof(tab[1]);
	lst->posz = ft_atof(tab[2]);
	lst->height = ft_atof(tab[3]);
	lst->width = ft_atof(tab[4]);
	lst->depth = ft_atof(tab[5]);
	return (lst);
}
