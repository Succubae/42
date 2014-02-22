/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 17:43:58 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 11:10:55 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	*matrix_sub(t_vect *v1, t_vect *v2)
{
	t_vect	*v3;

	v3 = (t_vect*)malloc(sizeof(t_vect));
	v3->x = v1->x - v2->x;
	v3->y = v1->y - v2->y;
	v3->z = v1->z - v2->z;
	v3->l = find_magnitude(v3->x, v3->y, v3->z);
	return (v3);
}

t_vect	*matrix_add(t_vect *v1, t_vect *v2)
{
	t_vect	*v3;

	v3 = (t_vect*)malloc(sizeof(t_vect));
	v3->x = v1->x + v2->x;
	v3->y = v1->y + v2->y;
	v3->z = v1->z + v2->z;
	v3->l = find_magnitude(v3->x, v3->y, v3->z);
	return (v3);
}

t_vect	*matrix_mul_by_val(t_vect *m1, t_type f)
{
	t_vect	*m2;

	m2 = (t_vect*)malloc(sizeof(t_vect));
	m2->x = m1->x * f;
	m2->y = m1->y * f;
	m2->z = m1->z * f;
	m2->l = find_magnitude(m2->x, m2->y, m2->z);
	return (m2);
}

t_vect	*matrix_div_by_val(t_vect *m1, t_type f)
{
	t_vect	*m2;

	m2 = (t_vect*)malloc(sizeof(t_vect));
	m2->x = m1->x / f;
	m2->y = m1->y / f;
	m2->z = m1->z / f;
	m2->l = find_magnitude(m2->x, m2->y, m2->z);
	return (m2);
}

t_vect	*matrix_add_by_val(t_vect *m1, t_type f)
{
	t_vect	*m2;

	m2 = (t_vect*)malloc(sizeof(t_vect));
	m2->x = m1->x + f;
	m2->y = m1->y + f;
	m2->z = m1->z + f;
	m2->l = find_magnitude(m2->x, m2->y, m2->z);
	return (m2);
}
