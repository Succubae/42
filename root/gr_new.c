/*
** gr_new.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Tue Apr  6 16:41:36 2010 jerome ceccato
** Last update Wed Apr 14 20:31:12 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"

t_node		*new_node(char *name, unsigned int flag)
{
  t_node	*new;

  new = gr_malloc(sizeof(*new));
  new->name = name;
  new->state = flag;
  new->n = 0;
  new->link = NULL;
  return (new);
}

t_link		*new_link(t_node *node, t_link *next)
{
  t_link	*new;

  new = gr_malloc(sizeof(*new));
  new->data = node;
  new->next = next;
  return (new);
}

t_graph		*gr_create(void)
{
  t_graph	*new;

  new = gr_malloc(sizeof(*new));
  new->graph = NULL;
  new->nnode = 0;
  new->nlink = 0;
  return (new);
}
