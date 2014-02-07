/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_options_struct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:42:20 by rgary             #+#    #+#             */
/*   Updated: 2013/12/19 16:51:56 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_printf.h"

t_op	*ft_build_options_struct_spe(t_op *op)
{
	op = (t_op*)malloc(sizeof(t_op));
	op->field = 0;
	op->flag = NULL;
	op->separator = '\0';
	op->min_width = 0;
	op->starwidth = '\0';
	op->precision = 0;
	op->mod = NULL;
	op->conv = '\0';
	op->next = NULL;
	op->arg_size = 1;
	return (op);
}

t_op	*ft_build_options_struct(t_op *op)
{
	op = (t_op*)malloc(sizeof(t_op));
	op->field = 0;
	op->flag = NULL;
	op->separator = '\0';
	op->min_width = 0;
	op->starwidth = '\0';
	op->precision = 0;
	op->mod = NULL;
	op->conv = '\0';
	op->next = NULL;
	op->arg_size = 0;
	return (op);
}
