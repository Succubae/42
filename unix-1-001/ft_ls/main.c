/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 12:12:04 by rgary             #+#    #+#             */
/*   Updated: 2013/12/14 18:35:33 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "ft_ls.h"

void	ft_do_noparams(char **argv)
{
	int			i;
	t_list2		*lnk;
	t_params	*p;

	lnk = NULL;
	i = 1;
	p = ft_do_by_params(argv, &i);
	lnk = ft_list_dir_content(lnk, "./", p);
	ft_print_list(lnk, p);
}

void	ft_do_only_params(t_params *p)
{
	t_list2		*lnk;
	t_stat		stats;

	lnk = NULL;
	if (stat(".", &stats) == -1)
	{
		ft_putstr("main error (if) : ");
		perror(".");
	}
	if (ft_find_type(stats.st_mode) != 'd')
		lnk = ft_build_list_file(".", lnk, ".", p);
	else if (ft_find_type(stats.st_mode) == 'd' && p->R == 0)
		lnk = ft_list_dir_content(lnk, ".", p);
	else if (ft_find_type(stats.st_mode) == 'd' && p->R == 1)
		ft_create_recursivity(".", p);
	ft_print_list(lnk, p);
}

void	ft_do_params_path(int i, t_params *p, char **argv, int argc)
{
	t_list2		*lnk;
	t_stat		stats;

	lnk = NULL;
	ft_sort_params_name(argv);
	ft_sort_params_type(argv);
	if (lstat(argv[i], &stats) == -1)
		perror(argv[i]);
	else
	{
		if (ft_find_type(stats.st_mode) == 'd' && p->R == 0)
		{
			if ((argc - i) > 1)
				p->round = 1;
			lnk = ft_list_dir_content(lnk, argv[i], p);
		}
		else if (ft_find_type(stats.st_mode) == 'd' && p->R == 1)
			ft_create_recursivity(argv[i], p);
		else
			lnk = ft_build_list_file(argv[i], lnk, argv[i], p);
		ft_print_list(lnk, p);
	}
}

int		main(int argc, char **argv)
{
	t_list2		*lnk;
	int			i;
	t_sizes		*sizes;
	t_params	*p;

	lnk = NULL;
	sizes = NULL;
	sizes = ft_build_sizes_list(sizes);
	i = 1;
	if (argc == 1)
		ft_do_noparams(argv);
	else if (argc > 1)
	{
		p = ft_do_by_params(argv, &i);
		if (i == argc)
			ft_do_only_params(p);
		while (i < argc)
		{
			ft_do_params_path(i, p, argv, argc);
			i++;
		}
	}
	return (0);
}
