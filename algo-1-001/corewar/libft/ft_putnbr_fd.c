/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 10:55:08 by sbuono            #+#    #+#             */
/*   Updated: 2014/01/08 10:59:19 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if ((n / 10) != 0)
			ft_putnbr_fd(((n / 10) * -1), fd);
		ft_putnbr_fd(((n % 10) * -1), fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar_fd((n + 48), fd);
	}
}
