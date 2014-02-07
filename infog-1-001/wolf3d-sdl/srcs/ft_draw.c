/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 14:31:59 by rgary             #+#    #+#             */
/*   Updated: 2014/01/11 15:36:50 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "wolf3d.h"

static void	find_color_by_dist(t_all *all, int *r, int *g, int *b)
{
	if (all->pos->wallheight >= WIND_Y)
		*r = *b = *g = 255;
    else
    {
		*r = ((255 * all->pos->wallheight) / WIND_Y) * 3;
        *b = ((255 * all->pos->wallheight) / WIND_Y) * 3;
        *g = ((255 * all->pos->wallheight) / WIND_Y) * 3;
    }
    if (*r > 255)
		*r = 255;
    if (*b > 255)
		*b = 255;
    if (*g > 255)
		*g = 255;
}

static void	draw_ceiling(t_all *all, int x)
{
	int		i;
	float	c;

	i = 0;
	while (i < (WIND_Y / 3))
	{
		SDL_SetRenderDrawColor(all->sdl->ren, 126, 126, 126, 255);
		SDL_RenderDrawPoint(all->sdl->ren, x, i);
		i++;
	}
	c = 125;
	while (i < POS->drawstart)
	{
		SDL_SetRenderDrawColor(all->sdl->ren, (int)c, (int)c, (int)c, 255);
		SDL_RenderDrawPoint(all->sdl->ren, x, i);
		i++;
		c -= (126 / (((float)WIND_Y / 2) - ((float)WIND_Y / 3)));
	}
}

static void	draw_floor(t_all *all, int x)
{
	int    i;
	float   c;
	
	i = WIND_Y;
	while (i > ((WIND_Y / 3) * 2))
	{
		SDL_SetRenderDrawColor(all->sdl->ren, 226, 226, 226, 255);
		SDL_RenderDrawPoint(all->sdl->ren, x, i);
		i--;
	}
	c = 226;
	while (i > POS->drawend)
	{
		SDL_SetRenderDrawColor(all->sdl->ren, (int)c, (int)c, (int)c, 255);
		SDL_RenderDrawPoint(all->sdl->ren, x, i);
		i--;
		c -= (226 / (((float)WIND_Y / 2) - ((float)WIND_Y / 3)));
	}
}

void	ft_draw_line(t_all *all, int x)
{
	int		r;
	int		g;
	int		b;
	SDL_Rect    *rect;

	find_color_by_dist(all, &r, &g, &b);
	SDL_SetRenderDrawColor(all->sdl->ren, 0, 0, 0, 255);
	draw_ceiling(all, x);
	draw_floor(all, x);
	POS->texnbr = all->map[POS->mapx][POS->mapy] - 1;
	fill_rect(all, rect, calc_tex_x_coor(all), x);
}
