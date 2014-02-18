/*
** lemin.h for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Tue Apr  6 17:33:39 2010 jerome ceccato
** Last update Wed Apr 21 13:38:46 2010 jerome ceccato
*/

#ifndef		__LEMIN_H__
# define	__LEMIN_H__

# define	FLAGS_NO	0x00u
# define	FLAGS_ANT	0x01u
# define	FLAGS_START	0x02u
# define	FLAGS_END	0x04u
# define	FLAGS_TRAVELED	0x08u
# define	FLAGS_DONE	0x10u

# define	STR_START1	"##start"
# define	STR_START2	"##home"
# define	STR_END		"##end"

# define	COMMENT_CHAR	'#'

typedef struct	s_data
{
  t_graph	*g;
  t_list	*sorted;
  t_node	*start;
  int		nants;
}		t_data;

int		getnbr(char *s);
int		my_strcmp(const char *s1, const char *s2);
int		my_linecmp(char *line, char *s);
int		my_isspace(char c);
char		*my_strchr(char *s, char c);
char		*my_strpbrk(char *s, char *charset);
char		*my_strdup(const char *s);
int		my_strlen(const char *s);

void		read_infos(t_data *data);
void		lem_in(t_data *data, t_list *tmp);
void		disp_move(t_node *a);
int		update_way(t_list *lst, int *npassed, int *nants, int totalants);
t_list		*gr_find_shortest_way(t_graph *g, t_node *start);
void		free_sorted(t_list *s);
void		lem_in_proceed(t_data *data);

#endif		/* __LEMIN_H__ */
