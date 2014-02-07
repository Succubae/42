/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_arg_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 09:11:37 by rgary             #+#    #+#             */
/*   Updated: 2013/12/21 19:02:58 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

int			ft_field_options(char *str, t_op *op, int i)
{
	int			j;

	j = 0;
	if (IS_NUM)
	{
		while (IS_STILL_NUM)
			j++;
		if (str[i + j] == '$')
		{
			op->field = ft_atoi(ft_strsub(str, i, j));
			i += j;
			op->arg_size += j;
			i = ft_flag_options(str, op, i + 1);
		}
		else
			i = ft_width_options(str, op, i);
	}
	else
		i = ft_flag_options(str, op, i);
	return (i);
}

int			ft_flag_options(char *str, t_op *op, int i)
{
	int			j;

	j = 0;
	if (IS_FLAG)
	{
		while (IS_FLAG)
			j++;
		op->flag = ft_strsub(str, i, j);
		i += j;
		op->arg_size += j;
	}
	i = ft_width_options(str, op, i);
	return (i);
}

int			ft_width_options(char *str, t_op *op, int i)
{
	int			j;

	j = 0;
	if (IS_NUM)
	{
		while (IS_STILL_NUM)
			j++;
		op->min_width = ft_atoi(ft_strsub(str, i, j));
		i += j;
		op->arg_size += j;
	}
	i = ft_precision_options(str, op, i);
	return (i);
}

int			ft_precision_options(char *str, t_op *op, int i)
{
	int			j;

	j = 0;
	if (str[i] == '.')
	{
		i++;
		while (str[i + j] >= '0' && str[i + j] <= '9')
			j++;
		op->precision = ft_atoi(ft_strsub(str, i, j));
		i += j;
		op->arg_size += j;
	}
	i = ft_modifier_options(str, op, i);
	return (i);
}

int			ft_modifier_options(char *str, t_op *op, int i)
{
	int			j;

	j = 0;
	if (IS_LEN_MOD)
	{
		while (IS_LEN_MOD)
			j++;
		op->mod = ft_strsub(str, i, j);
		i += j;
		op->arg_size += j;
	}
	i = ft_converter_options(str, op, i);
	return (i);
}
