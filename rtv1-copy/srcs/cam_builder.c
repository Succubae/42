/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 11:03:46 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 13:45:07 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam	*create_camera(t_cam *cam, t_vect *pos, t_vect *dir)
{
	cam = (t_cam*)malloc(sizeof(t_cam));
	cam->dirray = (t_vect*)malloc(sizeof(t_vect));
	cam->pos = pos;
	cam->dir = dir;
	norm_vect(cam->dir);
	cam->vpwidth = 0.5;
	cam->vpheight = 0.5;
	cam->vpdist = 1.0;
	fill_orient(cam);
	cam->t_min = 0;
	cam->t_max = 2000000000;
	cam->vpupleftpos = find_upleftpos(cam);
	cam = store_cam(cam);
	return (cam);
}

void	fill_orient(t_cam *cam)
{
	cam->frontvect = new_vect((cam->pos->x - cam->dir->x),
							(cam->pos->y - cam->dir->y),
							(cam->pos->z - cam->dir->z));
	norm_vect(cam->frontvect);
	cam->sidevect = new_vect(((FRONT(y) * -1.0) - (FRONT(z) * 0.0)),
							((FRONT(z) * 0.0) - (FRONT(x) * -1.0)),
							((FRONT(x) * 0.0) - (FRONT(y) * 0.0)));
	norm_vect(cam->sidevect);
	cam->upvect = new_vect(((cam->sidevect->y * cam->frontvect->z)
							- (cam->sidevect->z * cam->frontvect->y)),
							((cam->sidevect->z * cam->frontvect->x)
							- (cam->sidevect->x * cam->frontvect->z)),
							((cam->sidevect->x * cam->frontvect->y)
							- (cam->sidevect->y * cam->frontvect->x)));
	norm_vect(cam->frontvect);
}

t_vect	*find_upleftpos(t_cam *cam)
{
	static t_type	val = 0;
	static t_type	val2 = 0;
	t_vect			*vect1;
	t_vect			*vect2;
	t_vect			*vect3;

	if (val == 0)
		val = cam->vpheight / 2.0;
	if (val2 == 0)
		val2 = cam->vpwidth / 2.0;
	vect1 = matrix_mul_by_val(cam->upvect, val);
	vect2 = matrix_mul_by_val(cam->sidevect, val2);
	vect3 = matrix_add(cam->frontvect, vect1);
	free(vect1);
	vect1 = matrix_add(cam->pos, vect3);
	free(vect3);
	vect3 = matrix_sub(vect1, vect2);
	free(vect1);
	free(vect2);
	norm_vect(vect3);
	return (vect3);
}

t_vect	*update_cam_dirray(t_cam *cam, t_type i, t_type j)
{
	static t_type	iincr = 0;
	static t_type	jincr = 0;
	t_vect			*v4;
	t_vect			*v2;
	t_vect			*v3;

	if (iincr == 0)
		iincr = cam->vpwidth / (t_type)SCREEN_WIDTH;
	if (jincr == 0)
		jincr = cam->vpheight / (t_type)SCREEN_HEIGHT;
	v2 = matrix_mul_by_val(cam->sidevect, iincr);
	v3 = matrix_mul_by_val(v2, i);
	free(v2);
	v2 = matrix_mul_by_val(cam->upvect, jincr);
	v4 = matrix_mul_by_val(v2, j);
	free(v2);
	v2 = matrix_add(cam->vpupleftpos, v3);
	free(v3);
	v3 = matrix_sub(v2, v4);
	norm_vect(v3);
	return (v3);
}

t_obj	*camera_data(t_obj *lst, char **tab, char *buf)
{
	t_vect	*pos;
	t_vect	*dir;
	t_cam	*cam;

	cam = NULL;
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] == NULL
		|| tab[4] == NULL || tab[5] == NULL)
		file_error("Parser error in scene file near : ", buf);
	pos = new_vect(ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2]));
	dir = new_vect(ft_atof(tab[3]), ft_atof(tab[4]), ft_atof(tab[5]));
	cam = create_camera(cam, pos, dir);
	(void)lst;
	return (NULL);
}
