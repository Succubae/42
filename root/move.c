/*
** move.c for  in /home/ceccat_j/work/epilem
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Wed Apr 14 20:31:50 2010 jerome ceccato
** Last update Wed Apr 14 20:40:43 2010 jerome ceccato
*/

#include <stdlib.h>
#include <unistd.h>
#include "graph.h"
#include "lemin.h"

static void	my_putnbr(int n)
{
  char		buf[sizeof(int) << 3];
  int		i;

  i = 0;
  while (n)
    {
      buf[i++] = n % 10 + '0';
      n /= 10;
    }
  while (--i >= 0)
    write(1, buf + i, 1);
}

void		disp_move(t_node *a)
{
  static int	space = 0;

  if (!a)
    {
      if (space)
	write(1, "\n", 1);
      space = 0;
    }
  else
    {
      if (space)
	write(1, " ", 1);
      else
	space = 1;
      write(1, "P", 1);
      my_putnbr(a->n);
      write(1, "-", 1);
      write(1, a->name, my_strlen(a->name));
    }
}

int		update_way(t_list *lst, int *npassed, int *nants, int totalants)
{
  if (!lst || !lst->next)
    return (0);
  update_way(lst->next, npassed, nants, totalants);
  if (NODE(lst->data)->state & FLAGS_ANT)
    {
      NODE(lst->next->data)->state |= FLAGS_ANT;
      NODE(lst->next->data)->n = NODE(lst->data)->n;
      NODE(lst->data)->state &= ~FLAGS_ANT;
      disp_move(lst->next->data);
      if (NODE(lst->next->data)->state & FLAGS_END)
	(*npassed)++;
    }
  else if ((NODE(lst->data)->state & FLAGS_START) && (*nants > 0))
    {
      NODE(lst->next->data)->state |= FLAGS_ANT;
      NODE(lst->next->data)->n = totalants - (*nants)-- + 1;
      disp_move(lst->next->data);
      if (NODE(lst->next->data)->state & FLAGS_END)
	(*npassed)++;
    }
  return (0);
}
