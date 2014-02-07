/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node_part1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 11:55:46 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 13:53:43 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "hotrace.h"

t_ascii		*make_node(void)
{
	t_ascii *tmp;

    if ((tmp = (t_ascii*)malloc(sizeof(t_ascii))) == NULL)
    {
        ft_putstrendl("Malloc Error");
        return (NULL);
    }
	tmp->zero = NULL;
    tmp->one = NULL;
    tmp->two = NULL;
    tmp->three = NULL;
    tmp->four = NULL;
    tmp->five = NULL;
    tmp->six = NULL;
    tmp->seven = NULL;
    tmp->eight = NULL;
    tmp->nine = NULL;
    tmp->A = NULL;
	tmp->B = NULL;
    tmp->C = NULL;
    tmp->D = NULL;
    tmp->E = NULL;
    tmp->F = NULL;
	make_node_2(tmp);
	return (tmp);
}

void		make_node_2(t_ascii *tmp)
{
	tmp->G = NULL;
    tmp->H = NULL;
    tmp->I = NULL;
    tmp->J = NULL;
    tmp->K = NULL;
    tmp->L = NULL;
    tmp->M = NULL;
    tmp->N = NULL;
    tmp->O = NULL;
    tmp->P = NULL;
    tmp->Q = NULL;
    tmp->R = NULL;
    tmp->S = NULL;
    tmp->T = NULL;
    tmp->U = NULL;
    tmp->V = NULL;
    tmp->W = NULL;
	tmp->X = NULL;
    tmp->Y = NULL;
    tmp->Z = NULL;
    tmp->a = NULL;
    tmp->b = NULL;
    tmp->c = NULL;
    tmp->d = NULL;
	make_node_3(tmp);
}

void		make_node_3(t_ascii *tmp)
{
	tmp->e = NULL;
    tmp->f = NULL;
    tmp->g = NULL;
    tmp->h = NULL;
    tmp->i = NULL;
    tmp->j = NULL;
    tmp->k = NULL;
    tmp->l = NULL;
    tmp->m = NULL;
    tmp->n = NULL;
    tmp->o = NULL;
    tmp->p = NULL;
    tmp->q = NULL;
    tmp->r = NULL;
    tmp->s = NULL;
    tmp->t = NULL;
    tmp->u = NULL;
    tmp->v = NULL;
    tmp->w = NULL;
    tmp->x = NULL;
    tmp->y = NULL;
    tmp->z = NULL;
    tmp->space = NULL;
	make_node_4(tmp);
}

void		make_node_4(t_ascii *tmp)
{
	tmp->excl = NULL;
    tmp->quote = NULL;
    tmp->num = NULL;
    tmp->dollar = NULL;
    tmp->percent = NULL;
    tmp->and = NULL;
    tmp->squote = NULL;
    tmp->op = NULL;
    tmp->cp = NULL;
    tmp->star = NULL;
    tmp->plus = NULL;
    tmp->coma = NULL;
    tmp->minus = NULL;
    tmp->point = NULL;
    tmp->slash = NULL;
    tmp->dbpoint = NULL;
    tmp->pointcoma = NULL;
    tmp->left = NULL;
	tmp->equal = NULL;
    tmp->right = NULL;
    tmp->inter = NULL;
    tmp->arob = NULL;
    tmp->oc = NULL;
    tmp->backslash = NULL;
	make_node_5(tmp);
}

void		make_node_5(t_ascii *tmp)
{
	tmp->cc = NULL;
    tmp->up = NULL;
    tmp->under = NULL;
    tmp->accent = NULL;
    tmp->ov = NULL;
    tmp->pipe = NULL;
    tmp->cv = NULL;
    tmp->tild = NULL;
    tmp->result = NULL;
}
