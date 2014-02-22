/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 12:37:24 by rgary             #+#    #+#             */
/*   Updated: 2014/02/22 11:23:03 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

void	create_prompt3(char *home, char *pwd, char *prompt, int j)
{
	int		i;

	i = 0;
	while (pwd[i] == home[i])
		i++;
	if (i != (int)ft_strlen(home))
		prompt = ft_strcat(prompt, pwd);
	else
		create_prompt2(pwd, prompt, i, j);
	free(home);
	free(pwd);
	print_prompt(prompt);
	free(prompt);
}
