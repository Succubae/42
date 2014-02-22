/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 11:10:30 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 13:45:56 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	*matrix_sub_by_val(t_vect *m1, t_type f)
{
	t_vect	*m2;

	m2 = (t_vect*)malloc(sizeof(t_vect));
	m2->x = m1->x - f;
	m2->y = m1->y - f;
	m2->z = m1->z - f;
	m2->l = find_magnitude(m2->x, m2->y, m2->z);
	return (m2);
}

t_all	*build_all(t_mlx *mlx, t_cam *cam, t_obj *lst)
{
	t_all	*all;

	all = (t_all*)malloc(sizeof(t_all));
	all->mlx = mlx;
	all->lst = lst;
	all->cam = cam;
	if (cam == NULL)
	{
		write(2, "Parse Error : No Camera\n", 25);
		exit(-1);
	}
	return (all);
}

int		expose_hook(t_all *all)
{
	calc_rays(all->cam, all->lst);
	return (0);
}
