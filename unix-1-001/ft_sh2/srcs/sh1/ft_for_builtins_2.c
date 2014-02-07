/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_builtins_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 17:32:19 by rgary             #+#    #+#             */
/*   Updated: 2014/01/16 10:30:16 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

char	*ft_slice_and_dice(char *jn, int *i, int *k)
{
	int		j;

	j = 0;
	if (jn[*i + 1] == '.')
	{
		while (jn[*i - 2 - j] != '/' && (*i - 2 - j) > 0)
			j++;
		if ((*i - 2 - j) > -1)
			jn = JOIN(SUB(jn, 0, *i - 2 - j), SUB(jn, *i + 2, 300));
		else
			jn = JOIN(ft_strsub(jn, 0, *i), ft_strsub(jn, *i + 3, 300));
		*k += 1;
	}
	else if (jn[*i + 1] == '/')
	{
		jn = JOIN(ft_strsub(jn, 0, *i - 1), ft_strsub(jn, *i + 1, 300));
		*k += 1;
	}
	return (jn);
}

char	*ft_cleanup_pwd(char *jn)
{
	int		i;
	int		j;
	int		k;

	i = j = 0;
	k = 1;
	while (k > 0)
	{
		i = j = k = 0;
		while (jn[i] != '\0')
		{
			while (jn[i] != '.' && jn[i] != '\0')
				i++;
			jn = ft_slice_and_dice(jn, &i, &k);
			i++;
		}
	}
	return (jn);
}

int		ft_check_var_exist(char *varname, char **env)
{
	if (ft_getenv(varname, env) == NULL)
		return (0);
	else
		return (1);
}
