/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 15:59:01 by sbuono            #+#    #+#             */
/*   Updated: 2013/12/15 13:56:13 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "hotrace.h"

F*tab[96] = {ret_space, ret_excl, ret_quote,
			 ret_num, ret_dollar, ret_percent, ret_and, ret_quote, ret_op,
			 ret_cp, ret_star, ret_plus, ret_coma, ret_minus, ret_point,
			 ret_slash, ret_zero, ret_one, ret_two, ret_three, ret_four,
			 ret_five, ret_six, ret_seven, ret_eight, ret_nine, ret_dbpoint,
			 ret_pointcoma, ret_left, ret_equal, ret_right, ret_inter, ret_arob,
			 ret_A, ret_B, ret_C, ret_D, ret_E, ret_F, ret_G, ret_H, ret_I,
			 ret_J, ret_K, ret_L, ret_M, ret_N, ret_O, ret_O, ret_P, ret_Q,
			 ret_R, ret_S, ret_T, ret_U, ret_V, ret_W, ret_X, ret_Y, ret_Z,
			 ret_oc, ret_backslash, ret_cc, ret_up, ret_under, ret_accent, 
			 ret_a, ret_b, ret_c, ret_d, ret_e, ret_f, ret_g, ret_h, ret_i, 
			 ret_j, ret_k, ret_l, ret_m, ret_n, ret_o, ret_p, ret_q, ret_r,
			 ret_s, ret_t, ret_u, ret_v, ret_w, ret_x, ret_y, ret_z, ret_ov,
			 ret_pipe, ret_cv, ret_tild};

void	make_tree(t_ascii *node, const char *line, int nb)
{
	t_ascii		**tmp;

	while (line[nb] != 0)
	{
		tmp = tab[line[nb] - 32](node);
		if (*tmp == NULL)
			*tmp = make_node();
		node = *tmp;
		++nb;
	}
	get_next_line(0, &(node->result));
}

void	search_value(t_ascii *node, char *line)
{
	int			nb;
	t_ascii		**tmp;

	nb = 0;
	while (line[nb] != 0)
	{
		tmp = tab[line[nb] - 32](node);
		if (*tmp != NULL)
			node = *tmp;
		++nb;
	}
	if (node->result == NULL)
	{
		write(1, line, nb);
		write(1, ": Not found.\n", 13);
	}
	else
		ft_putstrendl(node->result);
}

void	get_values(t_ascii *root)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		search_value(root, line);
	}
}

int		main(void)
{
	char	*line;
	t_ascii	*root;

	root = make_node();
	while (get_next_line(0, &line) > 0)
	{
		if (*line)
			make_tree(root, line, 0);
		else
			get_values(root);
	}
	
	return (0);
}
