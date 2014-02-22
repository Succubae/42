/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 19:39:48 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/17 19:39:50 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"
#include "libft.h"

void	invalid_format(void)
{
	kill_me("Invalid format");
}

void	not_unique_flag(char flag)
{
	ft_putstr_fd("This flag is used more than once : [", 2);
	ft_putstr_fd(&flag, 2);
	ft_putstr_fd("]\n", 2);
	exit(1);
}