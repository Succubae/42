/*
** gr_free.c for g in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Tue Apr  6 16:40:31 2010 jerome ceccato
** Last update Thu Apr 15 10:50:53 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"

t_node		*gr_free_node(t_node *n)
{
  t_link	*tmp;

  free(n->name);
  while (n->link)
    {
      tmp = n->link->next;
      free(n->link);
      n->link = tmp;
    }
  free(n);
  return (NULL);
}

t_graph		*gr_free(t_graph *g)
{
  t_list	*tmp;

  while (g->graph)
    {
      tmp = g->graph->next;
      gr_free_node(g->graph->data);
      free(g->graph);
      g->graph = tmp;
    }
  free(g);
  return (NULL);
}

int		free_list(t_list *lst)
{
  t_list	*tmp;

  while (lst)
    {
      tmp = lst->next;
      free(lst);
      lst = tmp;
    }
  return (0);
}
