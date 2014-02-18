/*
** gr_search.c for lem-in in /goinfre/epilem
** 
** Made by kevin de-carvalho
** Login   <de-car_k@epitech.net>
** 
** Started on  Mon Apr 12 13:53:55 2010 kevin de-carvalho
** Last update Wed Apr 14 21:05:01 2010 jerome ceccato
*/

#include	<stdlib.h>
#include	"graph.h"
#include	"lemin.h"

static int		is_connected(t_node *n, t_link *ln)
{
  while (ln)
    {
      if (ln->data->state & FLAGS_TRAVELED)
	if (ln->data == n)
	  return (1);
      ln = ln->next;
    }
  return (0);
}

static t_list		*back_trace_way(t_graph *g, t_node *end,
					t_list *save_way)
{
  t_node		*n;
  t_list		*tmp;

  if (!end)
    return (NULL);
  tmp = save_way;
  while (tmp)
    {
      if (is_connected(tmp->data, end->link))
	{
	  n = tmp->data;
	  free_list(tmp->next);
	  tmp->next = NULL;
	  if (n->state & FLAGS_START)
	    return (free_list(save_way) + new_list(n, new_list(end, NULL)));
	  return (append_list(back_trace_way(g, n, save_way), end));
	}
      tmp = tmp->next;
    }
  return (NULL);
}

static t_link	*loop_z(t_link *z, t_list *f)
{
  if (!(NODE(z->data)->state & (FLAGS_TRAVELED | FLAGS_DONE)))
    {
      setflag_traveled(z->data);
      f = append_list(f, z->data);
    }
  return (z->next);
}

t_list		*gr_find_shortest_way(t_graph *g, t_node *start)
{
  t_list	*f;
  t_list	*x;
  t_link	*z;
  t_list	*save_way;

  setflag_traveled(start);
  f = append_list(NULL, start);
  save_way = NULL;
  while (f)
    {
      x = f;
      z = NODE(x->data)->link;
      save_way = append_list(save_way, x->data);
      while (z && z->data)
	{
	  if (z->data->state & FLAGS_END)
	    return (free_list(f) + back_trace_way(g, z->data, save_way));
	  z = loop_z(z, f);
	}
      x = f->next;
      free(f);
      f = x;
    }
  return ((x = NULL) + free_list(f) + free_list(save_way));
}

