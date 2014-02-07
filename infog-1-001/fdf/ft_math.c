/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 10:21:09 by rgary             #+#    #+#             */
/*   Updated: 2013/12/28 15:38:58 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

float	ft_abs(float x)
{
	return (x < 0 ? x *= -1 : x);
}

float	ft_cosinus(float x)
{
	float	e;
	int		c;
	int		n;
	float	cos;

	e = 0.001;
	c = 1;
	n = -2;
	cos = 0;
	while ((ft_power_float(x, (n + 1)) / ft_fact(n + 1)) >= e)
	{
		cos += c *(ft_power_float(x, (n + 2)) / ft_fact(n + 2));
		c *= -1;
		n += 2;
	}
	return (cos);
}

float	ft_sinus(float x)
{
	float	res;
	float	coeff;
	int		i;

	res = 1;
	x = (x - 6.28) * (x / 6.28);
	i = 2;
	coeff = 1;
	while (ft_abs(coeff) > 0.01)
	{
		coeff = (-coeff * (x * x) / (i * (i + 1)));
		res += coeff;
		i += 2;
	}
	return (x *res);
}

float	ft_power_float(float a, float b)
{
	int		i;
	float	c;

	i = 0;
	c = 1;
	if (a != 0 && b > 0)
	{
		while (i < b)
		{
			c = c * a;
			i++;
		}
	}
	else if ( a != 0 && b < 0)
	{
		while (i < (-b))
		{
			c = c * (1 / a);
			i++;
		}
	}
	else if (b == 0)
		c = 1;
	return (c);
}

float	ft_fact(int n)
{
	float	fact;
	int		i;

	fact = 1;
	i = 1;
	if (n == 0)
		fact = 1;
	else
	{
		while (i <= n)
		{
			fact *= i;
			i++;
		}
	}
	return (fact);
}
