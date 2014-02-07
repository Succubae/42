/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 18:25:38 by mfaye             #+#    #+#             */
/*   Updated: 2013/12/09 18:25:41 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# include "libft.h"
# define START '%'
# define FLAG "#0- +"
# define MOD "hljtzqLv"
# define ARG_N '$'
# define NULL_STR "(null)"
# define FD_OUT 1

typedef struct	s_flags
{
	int	has_hashtag;
	int	has_zero;
	int	has_minus;
	int	has_space;
	int	has_plus;
}				t_flags;

typedef struct	s_format
{
	int				start;
	int				arg_nb;
	t_flags			*f_list;
	int				m_width;
	int				preci;
	char			*l_mod;
	char			conv;
	size_t			length;
	char			*format;
	int				has_star;
	struct s_format	*next;
}				t_format;

typedef int	(*t_func)(va_list *, t_format *);

typedef struct	s_conv
{
	char			conv;
	t_func			func;
	struct s_conv	*next;
}				t_conv;

void	add_conv(t_conv **, t_conv *);
void	add_c_func(t_conv **);
void	add_d_func(t_conv **);
void	add_o_func(t_conv **);
void	add_s_func(t_conv **);
void	add_u_func(t_conv **);
void	add_x_func(t_conv **);
void	apply_flags(char **, t_format *);

void	check_for_arg_nb(t_format *);
t_conv	*create_conv(char, t_func);

int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));
void	free_format(t_format *);
void	ft_strpad2(char **, size_t, t_paddir, char);
void	*ft_memcpy(void *, const void *, size_t);

t_func	get_conversion(t_format *);

void	handle_flags_for_d(char **, t_format *);

void	impossible_malloc(char *);
void	invalid_format(void);

void	kill_me(char *);

int		list_count(t_format *);
void	list_pushback(t_format **, t_format **);

void	not_unique_flag(char);

int		print_arg(va_list *, t_format *);

int		set_argnb(t_format **, int, char *);
int		set_flags(t_format **, int, char *);
void	set_lenmod(t_format **, int, char *);
int		set_minwidth(t_format **, int, char *);
int		set_precision(t_format **, int, char *);

void	update_flags(t_format **, char *);
#endif