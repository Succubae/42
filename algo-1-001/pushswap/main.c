/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 11:51:57 by rgary             #+#    #+#             */
/*   Updated: 2013/12/27 12:38:09 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_print_operations(char *op)
{
	FP("%s\n", op);
}

void	ft_print_list(t_sort *lnk, t_sort *lnk_b)
{
	t_sort	*save;
	t_sort	*save_b;

	save = lnk;
	save_b = lnk_b;
	FP("-----START-----\n");
	while (lnk != NULL)
	{
		FP("lnk = %d\n", lnk->val);
		lnk= lnk->next;
	}
	while (lnk_b != NULL)
	{
		FP("lnk_b = %d\n", lnk_b->val);
		lnk_b = lnk_b->next;
	}
	FP("------END------\n");
	lnk = save;
	lnk_b = save_b;
}

int		main(int argc, char **argv)
{
	int		i;
	t_sort	*lnk;
	t_sort	*lnk_b;
	t_sort	*unsorted;
	t_state	*state;

	i = 0;
	lnk = NULL;
	lnk_b = NULL;
	unsorted = NULL;
	state = NULL;
	if (argc == 1)
	{
		FP("Push-Swap error: cannot sort an empty list\n");
		FP("Usage: push_swap [(-)0123456789 ...]\n");
	}
	else
	{
		while (++i < argc)
			lnk = ft_build_list_a(lnk, argv[i]);
		lnk_b = ft_create_empty(lnk_b);
		unsorted = ft_lstmap_unmod(lnk);
		ft_sort(&lnk);
		ft_call_f(lnk, unsorted, lnk_b, state);
/*		lnk_b = ft_cut_a(lnk, lnk_b);
		ft_print_list(lnk, lnk_b);
		lnk = ft_swap_a(lnk);
		ft_print_list(lnk, lnk_b);
		lnk = ft_pick_b_to_a(lnk, &lnk_b);
		ft_print_list(lnk, lnk_b);
		lnk = ft_rotate_a(lnk);
		ft_print_list(lnk, lnk_b);
		lnk = ft_rotate_rev_a(lnk);
		ft_print_list(lnk, lnk_b);
		lnk_b = ft_swap_b(lnk_b);
		ft_print_list(lnk, lnk_b);
		lnk_b = ft_pick_a_to_b(lnk_b, &lnk);
		ft_print_list(lnk, lnk_b);
		lnk_b = ft_rotate_b(lnk_b);
		ft_print_list(lnk, lnk_b);
		lnk_b = ft_rotate_rev_b(lnk_b);
		ft_print_list(lnk, lnk_b);*/
	}
	return (0);
}
