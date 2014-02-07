/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 15:22:47 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 16:39:57 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

void	ft_error_unsetenv(char *s)
{
	FP2("Minishell: Unsetenv error: Unable to remove variable \"", 2);
	FP2(s, 2);
	FP2("\"\n", 2);
	FP2("Minishell: Check for variable name in \"env\"\n", 2);
}

void	ft_error_chdir(char *s)
{
	FP2("Minishell: cd error: Can not access \"", 2);
	FP2(s, 2);
	FP2("\"\n", 2);
}

void	ft_error_malloc(char *s)
{
	FP2("Minishell: Malloc error: Unable to ", 2);
	FP2(s, 2);
	FP2(".\n", 2);
	exit(-1);
}

void	ft_error(char *s)
{
	FP2("Minishell: ", 2);
	FP2(s, 2);
	FP2(".\n", 2);
}

void	ft_error_exit(char *s)
{
	FP2("Minishell: ", 2);
	FP2(s, 2);
	FP2(".\n", 2);
	exit(0);
}
