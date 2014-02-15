/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 11:02:25 by rgary             #+#    #+#             */
/*   Updated: 2014/02/15 14:57:53 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "rtv1.h"

#include <stdio.h>

int		key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 65307)
		exit (1);
	return (0);
}

void	file_error(char *s, char *s2)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(s2, 2);
	write(2, "\n", 1);
	exit(-1);
}

t_mlx	*store_mlx(t_mlx *mlx)
{
	static t_mlx	*save = NULL;

	if (save == NULL)
		save = mlx;
	return (save);
}

t_cam	*store_cam(t_cam *cam)
{
	static t_cam	*save = NULL;

	if (save == NULL)
		save = cam;
	return (save);
}

int		main(int ac, char **av)
{
	t_cam	*cam;
	t_obj	*lst;
	t_mlx	*mlx;
	t_all	*all;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	if (((mlx->mlx = mlx_init()) == NULL)
		|| ((mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT
									, "0")) == NULL))
		return (0);
	mlx = store_mlx(mlx);
	if (ac != 2)
	{
		write(2, "Argument error.\nUsage : ./rtv1 file.scn\n", 40);
		exit(-1);
	}
	lst = NULL;
	lst = get_obj_from_file(av[1]);
	cam = store_cam(NULL);
	all = build_all(mlx, cam, lst);
	calc_rays(cam, lst);
	mlx_key_hook(mlx->win, &key_hook, mlx);
	mlx_expose_hook(mlx->win, &expose_hook, all);
	mlx_loop(mlx->mlx);
	return (0);
}
