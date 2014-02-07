/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:36:57 by rgary             #+#    #+#             */
/*   Updated: 2013/12/13 10:58:13 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbrl(int n)
{
	if ((n > -2147483648) && (n <= 2147483647))
	{
		if (n < 0)
		{
			ft_putchar('-');
			ft_putnbr(n * -1);
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		if (n >= 0 && n <= 9)
		{
			ft_putchar(n + 48);
		}
		ft_putchar('\n');
	}
	else if (n == -2147483648)
		ft_putendl("-2147483648");
	else
		ft_putendl("Error, number out of int range");
}
