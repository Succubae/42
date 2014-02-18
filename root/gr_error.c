/*
** gr_error.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Tue Apr  6 15:48:40 2010 jerome ceccato
** Last update Tue Apr  6 17:13:44 2010 jerome ceccato
*/

#include <unistd.h>
#include <stdarg.h>
#include "graph.h"

int		gr_error(const char *fmt, ...)
{
  va_list	lst;
  char		*s;

  va_start(lst, fmt);
  while (*fmt)
    {
      if ((*fmt == '%') && (fmt[1] == 's'))
	{
	  s = va_arg(lst, char *);
	  write(2, s, my_strlen(s));
	  fmt++;
	}
      else
	write(2, fmt, 1);
      fmt++;
    }
  va_end(lst);
  return (0);
}
