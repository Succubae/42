/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:47:16 by rgary             #+#    #+#             */
/*   Updated: 2014/01/15 14:10:25 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WOLF3D_H
# define WOLF3D_H

# include <SDL2/SDL.h>
# include "get_next_line.h"

# define WIND_X		1280
# define WIND_Y		1024
# define MWIDTH		24
# define MHEIGHT	24
# define TEXWIDTH	64
# define SCW		SDL_CreateWindow
# define SCR		SDL_CreateRenderer
# define SWS		SDL_WINDOW_SHOWN
# define SDL_SRCCOLORKEY 0x00001000
# define SPOS		(*all)->pos
# define POS		all->pos

# define FP			ft_printf

typedef struct	s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		**tab;
	SDL_Surface		*bmp;
	SDL_Texture		*tex;
}				t_sdl;

typedef struct	s_pos
{
	int		texnbr;
	int		mapwidth;
	int		mapheight;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		wallheight;
	int		drawstart;
	int		drawend;
	int		color;
	int		nsew;
	float	posx;
	float	posy;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
	float	camerax;
	float	rayposx;
	float	rayposy;
	float	raydirx;
	float	raydiry;
	float	sidedistx;
	float	sidedisty;
	float	deltadistx;
	float	deltadisty;
	float	walldist;;
}				t_pos;

typedef struct	s_all
{
	t_sdl	*sdl;
	t_pos	*pos;
	int		**map;
}				t_all;
/*
**ft draw
*/
void	ft_draw_line(t_all*, int);
/*
**ft color
*/
int		ft_get_color(int, int, int);
int		ft_find_color(t_all*);
/*
**ft calc
*/
void	ft_find_ray_dir_and_dist(t_all **all, int x);
void	ft_calc_step(t_all **all);
void	ft_find_wall(t_all **all);
void	ft_find_dist_wall(t_all **all);
/*
**ft keyhook
*/
void	other_event(const Uint8 *g_state, t_all **all);
void	yet_another_event(const Uint8 *g_state, t_all **all);
int		ft_abs(int);
void	sdl_event(t_all **all);
void	ft_redraw(t_all*);
/*
**ft get land data
*/
int     *get_n_line(int fd);
int     **ft_get_data(void);
/*
**ft str nbr split
*/
char	**ft_str_nbr_split(const char *s);
/*
**ft atoi
*/
int		ft_atoi(const char *str);
void	error(const char *s);
/*
**create tex coor
*/
void	fill_rect(t_all*, SDL_Rect*, int, int);
void	show_weapon(t_all *all);
void	create_tex_tab(t_sdl **sdl);
int     calc_tex_x_coor(t_all *all);
#endif
