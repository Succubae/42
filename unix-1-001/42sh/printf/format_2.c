/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:33:30 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/19 16:33:31 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"

void	free_format(t_format *save)
{
	t_format	*tmp;

	while (save)
	{
		if (save->f_list)
			free(save->f_list);
		if (save->l_mod)
			free(save->l_mod);
		if (save->format)
			free(save->format);
		tmp = save;
		save = save->next;
		free(tmp);
	}
}