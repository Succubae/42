/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 12:28:42 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 17:08:56 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

static void	cat_and_del(int *i, char *newstr, char ***strings)
{
	ft_strcat(newstr, *strings[*i]);
	ft_strdel(strings[*i]);
	*i += 1;
}

char		*ft_strmjoin(int nbstr, ...)
{
	char	*newstr;
	va_list	list;
	char	***strings;
	int		i;
	size_t	totallen;

	i = 0;
	totallen = 0;
	va_start(list, nbstr);
	strings = (char***)malloc(sizeof(char**) * nbstr);
	while (i < nbstr)
	{
		strings[i] = va_arg(list, char**);
		if (strings[i] != NULL)
			totallen += ft_strlen((*strings)[i]);
		i++;
	}
	newstr = ft_strnew(totallen + 1);
	i = 0;
	while (i < nbstr)
		cat_and_del(&i, newstr, strings);
	va_end(list);
	free(strings);
	return (newstr);
}
