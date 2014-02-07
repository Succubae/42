/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:18:45 by rgary             #+#    #+#             */
/*   Updated: 2013/11/26 11:34:15 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lnk;

	lnk = (t_list*)malloc(sizeof(t_list));
	lnk->content = (void*)malloc(sizeof(void) * content_size);
	if (content == 0)
	{
		lnk->content = NULL;
		lnk->content_size = 0;
	}
	else
	{
		lnk->content = (void*)content;
		lnk->content_size = content_size;
	}
	lnk->next = NULL;
	return (lnk);
}
