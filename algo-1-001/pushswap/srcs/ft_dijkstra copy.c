/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:47:33 by rgary             #+#    #+#             */
/*   Updated: 2013/12/26 19:24:20 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_sort_head	*ft_create_tsorthead_struct(t_sort *unsorted)
{
	t_sort_head	*new;

	new = (t_sort_head*)malloc(sizeof(t_sort_head));
	new->head = unsorted;
	new->next = NULL;
}

t_state		*ft_create_state_struct(t_sort *lnk, t_sort *unsort, t_state *state)
{
	if (state == NULL)
		state = (t_state*)malloc(sizeof(t_state));
	if (state->list == NULL)
		state->list = ft_create_tsorthead_struct(unsorted);
	else
	{
		while (state->list->next != NULL)
			state->list = state->list->next;
		state->list->next = ft_create_tsorthead_struct(unsorted);
	}
	state->obj = lnk;
	return (state);	
}

int			ft_compare_lists(t_sort *lnk, t_sort *lnk2)
{
	int		i;
	t_sort	*save;
	t_sort	*save2;

	i = -1;
	save = lnk;
	save2 = lnk2;
	while (lnk->val == lnk2->val && lnk != NULL && lnk2 != NULL)
	{
		lnk = lnk->next;
		lnk2 = lnk->next;
	}
	if (lnk == NULL && lnk2 == NULL)
		i = 0;
	else
		i = 1;
	lnk = save;
	lnk2 = save2;
	return (i);
}

char		*ft_add_operation(char *oldop, char *curop)
{
	int		i;
	int		j;
	int		l;
	char	*newop;

	i = j = l = 0;
	l = ft_strlen(oldop) + ft_strlen(curop) + 2;
	newop = (char*)malloc(sizeof(char) * l);
	while (oldop[i] != '\0')
	{
		newop[i] = oldop[i];
		i++;
	}
	newop[i] = ' ';
	while (curop[j] != '\0')
	{
		newop[i + j] = curop[j];
		j++;
	}
	newop[i + j] = '\0';
	return (newop);
}

void		ft_call_functions(t_sort *lnk, t_sort *unsorted, t_state *state)
{
	int		i;
	t_sort	new;
	t_func	*functions[11] = {ft_swap_a, ft_swap_b, ft_pick_b_to_a,\
							  ft_pick_a_to_b, ft_rotate_a, ft_rotate_b,\
							  ft_rotate_rev_a, ft_rotate_rev_b, ft_swap_both,\
							  ft_rotate_both, ft_rotate_rev_both};

	i = 0;
	if (state == NULL)
		state = ft_create_state_struct(lnk, new, state);
	while (i < 11)
	{
		new = ft_lst_map_unmod(unsorted);
		state = ft_create_state_struct(lnk, new, state);
		functions[i](new, state, functions);
		i++;
	}
}
