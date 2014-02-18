/*
** graph.h for g in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Tue Apr  6 15:09:37 2010 jerome ceccato
** Last update Wed Apr 14 20:30:57 2010 jerome ceccato
*/

#ifndef		__GRAPH_H__
# define	__GRAPH_H__

# define	GR_W_LNFAIL "Warning: Cannot create link between %s and %s\n"
# define	GR_W_LNEXIST "Warning: Link between %s and %s already exists\n"
# define	GR_W_NODEEXIST "Warning: Node already exists : %s\n"
# define	GR_E_MALLOC "Error: couldn't malloc\n"
# define	GR_E_NOSTART "Error: No starting node!\n"
# define	GR_E_NOEND "Error: No end\n"

# define	XCST(t, a) (t)a
# define	NODE(a) (XCST(t_node *, a))

typedef struct	s_link	t_link;
typedef struct	s_node	t_node;
typedef struct	s_list	t_list;
typedef struct	s_graph	t_graph;

struct		s_link
{
  t_node	*data;
  t_link	*next;
};

struct		s_node
{
  char		*name;
  unsigned int	state;
  int		n;
  t_link	*link;
};

struct		s_list
{
  void		*data;
  struct s_list	*next;
};

struct		s_graph
{
  t_list	*graph;
  int		nnode;
  int		nlink;
};

t_list		*llconvert(void *p);
t_list		*new_list(void *data, t_list *next);
t_list		*append_list(t_list *lst, void *new);
unsigned int	size_list(t_list *lst);

void		*gr_malloc(unsigned int sz);
int		apply_on_nodes(t_list *l, void (*fct)(t_node *));
t_node		*find_node(t_list *lst, unsigned int flag);

void		setflag_traveled(t_node *n);
void		setflag_untraveled(t_node *n);
void		setflag_done(t_node *n);

t_node		*new_node(char *name, unsigned int flag);
t_link		*new_link(t_node *node, t_link *next);
t_graph		*gr_create(void);

int		gr_error(const char *fmt, ...);

t_graph		*gr_add_node(t_graph *g, char *name, unsigned int flag);
t_graph		*gr_add_link(t_graph *g, char *n1, char *n2);
t_node		*gr_get_node(t_list *lst, char *name);
int		gr_exist_node(t_list *lst, char *name);
int		gr_exist_link(t_link *link, t_node *p);

t_node		*gr_free_node(t_node *n);
t_graph		*gr_free(t_graph *g);
int		free_list(t_list *lst);

int		my_strlen(const char *s);
int		my_strcmp(const char *s1, const char *s2);
char		*my_strdup(const char *s);

#endif		/* __GRAPH_H__ */
