/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_stats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 16:32:17 by rgary             #+#    #+#             */
/*   Updated: 2013/12/15 10:15:36 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_sizes	*ft_build_sizes_list(t_sizes *sizes)
{
	sizes = (t_sizes*)malloc(sizeof(t_sizes));
	sizes->right = 0;
	sizes->owner = 0;
	sizes->group = 0;
	sizes->name = 0;
	sizes->link = 0;
	sizes->size = 0;
	sizes->major = 0;
	sizes->minor = 0;
	sizes->time = 0;
	return (sizes);
}

void	ft_fill_padding_struct(t_list2 *lnk, t_sizes *sizes)
{
	if (lnk->right && (int)ft_strlen(lnk->right) > sizes->right)
		sizes->right = ft_strlen(lnk->right);
	if (lnk->owner && (int)ft_strlen(lnk->owner) > sizes->owner)
		sizes->owner = ft_strlen(lnk->owner);
	if (lnk->group && (int)ft_strlen(lnk->group) > sizes->group)
		sizes->group = ft_strlen(lnk->group);
	if (lnk->link && (int)ft_strlen(lnk->link) > sizes->link)
		sizes->link = ft_strlen(lnk->link);
	if (lnk->size && (int)ft_strlen(lnk->size) > sizes->size)
		sizes->size = ft_strlen(lnk->size);
	if (lnk->major && (int)ft_strlen(lnk->major) > sizes->major)
		sizes->major = ft_strlen(lnk->major);
	if (lnk->minor && (int)ft_strlen(lnk->minor) > sizes->minor)
		sizes->minor = ft_strlen(lnk->minor);
}

void	ft_define_padding_elem(t_list2 *lnk, t_sizes *sizes, t_params *p)
{
	t_list2		*save;

	save = lnk;
	while (lnk && (p->l == 1))
	{
		if (lnk->right && lnk->owner && lnk->group && lnk->link && lnk->size
			&& lnk->major && lnk->minor)
		{
			if (lnk->name[0] == '.' && p->a == 0)
				;
			else
				ft_fill_padding_struct(lnk, sizes);
		}
		lnk = lnk->next;
	}
	lnk = save;
	ft_padding_elem(lnk, sizes, p);
}

void	ft_padding_elem(t_list2 *lnk, t_sizes *sizes, t_params *p)
{
	t_list2		*save;

	save = lnk;
	while (lnk)
	{
		if (lnk->name[0] == '.' && p->a == 0)
			;
		else if (p->l == 1)
		{
			if (lnk->right && lnk->owner && lnk->group && lnk->link && lnk->size
				&& lnk->major && lnk->minor)
			{
				lnk->right = ft_pad(lnk->right, sizes->right, PAD_RIGHT, ' ');
				lnk->link = ft_pad(lnk->link, sizes->link, PAD_LEFT, ' ');
				lnk->owner = ft_pad(lnk->owner, sizes->owner, PAD_RIGHT, ' ');
				lnk->group = ft_pad(lnk->group, sizes->group, PAD_RIGHT, ' ');
				lnk->size = ft_pad(lnk->size, sizes->size, PAD_LEFT, ' ');
				lnk->major = ft_pad(lnk->major, sizes->major, PAD_LEFT, ' ');
				lnk->minor = ft_pad(lnk->minor, sizes->minor, PAD_LEFT, ' ');
			}
		}
		lnk = lnk->next;
	}
	lnk = save;
}
