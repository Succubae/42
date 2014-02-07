/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 15:22:47 by rgary             #+#    #+#             */
/*   Updated: 2013/12/24 12:53:50 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_sh1.h"

void	ft_error_unsetenv(char *s)
{
	FP("Minishell: Unsetenv error: Unable to remove variable \"%s\"\n", s);
	FP("Minishell: Check for variable name in \"env\"\n");
}

void	ft_error_chdir(char *s)
{
	FP("Minishell: cd error: Can not access \"%s\"\n", s);
}

void	ft_error_malloc(char *s)
{
	FP("Minishell: Malloc error: Unable to %s.\n", s);
	exit (-1);
}
