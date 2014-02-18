/*
** main.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Tue Apr  6 16:54:18 2010 jerome ceccato
** Last update Wed Apr 21 13:42:10 2010 jerome ceccato
*/

#include <stdlib.h>
#include <unistd.h>
#include "graph.h"
#include "lemin.h"

int		main(void)
{
  t_data	data;
  t_list	*tmp;

  data.g = gr_create();
  read_infos(&data);
  data.sorted = NULL;
  if (!(data.start = find_node(data.g->graph, FLAGS_START)))
    {
      gr_error(GR_E_NOSTART);
      gr_free(data.g);
      return (1);
    }
  apply_on_nodes(data.g->graph, setflag_untraveled);
  while ((tmp = gr_find_shortest_way(data.g, data.start)) && (size_list(tmp) > 2))
    {
      data.sorted = append_list(data.sorted, tmp);
      apply_on_nodes(data.g->graph, setflag_untraveled);
      apply_on_nodes(tmp, setflag_done);
    }
  lem_in(&data, tmp);
  free_sorted(data.sorted);
  gr_free(data.g);
  return (0);
}

void		lem_in(t_data *data, t_list *tmp)
{
  int		i;

  if (!data->sorted && (size_list(tmp) <= 2))
    {
      i = 0;
      while (++i <= data->nants)
	{
	  NODE(tmp->next->data)->n = i;
	  disp_move(tmp->next->data);
	}
      disp_move(NULL);
    }
  else
    lem_in_proceed(data);
}

void		lem_in_proceed(t_data *data)
{
  int		npassed;
  int		nants;
  t_list	*tmp;

  if (data->sorted)
    {
      npassed = 0;
      nants = data->nants;
      while ((npassed < data->nants) && data->sorted)
	{
	  tmp = data->sorted;
	  while (tmp)
	    {
	      update_way(tmp->data, &npassed, &nants, data->nants);
	      tmp = tmp->next;
	    }
	  disp_move(NULL);
	}
    }
  else
    gr_error(GR_E_NOEND);
}
