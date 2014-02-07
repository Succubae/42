/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_by_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:00:47 by rgary             #+#    #+#             */
/*   Updated: 2013/12/14 18:52:03 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include "ft_ls.h"

t_params		*ft_build_params_struct(t_params *p)
{
	p = (t_params*)malloc(sizeof(t_params));
	p->l = 0;
	p->a = 0;
	p->r = 0;
	p->R = 0;
	p->t = 0;
	p->round = 0;
	return (p);
}

void			ft_argv_error(char **argv, int *i, int j)
{
	if (argv[*i][j] != 'l' && argv[*i][j] != 'a'
		&& argv[*i][j] != 'r' && argv[*i][j] != 'R'
		&& argv[*i][j] != 't' && argv[*i][j] != '-')
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(argv[*i][j], 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: fls [-larRt] [file ...]", 2);
		exit (3);
	}
}

t_params		*ft_do_by_params(char **argv, int *i)
{
	int			j;
	t_params	*p;

	p = NULL;
	p = ft_build_params_struct(p);
	while (argv[*i] && argv[*i][0] == '-')
	{
		j = 0;
		while (argv[*i][j])
		{
			ft_fill_params_struct(argv, p, *i, j);
			ft_argv_error(argv, i, j);
			j++;
		}
		*i = *i + 1;
	}
	return (p);
}

int			ft_test_type(char **argv, int *i, int cnt)
{
	t_stat	stats;
	t_stat	stats2;

	while (argv[*i] && argv[*i + 1])
	{
		stat(argv[*i], &stats);
		stat(argv[*i + 1], &stats2);
		if (S_ISREG(stats.st_mode) < S_ISREG(stats2.st_mode))
		{
			ft_switch_elem(&argv[*i], &argv[*i + 1]);
			cnt = 1;
		}
		*i += 1;
	}
	return (cnt);
}

void		ft_switch_elem(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
