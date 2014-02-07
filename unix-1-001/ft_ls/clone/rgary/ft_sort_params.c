/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 10:43:55 by rgary             #+#    #+#             */
/*   Updated: 2013/12/09 10:46:59 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void		ft_sort_params_name(char **argv)
{
	int	i;
	int	save;
	int	cnt;

	i = 1;
	while (argv[i][0] == '-')
		i++;
	save = i;
	cnt = 1;
	while (cnt == 1)
	{
		cnt = 0;
		i = save;
		while (argv[i] && argv[i + 1])
		{
			if ((ft_strcmp(argv[i], argv[i + 1]) > 0))
			{
				ft_switch_elem(&argv[i], &argv[i + 1]);
				cnt = 1;
			}
			i++;
		}
	}
}

void		ft_sort_params_type(char **argv)
{
	int	i;
	int	cnt;
	int	save;

	i = 1;
	while (argv[i][0] == '-')
		i++;
	save = i;
	cnt = 1;
	while (cnt == 1)
	{
		cnt = 0;
		i = save;
		cnt = ft_test_type(argv, &i, cnt);
	}
}
