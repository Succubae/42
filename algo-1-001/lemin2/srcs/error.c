/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 11:03:35 by rgary             #+#    #+#             */
/*   Updated: 2014/02/17 16:56:07 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

void	ft_error_1(char *s)
{
	ft_putendl_fd(s, 2);
	exit (-1);
}

void	ft_error_2(char *s, char *s2)
{
	ft_putstr_fd(s, 2);
	ft_putendl_fd(s2, 2);
	exit (-1);
}

void	ft_error_3(char *s, char *s2, char *s3)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(s2, 2);
	ft_putendl_fd(s3, 2);
	exit (-1);
}

void	ft_error_4(char *s, char *s2, char *s3, char *s4)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(s3, 2);
	ft_putendl_fd(s4, 2);
	exit (-1);
}
