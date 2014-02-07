/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:10:36 by rgary             #+#    #+#             */
/*   Updated: 2014/01/11 17:11:01 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "wolf3d.h"

t_pos	*ft_build_pos_struct_2(t_pos *pos)
{
	pos->sidedisty = 0;
	pos->deltadistx = 0;
	pos->deltadisty = 0;
	pos->walldist = 0;
	pos->wallheight = 0;
	pos->drawstart = 0;
	pos->drawend = 0;
	pos->color = 0;
	return (pos);
}

t_pos	*ft_build_pos_struct(void)
{
	t_pos	*pos;

	pos = (t_pos*)malloc(sizeof(t_pos));
	pos->mapwidth = MWIDTH;
	pos->mapheight = MHEIGHT;
	pos->mapx = 0;
	pos->mapy = 0;
	pos->stepx = 0;
	pos->stepy = 0;
	pos->hit = 0;
	pos->side = 0;
	pos->posx = 7;
	pos->posy = 3;
	pos->dirx = 0.57;
	pos->diry = -0.63;
	pos->planex = 1;
	pos->planey = 0.66;
	pos->camerax = 0;
	pos->rayposx = 0;
	pos->rayposy = 0;
	pos->raydirx = 0;
	pos->raydiry = 0;
	pos->sidedistx = 0;
	pos = ft_build_pos_struct_2(pos);
	return (pos);
}

t_all	*ft_build_all_struct(t_sdl *sdl)
{
	t_all	*all;

	all = (t_all*)malloc(sizeof(t_all));
	all->sdl = sdl;
	all->pos = ft_build_pos_struct();
	all->map = ft_get_data();
	return (all);
}

int		main(void)
{
	t_all	*all;
	t_sdl	*sdl;

	sdl = (t_sdl*)malloc(sizeof(t_sdl));
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		error("INIT ERROR\n");
	if ((sdl->win = SCW("Wolf3D", 20, 20, WIND_X, WIND_Y, SWS)) == NULL)
		error("WINDOW ERROR\n");
	if ((sdl->ren = SCR(sdl->win, -1, SDL_RENDERER_SOFTWARE)) == NULL)
		error("RENDERER ERROR\n");
	create_tex_tab(&sdl);
	SDL_SetRenderDrawColor(sdl->ren, 255, 0, 0, 255);
	all = ft_build_all_struct(sdl);
	ft_redraw(all);
	sdl_event(&all);
	SDL_DestroyRenderer(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	SDL_Quit();
	return (0);
}
