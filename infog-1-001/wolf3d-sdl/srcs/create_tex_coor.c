/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tex_coor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 13:48:18 by rgary             #+#    #+#             */
/*   Updated: 2014/01/11 16:48:39 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "wolf3d.h"

void	calc_tex_y_coor(t_all *all)
{
	int		i;
	int		j;
	int		texy;

	i = POS->drawstart;
	while (i < POS->drawend)
	{
		j = i * 256 - WIND_Y * 128 + POS->wallheight * 128;
		texy = ((j * TEXWIDTH) / POS->wallheight) / 256;
		i++;
	}
}

void	modify_color_by_dist(t_all *all)
{
	int		r;
	int		g;
	int		b;

	r = 255 - (all->pos->walldist * 8);
	g = 255 - (all->pos->walldist * 8);
	b = 255 - (all->pos->walldist * 8);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	SDL_SetTextureColorMod(all->sdl->tex, r, g, b);
}

void	fill_rect(t_all *all, SDL_Rect *rect, int texx, int x)
{
	SDL_Rect	*dst;

	rect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	dst = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	rect->x = texx;
	if ((POS->wallheight - WIND_Y) < 0)
		rect->y = 0;
	else
		rect->y = ((TEXWIDTH - ((WIND_Y * TEXWIDTH) / POS->wallheight)) / 2.0);
	rect->w = 1;
	if (rect->y == 0)
		rect->h = TEXWIDTH;
	else
		rect->h = TEXWIDTH - (rect->y * 2);
	dst->x = x;
	if (((WIND_Y / 2) - (POS->wallheight / 2)) < 0)
		dst->y = 0;
	else
		dst->y = (WIND_Y / 2) - (POS->wallheight / 2);
	dst->w = 1;
	if (dst->y == 0)
		dst->h = WIND_Y;
	else
		dst->h = all->pos->wallheight + 1;
	all->sdl->tex = SDL_CreateTextureFromSurface(all->sdl->ren, all->sdl->tab[POS->texnbr]);
	modify_color_by_dist(all);
	SDL_RenderCopy(all->sdl->ren, all->sdl->tex, rect, dst);
}

void	show_weapon(t_all *all)
{
	SDL_Rect		*dest;
	SDL_Texture		*tmp;

	dest = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	dest->x = (WIND_X / 2);
	dest->y = WIND_Y - 350 - 1;
	dest->w = 513;
	dest->h = 350;
	tmp = SDL_CreateTextureFromSurface(all->sdl->ren, all->sdl->tab[8]);
	SDL_RenderCopy(all->sdl->ren, tmp, NULL, dest);
}

void	create_tex_tab(t_sdl **sdl)
{
	(*sdl)->tab = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * 12);
	(*sdl)->tab[0] = SDL_LoadBMP("./tex/purplestone.bmp");
	(*sdl)->tab[1] = SDL_LoadBMP("./tex/mossy.bmp");
	(*sdl)->tab[2] = SDL_LoadBMP("./tex/redbrick.bmp");
	(*sdl)->tab[3] = SDL_LoadBMP("./tex/greystone.bmp");
	(*sdl)->tab[4] = SDL_LoadBMP("./tex/eagle.bmp");
	(*sdl)->tab[5] = SDL_LoadBMP("./tex/wood.bmp");
	(*sdl)->tab[6] = SDL_LoadBMP("./tex/bluestone.bmp");
	(*sdl)->tab[7] = SDL_LoadBMP("./tex/colorstone.bmp");
	(*sdl)->tab[8] = SDL_LoadBMP("./tex/AUG.bmp");
	(*sdl)->tab[9] = SDL_LoadBMP("./tex/barrel.bmp");
	(*sdl)->tab[10] = SDL_LoadBMP("./tex/greenlight.bmp");
	(*sdl)->tab[11] = SDL_LoadBMP("./tex/pillar.bmp");
	SDL_SetColorKey((*sdl)->tab[8], SDL_SRCCOLORKEY, SDL_MapRGB((*sdl)->tab[8]->format, 255, 255, 255));
}

int		calc_tex_x_coor(t_all *all)
{
	int		texx;
	float	wallx;

	POS->texnbr = all->map[POS->mapx][POS->mapy] - 1;
	if (POS->side == 1)
		wallx = POS->rayposx + ((POS->mapy - POS->rayposy + (1 - POS->stepy) / 2) / POS->raydiry) * POS->raydirx;
	else
		wallx = POS->rayposy + ((POS->mapx - POS->rayposx + (1 - POS->stepx) / 2) / POS->raydirx) * POS->raydiry;
	wallx -= (int)wallx;
	texx = (int)(wallx * (float)(TEXWIDTH));
	if (POS->side == 0 && POS->raydirx > 0)
		texx = TEXWIDTH - texx - 1;
	if (POS->side == 1 && POS->raydiry < 0)
		texx = TEXWIDTH - texx - 1;
	return (texx);
}
