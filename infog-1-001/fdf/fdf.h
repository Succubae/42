/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 12:22:58 by rgary             #+#    #+#             */
/*   Updated: 2013/12/18 10:53:47 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

#include <string.h>
# define WIND_X 1000
# define WIND_Y 1000
# define X1 pts->x1
# define X2 pts->x2
# define Y1 pts->y1
# define Y2 pts->y2
# define sgn(x) ((x<0)?-1:((x>0)?1:0))
# define RSX all->rot->sizex
# define RSY all->rot->sizey

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_rot
{
	int			rotx;
	int			roty;
	int			rotz;
	int			centerx;
	int			centery;
	int			sizex;
	int			sizey;
}				t_rot;

typedef struct	s_pts
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		mx1;
	int		my1;
	int		mx2;
	int		my2;
	int		height;
}				t_pts;

typedef struct	s_all
{
	struct s_mlx	*mlx;
	struct s_rot	*rot;
	int				**tab;
	int				height;
	float			incl;
	int				rotx;
	int				roty;
}				t_all;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putendl(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *str);
void	ft_putstr(const char *c);
void	ft_putchar(char c);
char	*ft_strcpy(char *str, const char *str2);
char	*ft_strdup(const char *str);
int		ft_strichr(char *str, int l);
char	*ft_strnew(size_t size);
char	*ft_strnjoin(char const *s1, char const *s2, int n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_putnbrl(int n);
void	ft_putnbr(int n);
char	**ft_strsplit(char const *s, char c);
int		get_next_line(int const fd, char **line);
/*
**get land data
*/
int		*get_n_line(int fd, t_rot *rot);
int		**ft_get_data(const char *str, t_rot *rot);
/*
**main
*/
char	*ft_convert_to_hexa(int n);
char	*ft_create_color(int j, int l);
t_rot	*build_rot_struct(void);
int		main(int argc, char**argv);
/*
**key_hook
*/
int		key_hook(int keycode, t_all *all);
void	key_hook_2(int keycode, t_all *all);
void	key_hook_3(int keycode, t_all *all);
int		expose_hook(t_all *all);
/*
** ft_math
*/
float	ft_abs(float x);
float	ft_cosinus(float x);
float	ft_sinus(float x);
float	ft_power_float(float a, float b);
float	ft_fact(int n);
/*
** ft draw
*/
void	ft_draw_horizontaly(t_all*);
void	ft_draw_verticaly(t_all*);
void	ft_build_perspective(t_pts*, t_all*);
void	ft_place_points(t_pts*, t_all*);
void	ft_new_draw_algo(t_pts*, t_mlx *mlx);
/*
**str nbr split
*/
char    **ft_str_nbr_split(const char *s);
#endif
