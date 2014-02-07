/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_ls.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rgary <rgary@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2013/11/27 16:49:58 by rgary			 #+#	#+#			 */
/*   Updated: 2013/12/14 18:48:24 by rgary            ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#ifndef FT_LS_H
# define FT_LS_H
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

# define DN dp->d_name
# define ft_pad ft_padding
# define SORT_NAME 0
# define SORT_TIME 1
# define SORT_R_NAME 2
# define SORT_R_TIME 3
# define S_UID(m) (((m) & S_ISUID) == S_ISUID)
# define S_GID(m) (((m) & S_ISGID) == S_ISGID)
# define S_VTX(m) (((m) & S_ISVTX) == S_ISVTX)


typedef struct		tm		t_tm;

typedef struct		dirent	t_dirent;

typedef struct		stat	t_stat;

typedef struct		group	t_group;

typedef struct		passwd	t_passwd;

typedef struct		s_list2
{
	char				*right;
	char				*owner;
	char				*group;
	char				*name;
	char				*time;
	char				*link;
	char				*size;
	char				*major;
	char				*minor;
	int					blk;
	long				timestamp;
	struct s_list2		*next;
	struct s_list2		*prev;
}					t_list2;

typedef struct		s_list3
{
	int		right;
	int		owner;
	int		group;
	int		name;
	int		link;
	int		size;
	int		major;
	int		minor;
	int		time;
}					t_sizes;

typedef struct		s_list4
{
	int		l;
	int		a;
	int		r;
	int		R;
	int		t;
	int		round;
}					t_params;

typedef struct		s_list5
{
	t_list2			*content;
	t_list2			*dirlist;
}					t_recurs;

typedef struct		s_list6
{
	t_list2			*dir;
	struct s_list6	*next;
}					t_recurs2;

/*
**main
*/
void		ft_do_noparams(char**);
void		ft_do_only_params(t_params *p);
void		ft_do_params_path(int i, t_params *p, char **argv, int argc);

/*
**ft_create_dir_content_list
*/
t_list2		*ft_lst_push_back_dir(t_list2*, t_list2*);
t_list2		*ft_lstnew_dir(const char*, t_list2*);
t_list2		*ft_build_list(char*, t_list2*, char*, t_params*);
t_list2		*ft_list_dir_content(t_list2*, char*, t_params*);

/*
**ft_create_dirlist_content_list
*/
t_list2		*ft_lst_push_back_dirlist(t_list2 *lnk, t_list2 *new);
t_list2		*ft_build_dirlist(char *str, t_list2 *lnk);

/*
**ft_create_file_content_list
*/
t_list2		*ft_build_list_file(char*, t_list2*, char*, t_params*);
void		ft_change_link_name(char*, t_stat*, t_list2*);
t_list2		*ft_fill_stats_file(t_list2*, char*, t_params*);

/*
**ft_do_by_params
*/
t_params	*ft_build_params_struct(t_params *p);
void		ft_argv_error(char **argv, int *i, int j);
t_params	*ft_do_by_params(char **argv, int *i);
int			ft_test_type(char**, int*, int);
void		ft_switch_elem(char **s1, char **s2);

/*
**ft_sort_params
*/
void		ft_sort_params_name(char **argv);
void		ft_sort_params_type(char **argv);

/*
**ft_fill_stats
*/
t_stat		*ft_create_stat_struct(void);
void		ft_find_time(t_list2*, t_stat*, char*);
void		ft_fill_r_l_t(t_list2*, t_stat*, char*, t_params*);
char		*ft_build_dirname(t_list2 *lnk, char *dir);
t_list2		*ft_fill_stats(t_list2*, char*, t_params*);

/*
**ft_find_info_stats
*/
char		ft_find_type(int st_mode);
char		*ft_find_right(t_stat*, char*, char*);
void		ft_fill_params_struct(char **argv, t_params *p, int i, int j);

/*
**ft_pad_stats
*/
t_sizes		*ft_build_sizes_list(t_sizes*);
void		ft_define_padding_elem(t_list2*, t_sizes*, t_params*);
void		ft_padding_elem(t_list2*, t_sizes*, t_params*);

/*
**ft_sort_list
*/
int			ft_list_elem_cmp(char*, char*);
t_list2		*ft_sort_list_elem(t_list2*, int);
t_list2		*ft_sort_name(t_list2*, t_list2*, t_list2*, t_list2*);
t_list2		*ft_list_switch(t_list2*, t_list2*);
t_list2		*ft_sort_r_name(t_list2*, t_list2*, t_list2*, t_list2*);

/*
**ft_sort_list_time
*/
t_list2		*ft_sort_time(t_list2*, t_list2*, t_list2*, t_list2*);
t_list2		*ft_sort_r_time(t_list2*, t_list2*, t_list2*, t_list2*);

/*
**ft_recursivity
*/
t_recurs	*ft_btree(t_dirent*, t_recurs*, char *dir, t_params*);
t_recurs	*ft_create_tree(t_recurs *recurs);
void		ft_print_error_permission(char *dir);
void		ft_print_dir_name(char*, t_params*);
void		ft_create_recursivity(char *dir, t_params*);

/*
**ft_print_by_params
*/
t_list2		*ft_sort_list(t_list2*, t_params*);
void		ft_print_hidden_file(t_list2*, t_params*);
void		ft_print_blk(t_list2 *lnk, int blkcnt, t_params *p);
void		ft_print_list(t_list2*, t_params*);
void		ft_print_list_recurs(t_list2*, t_params*, char*);

/*
**ft_print_info
*/
void		ft_print_dev_info(t_list2 *lnk);
void		ft_print_info(t_list2*);
void		ft_print_color(t_list2*);
void		ft_print_file(t_list2*, t_params*);

#endif
