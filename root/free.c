/*
** free.c for  in /home/ceccat_j/work/epilem
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Thu Apr 15 10:50:20 2010 jerome ceccato
** Last update Thu Apr 15 10:58:05 2010 jerome ceccato
*/

#include <stdlib.h>
#include <unistd.h>
#include "graph.h"
#include "lemin.h"

void		free_sorted(t_list *s)
{
  t_list	*tmp;

  while (s)
    {
      tmp = s->next;
      free_list(s->data);
      free(s);
      s = tmp;
    }
}
