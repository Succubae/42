/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:40:59 by rgary             #+#    #+#             */
/*   Updated: 2014/01/21 15:30:16 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char		*ft_fill_right(const char *s, char *str, char c, int total)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(s))
	{
		str[i] = s[i];
		i++;
	}
	while (i < total)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_fill_left(const char *s, char *str, char c, int fill)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < fill)
	{
		str[i] = c;
		i += 1;
	}
	while (i < (int)(ft_strlen(s) + fill))
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_padding(const char *s, size_t total, int direction, char c)
{
	int		i;
	char	*str;

	i = total - ft_strlen(s);
	str = ft_strnew(total);
	if (direction == 0)
		str = ft_fill_left(s, str, c, i);
	else if (direction == 1)
		str = ft_fill_right(s, str, c, total);
	return (str);
}
