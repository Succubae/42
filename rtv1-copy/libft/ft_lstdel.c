/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:50:37 by rgary             #+#    #+#             */
/*   Updated: 2014/01/21 15:29:48 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if ((tmp = *alst))
	{
		while (tmp->next)
		{
			*alst = tmp->next;
			(*del)(tmp->content, tmp->content_size);
			free(tmp);
			tmp = *alst;
		}
		*alst = NULL;
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
	}
}
