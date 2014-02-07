/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_builtins_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 17:32:19 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 13:19:02 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

static char	*for_sad(char *jn, int *i, int *k)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	j = 0;
	while (jn[*i - 2 - j] != '/' && (*i - 2 - j) > 0)
		j++;
	if ((*i - 2 - j) > -1)
	{
		tmp = SUB(jn, 0, *i - 2 - j);
		tmp2 = SUB(jn, *i + 2, 300);
		free(jn);
		jn = JOIN(tmp, tmp2);
	}
	else
	{
		tmp = ft_strsub(jn, 0, *i);
		tmp2 = ft_strsub(jn, *i + 3, 300);
		free(jn);
		jn = JOIN(tmp, tmp2);
	}
	free(tmp);
	free(tmp2);
	*k += 1;
	return (jn);
}

char		*ft_slice_and_dice(char *jn, int *i, int *k)
{
	char	*tmp;
	char	*tmp2;

	if (jn[*i + 1] == '.')
		jn = for_sad(jn, i, k);
	else if (jn[*i + 1] == '/')
	{
		tmp = ft_strsub(jn, 0, *i - 1);
		tmp2 = ft_strsub(jn, *i + 1, 300);
		free(jn);
		jn = JOIN(tmp, tmp2);
		*k += 1;
	}
	else
		return (jn);
	return (jn);
}

char		*ft_cleanup_pwd(char *jn)
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
			if (i == (int)ft_strlen(jn))
				break ;
			jn = ft_slice_and_dice(jn, &i, &k);
			i++;
		}
	}
	return (jn);
}

int			ft_check_var_exist(char *varname, char **env)
{
	if (ft_getenv(varname, env) == NULL)
		return (0);
	else
		return (1);
}
