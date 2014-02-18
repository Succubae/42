/*
** graph.c for g in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Tue Apr  6 15:09:29 2010 jerome ceccato
** Last update Fri Apr  9 10:45:07 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"

t_graph		*gr_add_node(t_graph *g, char *name, unsigned int flag)
{
  if (!gr_exist_node(g->graph, name))
    {
      g->graph = new_list(new_node(my_strdup(name), flag), g->graph);
      g->nnode++;
    }
  else
    gr_error(GR_W_NODEEXIST, name);
  return (g);
}

t_graph		*gr_add_link(t_graph *g, char *n1, char *n2)
{
  t_node	*p[2];

  p[0] = gr_get_node(g->graph, n1);
  p[1] = gr_get_node(g->graph, n2);
  if (!p[0] || !p[1])
    return (g + gr_error(GR_W_LNFAIL, n1, n2));
  if (!gr_exist_link(p[0]->link, p[1]))
    p[0]->link = new_link(p[1], p[0]->link);
  else
    gr_error(GR_W_LNEXIST, n1, n2);
  if (!gr_exist_link(p[1]->link, p[0]))
    p[1]->link = new_link(p[0], p[1]->link);
  else
    gr_error(GR_W_LNEXIST, n2, n1);
  g->nlink++;
  return (g);
}

t_node		*gr_get_node(t_list *lst, char *name)
{
  while (lst)
    {
      if (lst->data && !my_strcmp(NODE(lst->data)->name, name))
	return (lst->data);
      lst = lst->next;
    }
  return (NULL);
}

int		gr_exist_node(t_list *lst, char *name)
{
  return (gr_get_node(lst, name) != NULL);
}

int		gr_exist_link(t_link *link, t_node *p)
{
  while (link)
    {
      if (link->data == p)
	return (1);
      link = link->next;
    }
  return (0);
}
