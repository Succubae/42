/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 19:50:41 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/02 13:21:53 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ftprintf.h"

int			basic_d_conv(va_list *ap, t_format *format)
{
	int		conv;
	char	*s;
	size_t	len;

	if (format->has_star)
		format->m_width = va_arg(*ap, int);
	conv = va_arg(*ap, int);
	s = ft_stoa(conv);
	apply_flags(&s, format);
	len = ft_strlen(s);
	write(FD_OUT, s, len);
	free(s);
	return (len);
}

static void	add_basic(t_conv **list)
{
	add_conv(list, create_conv('d', basic_d_conv));
	add_conv(list, create_conv('i', basic_d_conv));
}

void		add_d_func(t_conv **list)
{
	add_basic(list);
}
