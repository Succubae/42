/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 14:04:36 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 16:55:22 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "rtv1.h"

int		find_cylinder_limit(t_type *dist, t_type val[3], t_type det, t_obj *lst)
{
	t_type	t1;
	t_type	t2;
	t_type	z1;
	t_type	z2;
	t_cam	*cam;

	cam = store_cam(NULL);
	t1 = (-val[1] + sqrt(det)) / (2 * val[0]);
	t2 = (-val[1] - sqrt(det)) / (2 * val[0]);
	z1 = (cam->pos->z - lst->posz) + (t1 * cam->dirray->z);
	z2 = (cam->pos->z - lst->posz) + (t2 * cam->dirray->z);
	if ((z1 > lst->posz && z1 < (lst->posz + lst->height))
		&& (z2 > lst->posz && z2 < (lst->posz + lst->height)))
	{
		if (t1 > t2)
			return (*dist = t2 * -1, 1);
		else
			return (*dist = t1 * -1, 1);
	}
	else if (z1 > lst->posz && z1 < (lst->posz + lst->height))
		return (*dist = t1 * -1, 1);
	else if (z2 > lst->posz && z2 < (lst->posz + lst->height))
		return (*dist = t2 * -1, 1);
	else
		return (0);
}

t_type	look_for_cylinder(t_obj *lst, t_type *dist)
{
	t_type	val[3];
	t_type	det;
	t_cam	*cam;

	cam = store_cam(NULL);
	val[0] = power(cam->dirray->x) + power(cam->dirray->y);
	val[1] = (2.0 * (cam->pos->x - lst->posx) * cam->dirray->x) +
		(2.0 * (cam->pos->y - lst->posy) * cam->dirray->y);
	val[2] = power(cam->pos->x - lst->posx) + power(cam->pos->y - lst->posy)
		- power(lst->radius);
	det = (val[1] * val[1]) - (4 * val[0] * val[2]);
	return (find_cylinder_limit(dist, val, det, lst));
}

t_type	look_for_sphere(t_obj *lst, t_type *dist)
{
	t_type	a;
	t_type	b;
	t_type	c;
	t_type	det;
	t_cam	*cam;

	cam = store_cam(NULL);
	a = power(cam->dirray->x) + power(cam->dirray->y) + power(cam->dirray->z);
	b = (2.0 * (cam->pos->x - lst->posx) * cam->dirray->x)
		+ (2.0 * (cam->pos->y - lst->posy) * cam->dirray->y)
		+ (2.0 * (cam->pos->z - lst->posz) * cam->dirray->z);
	c = ((power(cam->pos->x - lst->posx)) + (power(cam->pos->y - lst->posy))
		 + (power(cam->pos->z - lst->posz)) - power(lst->radius));
	det = (b * b) - (4 * a * c);
	return (find_dist(dist, a, b, det));
}

t_type	look_for_plane(t_obj *lst, t_type *dist)
{
	t_type	d;
	t_vect	*tmp;
	t_cam	*cam;

	cam = store_cam(NULL);
	tmp = new_vect(cam->pos->x, cam->pos->y, cam->pos->z);
	d = ((lst->nor->x * (tmp->x - lst->pos->x))
		+ (lst->nor->y * (tmp->y - lst->pos->x))
		+ (lst->nor->z * (tmp->z - lst->pos->z))
		/ ((lst->nor->x * cam->dirray->x)
		+ (lst->nor->y * cam->dirray->y)
		+ (lst->nor->z * cam->dirray->z)));
	free(tmp);
	if (d > -0.00001)
	{
		*dist = d;
		return (1);
	}
	*dist = 0;
	return (0);
}

t_type	look_for_cone(t_obj *lst, t_type *dist)
{
	t_type	det;
	t_type	val[3];
	t_cam	*cam;
	t_type	size;

	cam = store_cam(NULL);
	size = lst->radius * 3.141592 / 180;
	val[0] = power(cam->dirray->x) + power(cam->dirray->y)
		- power(((lst->radius * cam->dirray->z) / lst->height));
	val[1] = (2.0 * cam->dirray->x * (cam->pos->x - lst->posx))
		+ (2.0 * cam->dirray->y * (cam->pos->y - lst->posy))
		- (2.0 * (lst->radius / lst->height) * (lst->height
												- cam->pos->z - lst->posz));
	val[2] = power(cam->pos->x - lst->posx) + power(cam->pos->y - lst->posy)
		- power((lst->radius / lst->height)
				* (lst->height - cam->pos->z - lst->posz));
	det = (power(val[1])) - (4 * val[0] * val[2]);
	return (find_dist(dist, val[0], val[1], det));
}
