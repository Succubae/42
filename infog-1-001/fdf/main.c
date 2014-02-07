/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 15:46:46 by rgary             #+#    #+#             */
/*   Updated: 2013/12/21 10:07:28 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

char	*ft_convert_to_hexa(int n)
{
	char            *s;
	int             i;
	unsigned long   k;

	k = n;
	i = 1;
	while ((n /= 10) != 0)
		i++;
	s = (char*)malloc(sizeof(char) * i + 1);
	ft_bzero(s, i + 1);
	s = s + i - 1;
	if (k == 0)
		*s = '0';
	while (k != 0)
	{
		*--s = ((k % 16) > 9 ? 'a' + ((k % 16) - 10) : (k % 16) + '0');
		k /= 16;
	}
	return (s);
}

char	*ft_create_color(int j, int l)
{
	char	*r;
	char	*g;
	char	*b;
	char	*color;

	r = ft_convert_to_hexa(j);
	g = ft_convert_to_hexa(l);
	b = ft_convert_to_hexa((j + l) / 2);
	color = ft_strjoin("0x", ft_strjoin(r, ft_strjoin(g, b)));
	return (color);
}

t_rot	*build_rot_struct(void)
{
	t_rot	*rot;

	rot = (t_rot*)malloc(sizeof(t_rot));
	rot->rotx = 45;
	rot->roty = 0;
	rot->rotz = 30;
	rot->sizex = 0;
	rot->sizey = 0;
	rot->centerx = WIND_X / 2;
	rot->centery = WIND_Y / 2;
	return (rot);
}

t_all	*build_all_in_one_struct(t_mlx *mlx, t_rot *rot, int **tab)
{
	t_all	*all;

	all = (t_all*)malloc(sizeof(t_all));
	all->mlx = mlx;
	all->rot = rot;
	all->tab = tab;
	all->height = 8;
	all->incl = 0.3;
	all->rotx = 10;
	all->roty = -5;
	return (all);
}

int		main(int argc, char**argv)
{
	t_mlx	*mlx;
	int		**tab;
	t_rot	*rot;
	t_all	*all;
	char 	title[] = "test 1";

	if (argc == 1)
	{
		ft_putendl("Usage = fdf [file]");
		exit (1);
	}
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIND_X, WIND_Y, title);
	rot = build_rot_struct();
	tab = ft_get_data(argv[1], rot);
	all = build_all_in_one_struct(mlx, rot, tab);
	mlx_key_hook(mlx->win, &key_hook, all);
	mlx_expose_hook(mlx->win, &expose_hook, all);
	mlx_loop(mlx->mlx);
	return (0);
}
