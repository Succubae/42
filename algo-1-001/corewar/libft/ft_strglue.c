/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strglue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 11:49:53 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/01 11:49:54 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strglue(char **split, char glue)
{
	int		i;
	int		nb_split;
	char	*out;
	char	*tmp;
	char	*tmp2;

	i = 0;
	out = ft_strdup("");
	nb_split = ft_countsplit(split);
	while (split[i])
	{
		tmp = (i > 0 && i < nb_split ? ft_strjoinc(out, glue) : ft_strdup(""));
		tmp2 = ft_strjoin(tmp, split[i]);
		i++;
		free(out);
		free(tmp);
		out = tmp2;
	}
	return (out);
}