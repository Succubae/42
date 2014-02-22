/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:40:14 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 16:52:49 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "get_next_line.h"

# define SCREEN_WIDTH	700
# define SCREEN_HEIGHT	700
# define FRONT(s)		cam->frontvect->s

typedef float t_type;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;
typedef struct	s_point
{
	t_type		x;
	t_type		y;
	t_type		z;
}				t_point;

typedef struct	s_vect
{
	t_type		x;
	t_type		y;
	t_type		z;
	t_type		l;
}				t_vect;

typedef struct	s_lray
{
	t_type		x;
	t_type		y;
	t_type		z;
	t_type		dirx;
	t_type		diry;
	t_type		dirz;
	t_type		tmin;
	t_type		tmax;
}				t_lray;

typedef struct	s_cam
{
	t_vect	*pos;
	t_vect	*dir;
	t_vect	*dirray;
	t_vect	*frontvect;
	t_vect	*sidevect;
	t_vect	*upvect;
	t_type	t_min;
	t_type	t_max;
	t_type	vpwidth;
	t_type	vpheight;
	t_type	vpdist;
	t_vect	*vpupleftpos;
}				t_cam;

typedef enum	e_obj_type
{
	CAMERA = 0,
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	CUBE
}				t_obj_type;

typedef struct s_obj	t_obj;

struct s_obj
{
	t_obj_type	type;
	t_vect		*pos;
	t_vect		*nor;
	t_type		posx;
	t_type		posy;
	t_type		posz;
	t_type		norx;
	t_type		nory;
	t_type		norz;
	t_type		radius;
	t_type		height;
	t_type		width;
	t_type		depth;
	t_obj		*next;
	int			r;
	int			g;
	int			b;
};

typedef struct s_all	t_all;

struct s_all
{
	t_obj	*lst;
	t_cam	*cam;
	t_mlx	*mlx;
};

typedef t_obj*	(ft_data)(t_obj *lst, char **tab, char *buf);

/*
**params sphere :
**x;y;z;r
**params plane :
**x;y;z
**params cone :
**x;y;z;r;h
**params cylinder :
**x;y;z;r;h
**params cube :
**x;y;z;h;w;d
*/

/*
**BUILD STRUCT
*/
t_point	*new_point(t_type x, t_type y, t_type z);
t_vect	*new_vect(t_type x, t_type y, t_type z);
t_type	find_magnitude(t_type x, t_type y, t_type z);
void	norm_vect(t_vect *v);
t_type	dot_product(t_vect *v1, t_vect *v2);
t_vect	*cross_vect(t_vect *v1, t_vect *v2);
/*
**CAM BUILDER
*/
t_cam	*create_camera(t_cam *cam, t_vect*, t_vect*);
void	fill_orient(t_cam *cam);
t_vect	*find_upleftpos(t_cam *cam);
t_vect	*update_cam_dirray(t_cam *cam, t_type i, t_type j);
t_obj	*camera_data(t_obj *lst, char **tab, char *buf);
/*
**COLOR
*/
int		build_color(int, int, int);
/*
**FILL OBJLIST
*/
t_obj	*sphere_data(t_obj *lst, char **tab, char *buf);
t_obj	*plane_data(t_obj *lst, char **tab, char *buf);
t_obj	*cone_data(t_obj *lst, char **tab, char *buf);
t_obj	*cylinder_data(t_obj *lst, char **tab, char *buf);
t_obj	*cube_data(t_obj *lst, char **tab, char *buf);
/*
**LOOK FOR OBJ
*/
t_type	look_for_cylinder(t_obj *lst, t_type *dist);
t_type	look_for_sphere(t_obj *lst, t_type *dist);
t_type	look_for_plane(t_obj *lst, t_type *dist);
t_type	look_for_cone(t_obj *lst, t_type *dist);
/*
**OBJ LIST
*/
t_obj	*lst_push_back(t_obj *lst, t_obj *bgn_lst);
t_obj	*find_type(t_obj *lst, char *buf);
t_obj	*build_lnk(char *buf);
t_obj	*fill_data(char *buf, t_obj *lst);
t_obj	*get_obj_from_file(char *file);
/*
**RAY TRACER
*/
void	calc_rays(t_cam *cam, t_obj *lst);
void	find_another_obj(t_obj *save, t_type *dist, t_type *tmp, int cnt[2]);
/*
**UTILS
*/
t_vect	*matrix_sub(t_vect *v1, t_vect *v2);
t_vect	*matrix_add(t_vect *v1, t_vect *v2);
t_vect	*matrix_mul_by_val(t_vect *m1, t_type f);
t_vect	*matrix_div_by_val(t_vect *m1, t_type f);
t_vect	*matrix_add_by_val(t_vect *m1, t_type f);
/*
**UTILS2
*/
void	norm_vect(t_vect *v);
int		check_file(char *file);
void	put_pixel_by_object(int cnt[2], int l);
int		find_dist(t_type *dist, t_type a, t_type b, t_type det);
void	find_closest_obj(t_obj *save, t_type *dist, t_type *tmp, int cnt[2]);
float	power(float);
/*
**UTILS3
*/
t_vect	*matrix_sub_by_val(t_vect *m1, t_type f);
t_all	*build_all(t_mlx *mlx, t_cam *cam, t_obj *lst);
int		expose_hook(t_all *all);
/*
**MAIN
*/
void	file_error(char *s, char *s2);
t_mlx	*store_mlx(t_mlx*);
t_cam	*store_cam(t_cam*);
void	file_error(char *s, char *s2);


#endif
