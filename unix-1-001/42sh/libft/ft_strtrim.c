/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:08:52 by cwagner           #+#    #+#             */
/*   Updated: 2014/01/08 11:12:36 by cwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_afterwhites(char *s)
{
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	return (s);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;

	ret = ft_strnew(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	ret = (char *) s;
	ret = ft_afterwhites(ret);
	ret = ft_strrev(ret);
	ret = ft_afterwhites(ret);
	ret = ft_strrev(ret);
	if (ft_strcmp(ret, "") == 0)
		return (NULL);
	return (ret);
}
