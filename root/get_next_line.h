/*
** get_next_line.h for get_next_line in /home/justin_g/proj/GetNextLine
** 
** Made by guillaume justin
** Login   <justin_g@epitech.net>
** 
** Started on  Mon Nov 30 18:17:35 2009 guillaume justin
** Last update Wed Apr 21 12:02:48 2010 jerome ceccato
*/

#ifndef		__GNL_H__
# define	__GNL_H__

#define		BUF_SIZE 5000
#define		BUF_READ 5000

typedef struct	s_var
{
  char		*buffer;
  int		i;
  int		pos;
  int		nb_read;
}		t_var;

char		*get_next_line(const int fd);

#endif		/*__GNL_H__*/
