/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:25:39 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 16:16:48 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

void	for_a_better_setenv(char **arg, char ***env, int i)
{
	char	*tmp;
	char	*tmp2;

	free((*env)[i]);
	tmp = ft_strjoin("=", arg[2]);
	tmp2 = ft_strjoin(arg[1], tmp);
	(*env)[i] = ft_strdup(tmp2);
	free(tmp);
	free(tmp2);
}

void	for_a_better_other(char **cmd)
{
	free(cmd[1]);
	free(cmd[2]);
	free(cmd[3]);
	free(cmd);
}
