/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:49:19 by rgary             #+#    #+#             */
/*   Updated: 2013/12/08 09:44:55 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	while (str[i])
		i++;
	cpy = (char*)malloc(sizeof(char) * i + 1);
	if (!cpy)
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		cpy[i] = str[i];
	cpy[i] = '\0';
	return (cpy);
}
