/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 13:42:18 by rgary             #+#    #+#             */
/*   Updated: 2014/01/11 16:49:05 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "wolf3d.h"

float		ft_abs_float(float x)
{
	float i;

	i = (x < 0 ? x *= -1 : x);
	return (i);
}

void		ft_find_ray_dir_and_dist(t_all **all, int x)
{
	float	i;
	float	j;

	SPOS->camerax = 2 * x / (float)WIND_X - 1;
	SPOS->rayposx = SPOS->posx;
	SPOS->rayposy = SPOS->posy;
	SPOS->raydirx = SPOS->dirx + SPOS->planex * SPOS->camerax;
	SPOS->raydiry = SPOS->diry + SPOS->planey * SPOS->camerax;
	SPOS->mapx = (int)SPOS->rayposx;
	SPOS->mapy = (int)SPOS->rayposy;
	i = SPOS->raydiry * SPOS->raydiry;
	j = SPOS->raydirx * SPOS->raydirx;
	SPOS->deltadistx = sqrt(1 + (i) / (j));
	SPOS->deltadisty = sqrt(1 + (j) / (i));
}

void		ft_calc_step(t_all **all)
{
	if (SPOS->raydirx < 0)
	{
		SPOS->stepx = -1;
		SPOS->sidedistx = (SPOS->rayposx - SPOS->mapx) * SPOS->deltadistx;
	}
	else
	{
		SPOS->stepx = 1;
		SPOS->sidedistx = (SPOS->mapx + 1.0 - SPOS->rayposx) * SPOS->deltadistx;
	}
	if (SPOS->raydiry < 0)
	{
		SPOS->stepy = -1;
		SPOS->sidedisty = (SPOS->rayposy - SPOS->mapy) * SPOS->deltadisty;
	}
	else
	{
		SPOS->stepy = 1;
		SPOS->sidedisty = (SPOS->mapy + 1.0 - SPOS->rayposy) * SPOS->deltadisty;
	}
}

void		ft_find_wall(t_all **all)
{
	while (SPOS->hit == 0)
	{
		if (SPOS->sidedistx < SPOS->sidedisty)
		{
			SPOS->sidedistx += SPOS->deltadistx;
			SPOS->mapx += SPOS->stepx;
			SPOS->side = 0;
			if (SPOS->raydirx > 0)
				SPOS->nsew = 0;
			else
				SPOS->nsew = 1;
		}
		else
		{
			SPOS->sidedisty += SPOS->deltadisty;
			SPOS->mapy += SPOS->stepy;
			SPOS->side = 1;
			if (SPOS->raydiry > 0)
				SPOS->nsew = 2;
			else
				SPOS->nsew = 3;
		}
		if ((*all)->map[SPOS->mapx][SPOS->mapy] > 0)
			SPOS->hit = 1;
	}
}

void		ft_find_dist_wall(t_all **all)
{
	float		i;
	float		j;
	float		k;
	float		l;

	i = SPOS->mapx - SPOS->rayposx;
	j = SPOS->mapy - SPOS->rayposy;
	k = SPOS->raydirx;
	l = SPOS->raydiry;
	if (SPOS->side == 0)
		SPOS->walldist = ft_abs_float((i + (1 - SPOS->stepx) / 2) / k);
	else
		SPOS->walldist = ft_abs_float((j + (1 - SPOS->stepy) / 2) / l);
}
