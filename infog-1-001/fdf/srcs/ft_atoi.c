/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:07:51 by rgary             #+#    #+#             */
/*   Updated: 2013/12/03 11:09:43 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	ft_power(int n)
{
	if (n == 0)
		return (1);
	if (n == 1)
		return (10);
	else
		return (10 * ft_power(n - 1));
}

int			ft_atoi(const char *str)
{
	int		size;
	int		i;
	int		neg;
	int		result;

	neg = 1;
	size = ft_strlen(str);
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result += ((str[i] - 48) * ft_power(size - i - 1));
		i++;
	}
	if ((size - i) > 0)
		result /= ft_power(size - i);
	return (result * neg);
}
