/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:06:29 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/02 13:21:01 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "libft.h"

void		check_for_arg_nb(t_format *list)
{
	int			nb_arg;
	t_format	*save;

	nb_arg = 0;
	save = list;
	while (list)
	{
		if (list->arg_nb != -1)
			nb_arg++;
		list = list->next;
	}
	if ((nb_arg != 0) && (list_count(save) != nb_arg))
		kill_me("If you are going to use $-Style please use it everywhere.");
	save = NULL;
}

int			print_bad_format(t_format *format)
{
	ft_putchar_fd((format->format)[(format->length - 1)], FD_OUT);
	if (format->m_width != 0)
		return (format->m_width);
	return (1);
}

int			print_arg(va_list *ap, t_format *list)
{
	t_func	f;
	int		printed;

	f = get_conversion(list);
	if (!f)
		return (print_bad_format(list));
	printed = (*f)(ap, list);
	return (printed);
}
