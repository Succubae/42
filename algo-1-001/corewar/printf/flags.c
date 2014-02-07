/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:28:57 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/18 22:28:59 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"

t_flags	*init_flags(void)
{
	t_flags	*out;

	if ((out = (t_flags *) malloc(sizeof(t_flags))) == NULL)
		impossible_malloc("t_flags");
	out->has_hashtag = 0;
	out->has_zero = 0;
	out->has_minus = 0;
	out->has_space = 0;
	out->has_plus = 0;
	return (out);
}

void	check_unicity_and_update(char flag, int *val)
{
	if (*val == 0)
		*val = 1;
	else
		not_unique_flag(flag);
}

void	update_flags(t_format **format, char *flags)
{
	if (!(*format)->f_list)
		(*format)->f_list = init_flags();
	while (*flags)
	{
		if (*flags == '#')
			check_unicity_and_update(*flags, &((*format)->f_list->has_hashtag));
		if (*flags == '0')
			check_unicity_and_update(*flags, &((*format)->f_list->has_zero));
		if (*flags == '-')
			check_unicity_and_update(*flags, &((*format)->f_list->has_minus));
		if (*flags == ' ')
			check_unicity_and_update(*flags, &((*format)->f_list->has_space));
		if (*flags == '+')
			check_unicity_and_update(*flags, &((*format)->f_list->has_plus));
		flags++;
	}
}