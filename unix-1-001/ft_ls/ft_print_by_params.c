/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_by_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 15:45:01 by rgary             #+#    #+#             */
/*   Updated: 2013/12/13 15:30:19 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

t_list2	*ft_sort_list(t_list2 *lnk, t_params *p)
{
	if (p->r == 1 && p->t == 0)
	{
		lnk = ft_sort_list_elem(lnk, SORT_R_NAME);
	}
	else if (p->t == 0)
	{
		lnk = ft_sort_list_elem(lnk, SORT_NAME);
	}
	if (p->t == 1)
	{
		if (p->r == 1)
		{
			lnk = ft_sort_list_elem(lnk, SORT_R_NAME);
			lnk = ft_sort_list_elem(lnk, SORT_R_TIME);
		}
		else
		{
			lnk = ft_sort_list_elem(lnk, SORT_NAME);
			lnk = ft_sort_list_elem(lnk, SORT_TIME);
		}
	}
	return (lnk);
}

void	ft_print_hidden_file(t_list2 *lnk, t_params *p)
{
	if (lnk->name[0] == '.' && p->a == 1)
	{
		if (p->l == 1)
		{
			ft_print_info(lnk);
		}
		else
		{
			ft_putendl(lnk->name);
		}
	}
}

void	ft_print_blk(t_list2 *lnk, int blkcnt, t_params *p)
{
	t_list2		*save;

	save = lnk;
	while (lnk)
	{
		if (lnk->name[0] == '.' && p->a == 1)
			blkcnt += lnk->blk;
		else if (lnk->name[0] != '.')
			blkcnt += lnk->blk;
		lnk = lnk->next;
	}
	lnk = save;
	if (p->l == 1 && lnk)
	{
		ft_putstr("total ");
		ft_putnbrl(blkcnt);
	}
}

void	ft_print_list(t_list2 *lnk, t_params *p)
{
	int			blkcnt;
	t_sizes		*sizes;

	sizes = NULL;
	blkcnt = 0;
	if (p->l == 1)
		ft_define_padding_elem(lnk, ft_build_sizes_list(sizes), p);
	lnk = ft_sort_list(lnk, p);
	ft_print_blk(lnk, blkcnt, p);
	while (lnk)
	{
		ft_print_hidden_file(lnk, p);
		ft_print_file(lnk, p);
		if (lnk->next != NULL)
			lnk = lnk->next;
		else
			break ;
	}
}

void	ft_print_list_recurs(t_list2 *lnk, t_params *p, char* dir)
{
	int			blkcnt;
	int			i;
	t_sizes		*sizes;

	sizes = NULL;
	i = ft_strirchr(dir, '/');
	if (dir[i + 1] == '.' && p->a == 0)
		;
	else
	{
		blkcnt = 0;
		if (p->l == 1)
			ft_define_padding_elem(lnk, ft_build_sizes_list(sizes), p);
		lnk = ft_sort_list(lnk, p);
		ft_print_blk(lnk, blkcnt, p);
		while (lnk)
		{
			ft_print_hidden_file(lnk, p);
			ft_print_file(lnk, p);
			if (lnk->next != NULL)
				lnk = lnk->next;
			else
				break ;
		}
	}
}
