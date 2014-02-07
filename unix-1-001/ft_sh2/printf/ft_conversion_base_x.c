/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_base_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 17:34:04 by rgary             #+#    #+#             */
/*   Updated: 2013/12/19 11:02:49 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

char		*ft_convert_to_octal(unsigned long n)
{
	char			*s;
	char			c;
	unsigned long	k;
	int				i;

	k = n;
	i = 1;
	while ((n /= 10) != 0)
		i++;
	s = (char*)malloc(sizeof(char) * i + 1);
	ft_bzero(s, i + 1);
	s = s + i - 1;
	if (k == 0)
		*s = '0';
	while (k != 0)
	{
		c = (k % 8) + 48;
		k = k / 8;
		*--s = c;
	}
	return (s);
}

char		*ft_convert_to_hexa(unsigned long n, char conv)
{
	char			*s;
	char			c;
	int				i;
	unsigned long	k;

	k = n;
	c = 'a';
	if (conv != 'p')
		c = (conv == 'x' ? 'a' : 'A');
	i = 1;
	while ((n /= 10) != 0)
		i++;
	s = (char*)malloc(sizeof(char) * 17);
	ft_bzero(s, 17);
	s = s + 16;
	if (k == 0)
		*s = '0';
	while (k != 0)
	{
		*--s = ((k % 16) > 9 ? c + ((k % 16) - 10) : (k % 16) + '0');
		k /= 16;
	}
	return (s);
}
