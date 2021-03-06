/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:26:01 by rgary             #+#    #+#             */
/*   Updated: 2013/12/12 12:17:56 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
