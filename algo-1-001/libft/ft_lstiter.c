/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:16:58 by rgary             #+#    #+#             */
/*   Updated: 2013/11/25 18:34:20 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*tmp2;

	if (tmp = lst)
	{
		while (tmp->next)
		{
			tmp2 = tmp->next;
			(*f)(tmp);
			tmp = tmp2;
		}
		(*f)(tmp);
	}
}
