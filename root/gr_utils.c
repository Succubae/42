/*
** gr_utils.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Tue Apr  6 16:43:15 2010 jerome ceccato
** Last update Mon Apr 12 18:14:15 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"
#include "lemin.h"

void		*gr_malloc(unsigned int len)
{
  void		*p;

  if (!(p = malloc(len)))
    {
      gr_error(GR_E_MALLOC);
      exit(1);
    }
  return (p);
}

int		apply_on_nodes(t_list *l, void (*fct)(t_node *))
{
  if (!l)
    return (0);
  fct(l->data);
  return (apply_on_nodes(l->next, fct));
}

t_node		*find_node(t_list *lst, unsigned int flag)
{
  while (lst)
    {
      if (NODE(lst->data)->state & flag)
	return (lst->data);
      lst = lst->next;
    }
  return (NULL);
}
