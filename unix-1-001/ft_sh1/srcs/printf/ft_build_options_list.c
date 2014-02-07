/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_options_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:21:16 by rgary             #+#    #+#             */
/*   Updated: 2013/12/19 16:43:58 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_printf.h"

t_op	*ft_build_list(t_op *op, char *str, int *i, int j)
{
	int		l;
	t_op	*tmp;
	t_op	*new;

	l = *i;
	tmp = (t_op*)malloc(sizeof(t_op));
	if (!j)
	{
		tmp = ft_build_options_struct(tmp);
		*i = ft_field_options(str, tmp, l);
		new = ft_list_push_back(op, tmp);
		return (new);
	}
	else
		tmp = ft_build_options_struct_spe(tmp);
	new = ft_list_push_back(op, tmp);
	return (new);
}

t_op	*ft_list_push_back(t_op *op, t_op *new)
{
	t_op	*save;

	save = op;
	if (op == NULL)
		return (new);
	while (op->next != NULL)
		op = op->next;
	op->next = new;
	return (save);
}

t_op	*ft_analyse_str(char *str, t_op *op)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
			i++;
		if (str[i] == '%')
		{
			if (str[i + 1] == '%' || str[i + 1] == 'Z')
				j = 1;
			i += 1;
			op = ft_build_list(op, str, &i, j);
		}
	}
	return (op);
}

int		ft_converter_options(char *str, t_op *op, int i)
{
	int		j;

	j = 0;
	if (IS_N_CONVER)
	{
		while (IS_N_CONVER && str[i + j] != '%')
		{
			op->arg_size += 1;
			i++;
		}
		op->arg_size -= 1;
	}
	else
	{
		op->conv = str[i];
		i += 1;
	}
	op->arg_size += 1;
	return (i);
}
