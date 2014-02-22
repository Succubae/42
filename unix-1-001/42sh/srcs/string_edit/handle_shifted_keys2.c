/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shifted_keys2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 12:55:21 by rgary             #+#    #+#             */
/*   Updated: 2014/02/22 14:48:24 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "string_edit.h"

void	ft_to_get_under_25_lines_1(t_print *print)
{
	while (print->pos > 0)
	{
		tputs(tgetstr("le", NULL), 1, out);
		print->pos -= 1;
	}
}

void    ft_to_get_under_25_lines_2(t_print *print, int i, int j)
{
	while (print->pos < (i + j))
    {
        tputs(tgetstr("nd", NULL), 1, out);
        print->pos -= 1;
    }
}
