/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 18:36:50 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/19 18:36:52 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "ftprintf.h"
#include "libft.h"

int			basic_c_conv(va_list *ap, t_format *format)
{
	char	conv;
	char	*for_flags;
	size_t	len;
	size_t	len2;

	len = 1;
	conv = (char) va_arg(*ap, int);
	for_flags = ft_strnew(2);
	if (!for_flags)
		impossible_malloc("strnew basic_c_conv");
	for_flags[0] = conv;
	apply_flags(&for_flags, format);
	if ((len2 = ft_strlen(for_flags)) > len)
		len = len2;
	write(FD_OUT, for_flags, len);
	return (len);
}

static void	add_basic(t_conv **list)
{
	add_conv(list, create_conv('c', basic_c_conv));
}

void		add_c_func(t_conv **list)
{
	add_basic(list);
}