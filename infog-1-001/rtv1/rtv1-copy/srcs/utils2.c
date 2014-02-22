/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 09:32:53 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 15:19:42 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <mlx.h>
#include <math.h>
#include "rtv1.h"

void	norm_vect(t_vect *v)
{
	if (v->l != 0)
	{
		v->x /= v->l;
		v->y /= v->l;
		v->z /= v->l;
	}
	v->l = 1;
}

int		check_file(char *file)
{
	int	fd;

	fd = -1;
	if (access(file, F_OK) == 0)
	{
		if (access(file, R_OK) == 0)
			fd = open(file, O_RDONLY);
		if (fd != -1)
			return (fd);
	}
	return (-1);
}

void	put_pixel_by_object(int cnt[2], int l)
{
	t_mlx	*mlx;

	mlx = store_mlx(NULL);
	mlx_pixel_put(mlx->mlx, mlx->win, cnt[0], cnt[1], l);
}

int		find_dist(t_type *dist, t_type a, t_type b, t_type det)
{
	if (det == 0)
	{
		*dist = (-b / (2 * a));
		return (1);
	}
	else if (det > 0)
	{
		if ((-b + sqrt(det)) / (2 * a) > (-b - sqrt(det)) / (2 * a))
			*dist = (-b + sqrt(det)) / (2 * a) * -1;
		else
			*dist = (-b - sqrt(det)) / (2 * a) * -1;
		return (1);
	}
	else
		return (0);
}

float	power(float x)
{
	x *= x;
	return (x);
}
