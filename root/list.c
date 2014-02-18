/*
** list.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Fri Apr  9 10:45:24 2010 jerome ceccato
** Last update Mon Apr 12 14:31:14 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"

t_list		*llconvert(void *p)
{
  return (p);
}

t_list		*new_list(void *data, t_list *next)
{
  t_list	*new;

  new = gr_malloc(sizeof(*new));
  new->data = data;
  new->next = next;
  return (new);
}

t_list		*append_list(t_list *lst, void *new)
{
  if (lst == NULL)
    return (new_list(new, NULL));
  lst->next = append_list(lst->next, new);
  return (lst);
}

unsigned int	size_list(t_list *lst)
{
  unsigned int	i;

  i = 0;
  while (lst)
    {
      i++;
      lst = lst->next;
    }
  return (i);
}
