/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:49:42 by rgary             #+#    #+#             */
/*   Updated: 2013/12/18 10:54:16 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

void	ft_draw_horizontaly(t_all *all)
{
	t_pts	*pts;
	int		i;
	int		j;

	pts = (t_pts*)malloc(sizeof(t_pts));
	i = 0;
	j = 0;
	while (i < all->rot->sizex)
	{
		j = 0;
		while (j < all->rot->sizey - 1)
		{
			pts->x1 = pts->x2 = i;
			pts->y1 = j;
			pts->y2 = j + 1;
			ft_place_points(pts, all);
			j++;
		}
		i++;
	}
	free(pts);
}

void	ft_draw_verticaly(t_all *all)
{
	t_pts	*pts;
	int		i;
	int		j;

	pts = (t_pts*)malloc(sizeof(t_pts));
	i = 0;
	j = 0;
	while (j < all->rot->sizey)
	{
		i = 0;
		while (i < all->rot->sizex - 1)
		{
			pts->y1 = pts->y2 = j;
			pts->x1 = i;
			pts->x2 = i + 1;
			ft_place_points(pts, all);
			i++;
		}
		j++;
	}
	free(pts);
}

void	ft_build_perspective(t_pts *pts, t_all *all)
{
	float   t;
	float   x;
	float   y;
	float   a;

	pts->mx1 = ((pts->y1 * all->rotx) + 30 * pts->x1) + (WIND_X / 4);
	pts->my1 = ((pts->x1 * all->roty) + 30 * pts->y1) + (WIND_X / 4);
	pts->mx2 = ((pts->y2 * all->rotx) + 30 * pts->x2) + (WIND_X / 4);
	pts->my2 = ((pts->x2 * all->roty) + 30 * pts->y2) + (WIND_X / 4);
	t = all->incl;
	x = pts->mx1 - (WIND_X / 2);
	y = pts->my1 - (all->tab[pts->y1][pts->x1] * all->height) - (WIND_Y / 2);
	a = WIND_Y / (WIND_Y + y * ft_sinus(t));
	pts->mx1 = (a * x) + (WIND_X / 2);
	pts->my1 = (a * y * ft_cosinus(t) + (WIND_Y / 2));
	x = pts->mx2 - (WIND_X / 2);
	y = pts->my2 - (all->tab[pts->y2][pts->x2] * all->height) - (WIND_Y / 2);
	a = WIND_Y / (WIND_Y + y * ft_sinus(t));
	pts->mx2 = (a * x) + (WIND_X / 2);
	pts->my2 = (a * y * ft_cosinus(t) + (WIND_Y / 2));
}

void	ft_place_points(t_pts *pts, t_all *all)
{
	pts->mx1 = (((X1 - (RSX / 1.55)) * (WIND_X / ((RSX))) + (WIND_X)) / 1.55);
	pts->mx2 = (((X2 - (RSX / 1.55)) * (WIND_X / ((RSX))) + (WIND_X)) / 1.55);
	pts->my1 = (((Y1 - (RSY / 1.55)) * (WIND_Y / ((RSY))) + (WIND_Y)) / 1.55);
	pts->my2 = (((Y2 - (RSY / 1.55)) * (WIND_Y / ((RSY))) + (WIND_Y)) / 1.55);
	ft_build_perspective(pts, all);
	ft_new_draw_algo(pts, all->mlx);
}

void	ft_new_draw_algo(t_pts *pts, t_mlx *mlx)
{
	float	incl;
	int		i;
	int		px;
	int		py;

	i = 0;
	if ((ft_abs(pts->mx2 - pts->mx1) >= ft_abs(pts->my2 - pts->my1)
		 && pts->mx1 != pts->mx2) || pts->my1 == pts->my2)
	{
		incl = (float)(pts->my2 - pts->my1) / (float)(pts->mx2 - pts->mx1);
		while ((i += sgn(pts->mx2 - pts->mx1)) != (pts->mx2 - pts->mx1))
		{
			py = incl * i + pts->my1;
			mlx_pixel_put(mlx->mlx, mlx->win, (i + pts->mx1), py, 0xffffff);
		}
	}
	else
	{
		incl = (float)(pts->mx2 - pts->mx1) / (float)(pts->my2 - pts->my1);
		while ((i += sgn(pts->my2 - pts->my1)) != (pts->my2 - pts->my1))
		{
			px = incl * i + pts->mx1;
			mlx_pixel_put(mlx->mlx, mlx->win, px, (i + pts->my1), 0xffffff);
		}
	}
}
