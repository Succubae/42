/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 16:03:39 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/10 16:03:41 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ftprintf.h"
#include "libft.h"

void	list_pushback(t_format **list, t_format **format)
{
	t_format	*save;

	if (*list == NULL)
		*list = *format;
	else
	{
		save = *list;
		while ((*list)->next != NULL)
			*list = (*list)->next;
		(*list)->next = *format;
		*list = save;
	}
}

int		list_count(t_format *list)
{
	int	count;

	count = 0;
	if (list)
	{
		while (list)
		{
			count++;
			list = list->next;
		}
	}
	return (count);
}

t_conv	*create_conv(char conv, t_func f)
{
	t_conv	*elem;

	if ((elem = (t_conv *) ft_memalloc(sizeof(t_conv))) == NULL)
		impossible_malloc("t_conv");
	elem->conv = conv;
	elem->func = f;
	elem->next = NULL;
	return (elem);
}

void	add_conv(t_conv **list, t_conv *conv)
{
	if (*list)
		conv->next = *list;
	*list = conv;
}