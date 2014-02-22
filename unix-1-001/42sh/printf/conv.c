/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:02:42 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/18 22:02:44 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"

t_conv	*init_convlist(void)
{
	static t_conv	*list = NULL;

	if (!list)
	{
		if ((list = (t_conv *) malloc(sizeof(t_conv))) == NULL)
			impossible_malloc("t_conv");
		add_d_func(&list);
		add_c_func(&list);
		add_s_func(&list);
		add_u_func(&list);
		add_o_func(&list);
		add_x_func(&list);
	}
	return (list);
}

t_func	get_conversion(t_format *list)
{
	t_conv	*conv;

	conv = init_convlist();
	while (conv)
	{
		if (list->conv == conv->conv)
			return (conv->func);
		conv = conv->next;
	}
	return (NULL);
}

void	apply_flags(char **s, t_format *format)
{
	t_paddir	dir;
	int			tmp;

	if (format->f_list)
	{
		if ((format->conv == 'd') || (format->conv == 'i'))
			handle_flags_for_d(s, format);
	}
	else if (format->m_width != 0)
	{
		tmp = format->m_width;
		dir = (format->m_width > 0 ? PAD_LEFT : PAD_RIGHT);
		if (tmp < 0)
			tmp = -tmp;
		ft_strpad2(s, tmp, dir, ' ');
	}
}