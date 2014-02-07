/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:23:23 by rgary             #+#    #+#             */
/*   Updated: 2013/11/20 18:45:56 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>
void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	i = 0;
	tmp = (char*)s1;
	tmp2 = (char*)s2;
	tmp3 = (char*)malloc(sizeof(*tmp) * n);
	while (i < n)
	{
		tmp3[i] = tmp2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmp[i] = tmp3[i];
		i++;
	}
	free (tmp3);
	return (s1);
}
