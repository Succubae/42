/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:32:23 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/20 16:32:26 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "ftprintf.h"

int			basic_x_conv(va_list *ap, t_format *format)
{
	unsigned int	conv;
	char			*s;
	size_t			len;

	conv = va_arg(*ap, unsigned int);
	s = ft_utoa(conv, 16);
	apply_flags(&s, format);
	len = ft_strlen(s);
	write(FD_OUT, s, len);
	return (len);
}

int			basic_p_conv(va_list *ap, t_format *format)
{
	void	*conv;
	char	*s;
	size_t	len;

	conv = va_arg(*ap, void *);
	s = ft_utoa((t_ul) conv, 16);
	apply_flags(&s, format);
	len = ft_strlen(s);
	write(FD_OUT, "0x", 2);
	write(FD_OUT, s, len);
	return (len + 2);
}

static void	add_basic(t_conv **list)
{
	add_conv(list, create_conv('x', basic_x_conv));
	add_conv(list, create_conv('p', basic_p_conv));
}

void		add_x_func(t_conv **list)
{
	add_basic(list);
}