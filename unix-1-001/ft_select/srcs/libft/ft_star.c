/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 13:37:24 by rgary             #+#    #+#             */
/*   Updated: 2013/11/27 13:56:38 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_star(const char *s1, const char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (!*s1 && *s2 == '*')
		return (ft_star(s1, s2 + 1));
	else if (*s1 && *s2 == '*')
		return ((ft_star(s1 + 1, s2)) || (ft_star(s1, s2 + 1)));
	else if (*s1 == *s2)
		return (ft_star(s1 + 1, s2 + 1));
	return (0);
}
