/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:38:44 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 09:33:25 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

t_point	*new_point(float x, float y, float z)
{
	t_point	*p;

	p = (t_point*)malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

t_vect	*new_vect(t_type x, t_type y, t_type z)
{
	t_vect	*v;

	v = (t_vect*)malloc(sizeof(t_vect));
	v->x = x;
	v->y = y;
	v->z = z;
	v->l = find_magnitude(x, y, z);
	return (v);
}

t_type	find_magnitude(t_type x, t_type y, t_type z)
{
	t_type	l;

	l = (float)sqrt((x * x) + (y * y) + (z * z));
	return (l);
}

t_type	dot_product(t_vect *v1, t_vect *v2)
{
	return ((t_type)((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z)));
}

t_vect	*cross_vect(t_vect *v1, t_vect *v2)
{
	t_vect	*v3;

	v3 = (t_vect*)malloc(sizeof(t_vect));
	v3->x = v1->y * v2->z - v1->z * v2->y;
	v3->y = v1->z * v2->x - v1->x * v2->z;
	v3->z = v1->x * v2->y - v1->y * v2->x;
	v3->l = find_magnitude(v3->x, v3->y, v3->z);
	return (v3);
}
