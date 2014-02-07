/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 09:58:29 by rgary             #+#    #+#             */
/*   Updated: 2013/12/08 09:59:17 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static char	*ft_fillstr(int n, char *tmp)
{
	int		i;

	if (n < 0)
	{
		tmp[0] = '-';
		ft_fillstr(n * -1, tmp);
	}
	if (n > 9)
	{
		ft_fillstr(n / 10, tmp);
		ft_fillstr(n % 10, tmp);
	}
	if (n >= 0 && n <= 9)
	{
		i = 0;
		while (tmp[i] != '\0')
			i++;
		tmp[i] = (n + 48);
		tmp[i + 1] = '\0';
	}
	return (tmp);
}

static char	*ft_fill_min_val(char *tmp, char *tmp2)
{
	int		i;

	i = 0;
	while (tmp2[i] != '\0')
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (tmp);
}

char		*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*tmp;
	char	tmp2[] = "-2147483648";

	i = 0;
	j = 0;
	tmp = (char*)malloc(sizeof(char) * 12);
	ft_bzero(tmp, 12);
	if (n != -2147483648)
		tmp = ft_fillstr(n, tmp);
	else if (n == -2147483648)
		tmp = ft_fill_min_val(tmp, tmp2);
	return (tmp);
}
