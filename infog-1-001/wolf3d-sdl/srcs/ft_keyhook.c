/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:51:33 by rgary             #+#    #+#             */
/*   Updated: 2014/01/11 16:49:34 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "wolf3d.h"

void	ft_rotate(t_all **all, float i)
{
	float	olddirx;
	float	oldplanex;

	olddirx = SPOS->dirx;
	SPOS->dirx = SPOS->dirx * cos(i) - SPOS->diry * sin(i);
	SPOS->diry = olddirx * sin(i) + SPOS->diry * cos(i);
	oldplanex = SPOS->planex;
	SPOS->planex = SPOS->planex * cos(i) - SPOS->planey * sin(i);
	SPOS->planey = oldplanex * sin(i) + SPOS->planey * cos(i);
}

void	other_event(const Uint8 *g_state, t_all **all)
{
	if (g_state[SDL_SCANCODE_UP])
	{
		if ((*all)->map[(int)(SPOS->posx + SPOS->dirx)][(int)SPOS->posy] == 0)
			SPOS->posx += SPOS->dirx * 0.3;
		if ((*all)->map[(int)SPOS->posx][(int)(SPOS->posy + SPOS->diry)] == 0)
			SPOS->posy += SPOS->diry * 0.3;
		ft_redraw((*all));
	}
	if (g_state[SDL_SCANCODE_DOWN])
	{
		if ((*all)->map[(int)(SPOS->posx - SPOS->dirx)][(int)SPOS->posy] == 0)
			SPOS->posx -= SPOS->dirx * 0.3;
		if ((*all)->map[(int)SPOS->posx][(int)(SPOS->posy - SPOS->diry)] == 0)
			SPOS->posy -= SPOS->diry * 0.3;
		ft_redraw((*all));
	}
	yet_another_event(g_state, all);
}

void	yet_another_event(const Uint8 *g_state, t_all **all)
{
	if (g_state[SDL_SCANCODE_RIGHT])
	{
		ft_rotate(all, 0.15);
		ft_redraw((*all));
	}
	if (g_state[SDL_SCANCODE_LEFT])
	{
		ft_rotate(all, -0.15);
		ft_redraw((*all));
	}
}

void	sdl_event(t_all **all)
{
	int				quit;
	SDL_Event		event;
	const Uint8		*g_state = SDL_GetKeyboardState(NULL);

	quit = 0;
	while (quit == 0)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = 1;
			SDL_PumpEvents();
			if (g_state[SDL_SCANCODE_ESCAPE])
				quit = 1;
			other_event(g_state, all);
		}
	}
}

void	ft_redraw(t_all *all)
{
	int			x;

	x = 0;
	SDL_SetRenderDrawColor(all->sdl->ren, 0, 0, 0, 255);
	SDL_RenderPresent(all->sdl->ren);
	SDL_RenderCopy(all->sdl->ren, all->sdl->tex, NULL, NULL);
	while (x < WIND_X)
	{
		POS->hit = 0;
		ft_find_ray_dir_and_dist(&all, x);
		ft_calc_step(&all);
		ft_find_wall(&all);
		ft_find_dist_wall(&all);
		POS->wallheight = ft_abs((int)(WIND_Y / POS->walldist));
		POS->drawstart = -POS->wallheight / 2 + WIND_Y / 2;
		if (POS->drawstart < 0)
			POS->drawstart = 0;
		POS->drawend = POS->wallheight / 2 + WIND_Y / 2;
		if (POS->drawend >= WIND_Y)
			POS->drawend = WIND_Y - 1;
		ft_draw_line(all, x);
		x += 1;
	}
	show_weapon(all);
	SDL_RenderPresent(all->sdl->ren);
}
