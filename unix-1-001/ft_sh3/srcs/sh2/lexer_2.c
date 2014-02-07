/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:56:40 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 16:59:11 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

char	*remove_escape_char_from_stdchar(char *val)
{
	int		i;
	int		j;
	char	*new;

	i = j = 0;
	new = (char*)malloc(sizeof(char) * (ft_strlen(val) + 1));
	while (val[i] != '\0')
	{
		if (val[i] == '\\')
			i++;
		new[j] = val[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(val);
	return (new);
}

char	*remove_escape_char_from_quote(char *val)
{
	int		i;
	int		j;
	int		l;
	char	*new;

	i = j = 1;
	l = ft_strlen(val);
	new = (char*)malloc(sizeof(char) * (l + 1));
	new[0] = val[0];
	while (i < l)
	{
		if (val[i] == '\\')
			i++;
		new[j] = val[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(val);
	return (new);
}
