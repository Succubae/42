/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 10:52:53 by rgary             #+#    #+#             */
/*   Updated: 2013/12/09 13:50:09 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void	ft_print_dev_info(t_list2 *lnk)
{
	if (lnk->major && lnk->minor && lnk->size)
	{
		if (lnk->major[0] != '0')
		{
			ft_putstr(lnk->major);
			ft_putstr(" ");
			ft_putstr(lnk->minor);
		}
		else
			ft_putstr(lnk->size);
	}
}

void	ft_print_info(t_list2 *lnk)
{
	if (lnk->right && lnk->link && lnk->owner && lnk->group && lnk->time
		&& lnk->name)
	{
		ft_putstr(lnk->right);
		ft_putstr(" ");
		ft_putstr(lnk->link);
		ft_putstr(" ");
		ft_putstr(lnk->owner);
		ft_putstr("  ");
		ft_putstr(lnk->group);
		ft_putstr("  ");
		ft_print_dev_info(lnk);
		ft_putstr(" ");
		ft_putstr(lnk->time);
		ft_putstr(" ");
		ft_print_color(lnk);
	}
}

void	ft_print_color(t_list2 *lnk)
{
	if (lnk->right[0] == 'd')
	{
		ft_putstr("\033[34m");
		ft_putendl(lnk->name);
		ft_putstr("\033[0m");
	}
	else if(lnk->right[3] == 'x')
	{
		ft_putstr("\033[31m");
		ft_putendl(lnk->name);
		ft_putstr("\033[0m");
	}
	else
		ft_putendl(lnk->name);
}

void	ft_print_file(t_list2 *lnk, t_params *p)
{
	if (lnk->name[0] != '.')
	{
		if (p->l == 1)
			ft_print_info(lnk);
		else
			ft_putendl(lnk->name);
	}
}
