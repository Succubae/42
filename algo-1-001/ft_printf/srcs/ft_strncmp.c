/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:57:00 by rgary             #+#    #+#             */
/*   Updated: 2013/12/21 18:56:57 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
int		ft_strncmp(const char *str, const char *str2, size_t n)
{
	int		i;

	i = 0;
	if (str && str2)
	{
		while (*str != '\0' && *str2 != '\0'
			&& *str == *str2 && i < ((int)n - 1))
		{
			str++;
			str2++;
			i++;
		}
	return (*str - *str2);
	}
	else
		return (-1);
}
