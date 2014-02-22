/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 12:05:43 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 16:53:50 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "rtv1.h"

void	calc_rays(t_cam *cam, t_obj *lst)
{
	int		cnt[2] = {-1, -1};
	t_obj	*save;
	t_type	tmp;
	t_type	dist;

	tmp = 2000;
	while (++cnt[1] != SCREEN_HEIGHT)
	{
		cnt[0] = -1;
		while (tmp = 2000, ++cnt[0] != SCREEN_WIDTH)
		{
			save = lst;
			free(cam->dirray);
			cam->dirray = update_cam_dirray(cam, cnt[0], cnt[1]);
			while (save != NULL)
			{
				find_closest_obj(save, &dist, &tmp, cnt);
				save = save->next;
			}
		}
	}
}

void	find_closest_obj(t_obj *save, t_type *dist, t_type *tmp, int cnt[2])
{
	if (save->type == SPHERE)
	{
		if (look_for_sphere(save, dist) == 1 && *dist < *tmp)
		{
			*tmp = *dist;
			put_pixel_by_object(cnt, build_color(save->r, save->g, save->b));
		}
	}
	else if (save->type == PLANE)
	{
		if (look_for_plane(save, dist) == 1 && *dist < *tmp)
		{
			*tmp = *dist;
			put_pixel_by_object(cnt, build_color(save->r, save->g, save->b));
		}
	}
	else
		find_another_obj(save, dist, tmp, cnt);
}

void	find_another_obj(t_obj *save, t_type *dist, t_type *tmp, int cnt[2])
{
	if (save->type == CYLINDER)
	{
		if (look_for_cylinder(save, dist) == 1 && *dist < *tmp)
		{
			*tmp = *dist;
			put_pixel_by_object(cnt, build_color(save->r, save->g, save->b));
		}
	}
	else if (save->type == CONE)
	{
		if (look_for_cone(save, dist) == 1 && *dist < *tmp)
		{
			*tmp = *dist;
			put_pixel_by_object(cnt, build_color(save->r, save->g, save->b));
		}
	}
	else
		return ;
}
