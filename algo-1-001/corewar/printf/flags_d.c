/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:49:05 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/18 22:49:07 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"

void	handle_zero(char **, t_format *);
void	handle_minus(char **, t_format *);
void	handle_space(char **, t_format *);
void	handle_plus(char **, t_format *);

void	handle_flags_for_d(char **s, t_format *format)
{
	handle_zero(s, format);
	handle_minus(s, format);
	handle_space(s, format);
	handle_plus(s, format);
}

void	handle_space(char **s, t_format *format)
{
	if (format->f_list->has_space && !format->f_list->has_plus)
	{
		if (*s && ((*s)[0] != '-'))
			ft_strpad2(s, ft_strlen(*s) + 1, PAD_LEFT, ' ');
	}
}

void	handle_zero(char **s, t_format *format)
{
	if (format->f_list->has_zero)
	{
		if ((!format->f_list->has_minus) && (format->preci == -1))
			if (format->m_width != 0)
				ft_strpad2(s, format->m_width, PAD_LEFT, '0');
	}
}

void	handle_minus(char **s, t_format *format)
{
	if (format->f_list->has_minus && (format->m_width != 0))
		ft_strpad2(s, format->m_width, PAD_RIGHT, ' ');
}

void	handle_plus(char **s, t_format *format)
{
	if (format->f_list->has_plus)
		if (*s && ((*s)[0] != '-'))
			ft_strpad2(s, ft_strlen(*s) + 1, PAD_LEFT, '+');
}