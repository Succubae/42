/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 11:22:21 by rgary             #+#    #+#             */
/*   Updated: 2013/12/27 14:51:54 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf.h"
# include "libft.h"

# define FP ft_printf


typedef struct	s_list_arg
{
	int					val;
	struct s_list_arg	*next;
}				t_sort;

typedef struct	s_sort
{
	t_sort			*head;
	struct s_sort	*next;
}				t_sort_head;

typedef struct	s_state
{
	t_sort_head		*list;
	t_sort_head		*list_b;
	t_sort			*obj;
	char			*op;
}				t_state;
typedef int		(t_func)(t_sort**, t_sort**, t_state*);

/*
**ft compare
*/
int			ft_update_state(t_state*, t_sort *lnk, t_sort *lnk_b, int i);
int			ft_compare_other_states(t_sort*, t_sort *lnk_b, t_state *state);
/*
**ft dijkstra
*/
t_sort_head	*ft_create_tsorthead_struct(t_sort *unsorted);
t_state     *ft_create_state_struct(t_sort*, t_sort*, t_state*);
int			ft_compare_lists(t_sort*, t_sort*);
char		*ft_add_operation(char *oldop, char *curop);
void		ft_call_f(t_sort *lnk, t_sort*, t_sort*, t_state *state);
/*
**ft sort
*/
t_sort		*ft_sort_recurs(t_sort *start, t_sort *end);
void		ft_move_to_last(t_sort**, t_sort**, t_sort**);
t_sort		*ft_separate(t_sort*, t_sort *, t_sort**, t_sort**);
t_sort		*ft_get_last(t_sort *lnk);
void		ft_sort(t_sort **lnk);
/*
**ft lstmap unmod
*/
int			ft_sortlstcount(t_sort *lst);
t_sort		*ft_new_sortlnk(int i);
t_sort		*ft_lstmap_unmod(t_sort *lst);
/*
**ft operate on a
*/
int			ft_swap_a(t_sort**, t_sort**, t_state*);
int			ft_pick_b_to_a(t_sort**, t_sort**, t_state*);
int			ft_rotate_a(t_sort**, t_sort**, t_state*);
int			ft_rotate_rev_a(t_sort**, t_sort**, t_state*);
/*
**ft operate on b
*/
int			ft_swap_b(t_sort**, t_sort**, t_state*);
int			ft_pick_a_to_b(t_sort**, t_sort**, t_state*);
int			ft_rotate_b(t_sort**, t_sort**, t_state*);
int			ft_rotate_rev_b(t_sort**, t_sort**, t_state*);
/*
**ft operate on both
*/
t_sort		*ft_rotate_a_and_b(t_sort *lnk);
int			ft_rotate_both(t_sort**, t_sort**, t_state*);
t_sort		*ft_rotate_rev_a_and_b(t_sort *lnk);
int			ft_rotate_rev_both(t_sort**, t_sort**, t_state*);
/*
**ft swap both
*/
t_sort		*ft_swap_a_and_b(t_sort *lnk);
int			ft_swap_both(t_sort **lnk, t_sort **lnk_b, t_state *state);
/*
**ft cut a
*/
t_sort		*ft_cut_a(t_sort *lnk, t_sort *lnk_b);
/*
**ft build list a
*/
t_sort		*ft_sort_push_back(t_sort *lnk, t_sort *new);
t_sort		*ft_create_empty(t_sort *lnk);
t_sort		*ft_create_filled_lnk(t_sort *new, int i);
t_sort		*ft_build_list_a(t_sort*, char*);
/*
**main
*/
void		ft_print_operations(char*op);
void		ft_print_list(t_sort *lnk, t_sort *lnk_b);
int			main(int, char**);

# define FUNCTAB t_func  *g_funct[11] = {ft_swap_a, ft_swap_b,			\
										ft_pick_b_to_a, ft_pick_a_to_b,	\
										ft_rotate_a, ft_rotate_b,		\
										ft_rotate_rev_a,				\
										ft_rotate_rev_b,				\
										ft_swap_both, ft_rotate_both,	\
										ft_rotate_rev_both}

#endif
