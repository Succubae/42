/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 09:31:33 by rgary             #+#    #+#             */
/*   Updated: 2013/12/18 10:34:17 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int		key_hook(int keycode, t_all *all)
{
	(void)all;
	if (keycode == 65307)
		exit (1);
	else if (keycode == 65453)
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->win);
		all->height -= 2;
		ft_draw_horizontaly(all);
		ft_draw_verticaly(all);
	}
	else if (keycode == 65451)
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->win);
		all->height += 2;
		ft_draw_horizontaly(all);
		ft_draw_verticaly(all);
	}
	else
		key_hook_2(keycode, all);
	return (0);
}

void	key_hook_2(int keycode, t_all *all)
{
	if (keycode == 65463)
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->win);
		all->incl += 0.1;
		ft_draw_horizontaly(all);
		ft_draw_verticaly(all);
	}
	else if (keycode == 65465)
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->win);
		if (all->incl > 0.1)
			all->incl -= 0.1;
		ft_draw_horizontaly(all);
		ft_draw_verticaly(all);
	}
	else if (keycode == 65464)
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->win);
		all->roty += 1;
		ft_draw_horizontaly(all);
		ft_draw_verticaly(all);
	}
	else
		key_hook_3(keycode, all);
}

void	key_hook_3(int keycode, t_all *all)
{
	if (keycode == 65458)
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->win);
		all->roty -= 1;
		ft_draw_horizontaly(all);
		ft_draw_verticaly(all);
	}
	else if (keycode == 65460)
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->win);
		all->rotx += 1;
		ft_draw_horizontaly(all);
		ft_draw_verticaly(all);
	}
	else if (keycode == 65462)
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->win);
		all->rotx -= 1;
		ft_draw_horizontaly(all);
		ft_draw_verticaly(all);
	}
}

int		expose_hook(t_all *all)
{
	ft_draw_horizontaly(all);
	ft_draw_verticaly(all);
	return (0);
}
