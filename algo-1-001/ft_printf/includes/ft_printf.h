/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 09:23:08 by rgary             #+#    #+#             */
/*   Updated: 2013/12/21 19:44:38 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include <wchar.h>

# define UCHAR unsigned char
# define USHORT unsigned short
# define UINT unsigned int
# define ULONG unsigned long

# define IS_N_CONVER str[i + j] != 'd' && str[i + j] != 'i' \
		&& str[i + j] != 'o' && str[i + j] != 'u' && str[i + j] != 'x' \
		&& str[i + j] != 'X' && str[i + j] != 'D' && str[i + j] != 'O' \
		&& str[i + j] != 'U' && str[i + j] != 'e' && str[i + j] != 'E' \
		&& str[i + j] != 'f' && str[i + j] != 'F' && str[i + j] != 'g' \
		&& str[i + j] != 'G' && str[i + j] != 'a' && str[i + j] != 'A' \
		&& str[i + j] != 'C' && str[i + j] != 'c' && str[i + j] != 'S' \
		&& str[i + j] != 's' && str[i + j] != 'p' && str[i + j] != 'n'
# define IS_NUM str[i + j] >= '1' && str[i + j] <= '9'
# define IS_STILL_NUM str[i + j] >= '0' && str[i + j] <= '9'
# define IS_FLAG str[i + j] == '#' || str[i + j] == '0' || str[i + j] == '-' \
		|| str[i + j] == ' ' || str[i + j] == '+' || str[i + j] == '\''
# define IS_LEN_MOD str[i + j] == 'h' || str[i + j] == 'l' \
		|| str[i + j] == 'j' || str[i + j] == 't' || str[i + j] == 'z' \
		|| str[i + j] == 'q' || str[i + j] == 'L'
# define CMP ft_strncmp

typedef struct		s_option
{
	int				field;
	char			*flag;
	char			separator;
	int				min_width;
	int				precision;
	char			*mod;
	char			conv;
	int				arg_size;
	struct s_option	*next;
}					t_op;

typedef struct	s_arg
{
	char			*str;
	long			i;
	unsigned long	ull;
	long			ps;
	struct s_arg	*next;
}				t_arg;

void			ft_putchar(char);
void			ft_putwchar(wchar_t c);
void			ft_putstr(const char*);
void			ft_putnbr(long);
void			ft_putunbr(unsigned long);
void			ft_putnbrl(int n);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
char			*ft_strsub(const char*, unsigned int, size_t);
char			*ft_strdup(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putendl(const char*);
int				ft_strncmp(const char *str, const char *str2, size_t n);
char			*ft_itoa(long);
char			*ft_uitoa(unsigned long);
int				ft_strichr(char *str, int l);

/* *ft_printf* */
int			ft_printf(const char *format, ...)
	__attribute__((format(printf, 1, 2)));

/* *ft_build_arg_list* */
t_arg			*ft_arg_list_push_back(t_arg *lnk, t_arg *new);
t_arg			*ft_build_arg_link_int(t_arg *lnk, va_list *ap);
t_arg			*ft_build_arg_link_uint(t_arg *lnk, va_list *ap);
t_arg			*ft_build_arg_link_charstar(t_arg *lnk, va_list *ap);
t_arg			*ft_build_arglst_conv(t_op*, va_list*, t_arg*, int);

/* *ft_print_out* */
int				ft_print_out_3(int *i, t_op *op, t_arg *lnk);
int				ft_print_out_2(int *i, t_op *op, char *str, t_arg *lnk);
int				ft_print_out(char*, int, t_op*, t_arg*);
int				ft_find_arg_count(char *str);

/* *ft_find_arg_params* */
int				ft_field_options(char *str, t_op*, int i);
int				ft_flag_options(char *str, t_op*, int i);
int				ft_width_options(char *str, t_op*, int i);
int				ft_precision_options(char *str, t_op*, int i);
int				ft_modifier_options(char *str, t_op*, int i);

/* *ft_build_options_list.c* */
t_op			*ft_build_list(t_op*, char *str, int *i, int);
t_op			*ft_list_push_back(t_op*, t_op*);
t_op			*ft_build_options_struct_spe(t_op *op);
t_op			*ft_build_options_struct(t_op*);
t_op			*ft_analyse_str(char *str, t_op*);
int				ft_converter_options(char *str, t_op*, int i);

/* *ft_deal_with_types_and_conversion* */
void			ft_deal_with_hexa_conversion_2(t_op *op, t_arg *lnk);
void        	ft_deal_with_int_conversion_part2(t_op *op, t_arg *lnk);
void			ft_deal_with_int_conversion_part1(t_op *op, t_arg *lnk);
void            ft_deal_with_uint_conversion_part1(t_op *op, t_arg *lnk);
void			ft_deal_with_uint_conversion(t_op *op, t_arg *lnk);
void			ft_deal_with_octal_conversion(t_op *op, t_arg *lnk);
void			ft_deal_with_hexa_conversion(t_op *op, t_arg *lnk);
void			ft_deal_with_types_and_conversion(t_op*, t_arg *lnk);
void			ft_deal_with_types_and_conversion_2(t_op *op, t_arg *lnk);
void			ft_deal_with_types_and_conversion_3(t_op *op, t_arg *lnk);

/* *ft_build_padding* */
char			*ft_itoa_by_type(char *str, t_op *op, t_arg *lnk);
char			*ft_itoa_by_type(char *str, t_op *op, t_arg *lnk);
void			ft_place_zeros(t_op *op, t_arg *lnk, int);
void			ft_place_spaces(t_op *op, t_arg *lnk, int);
void			ft_create_padding(t_op *op, t_arg *lnk);

/* *ft_conversion_base_x* */
char			*ft_convert_to_octal(unsigned long n);
char			*ft_convert_to_hexa(unsigned long n, char conv);

#endif
