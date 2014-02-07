/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:43:20 by rgary             #+#    #+#             */
/*   Updated: 2013/11/25 13:11:30 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
int		ft_strcmp(const char *str, const char *str2)
{
	unsigned char	*_str;
	unsigned char	*_str2;

	_str = (unsigned char*) str;
	_str2 = (unsigned char*) str2;
	while (*_str != '\0' && *_str2 != '\0' && *_str == *_str2)
	{
		_str++;
		_str2++;
	}
	return (*_str - *_str2);
}
