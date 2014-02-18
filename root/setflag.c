/*
** setflag.c for  in /home/ceccat_j/work/epilem
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Mon Apr 12 14:01:20 2010 jerome ceccato
** Last update Mon Apr 12 14:01:36 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"
#include "lemin.h"

void		setflag_traveled(t_node *n)
{
  n->state |= FLAGS_TRAVELED;
}

void		setflag_untraveled(t_node *n)
{
  n->state &= ~FLAGS_TRAVELED;
}

void		setflag_done(t_node *n)
{
  n->state |= FLAGS_DONE;
}
