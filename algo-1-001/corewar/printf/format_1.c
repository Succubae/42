/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 19:41:40 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/17 19:41:43 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"
#include "libft.h"

int		set_argnb(t_format **format, int i, char *s)
{
	int		j;
	char	*carg_nb;

	j = i;
	while (s[j] && (s[j] != ARG_N))
		j++;
	if (j == i)
		invalid_format();
	if (s[j] == ARG_N)
	{
		carg_nb = ft_strsub(s, i, (j - i));
		if (carg_nb == NULL)
			impossible_malloc("arg_nb");
		(*format)->arg_nb = ft_atoi(carg_nb);
		free(carg_nb);
		return (j);
	}
	return (i);
}

int		set_flags(t_format **format, int i, char *s)
{
	char	*flag_list;

	while (ft_strchr(FLAG, s[i]) != NULL)
		i++;
	if (i == 1)
		invalid_format();
	flag_list = ft_strsub(s, 1, (i - 1));
	if (!flag_list)
		impossible_malloc("flag_list");
	update_flags(format, flag_list);
	if (!(*format)->f_list)
		impossible_malloc("flag_list2");
	free(flag_list);
	return (i);
}

int		set_minwidth(t_format **format, int i, char *s)
{
	int		j;
	char	*min_width;

	j = i;
	while (ft_isdigit(s[j]))
		j++;
	if (j == i)
		invalid_format();
	min_width = ft_strsub(s, i, (j - i));
	if (!min_width)
		impossible_malloc("min_width");
	(*format)->m_width = ft_atoi(min_width);
	free(min_width);
	return (j);
}

int		set_precision(t_format **format, int i, char *s)
{
	int		j;
	char	*precision;

	j = i + 1;
	while (ft_isdigit(s[j]))
		j++;
	if (j == (i + 1))
		invalid_format();
	precision = ft_strsub(s, i, (i - j));
	if (!precision)
		impossible_malloc("precision");
	(*format)->preci = ft_atoi(precision);
	free(precision);
	return (j);
}

void	set_lenmod(t_format **format, int i, char *s)
{
	char	*len_mod;
	int		j;

	j = i + 1;
	while (ft_strchr(MOD, s[j]) != NULL)
		j++;
	if (j == (i + 1))
		invalid_format();
	len_mod = ft_strsub(s, 1, (i - 1));
	if (!len_mod)
		impossible_malloc("len_mod");
	(*format)->l_mod = ft_strdup(len_mod);
	if (!(*format)->l_mod)
		impossible_malloc("len_mod2");
	free(len_mod);
}