/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:15:29 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/20 16:15:31 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "ftprintf.h"
#include "libft.h"

int			basic_s_conv(va_list *ap, t_format *format)
{
	char	*conv;
	size_t	len;

	conv = va_arg(*ap, char *);
	if (conv == NULL)
		conv = ft_strdup(NULL_STR);
	else
		apply_flags(&conv, format);
	len = ft_strlen(conv);
	write(FD_OUT, conv, len);
	return (len);
}

static void	add_basic(t_conv **list)
{
	add_conv(list, create_conv('s', basic_s_conv));
}

void		add_s_func(t_conv **list)
{
	add_basic(list);
}