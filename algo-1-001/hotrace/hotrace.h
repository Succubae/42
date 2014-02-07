s/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 15:59:01 by sbuono            #+#    #+#             */
/*   Updated: 2013/12/15 12:41:36 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

int		get_next_line(int const fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstrendl(char const *str);
void	ft_putstr(const char *s);

typedef	struct		s_ascii
{
	struct s_ascii	*zero;
	struct s_ascii	*one;
	struct s_ascii	*two;
	struct s_ascii	*three;
	struct s_ascii	*four;
	struct s_ascii	*five;
	struct s_ascii	*six;
	struct s_ascii	*seven;
	struct s_ascii	*eight;
	struct s_ascii	*nine;
	struct s_ascii	*A;
	struct s_ascii	*B;
	struct s_ascii	*C;
	struct s_ascii	*D;
	struct s_ascii	*E;
	struct s_ascii	*F;
	struct s_ascii	*G;
	struct s_ascii	*H;
	struct s_ascii	*I;
	struct s_ascii	*J;
	struct s_ascii	*K;
	struct s_ascii	*L;
	struct s_ascii	*M;
	struct s_ascii	*N;
	struct s_ascii	*O;
	struct s_ascii	*P;
	struct s_ascii	*Q;
	struct s_ascii	*R;
	struct s_ascii	*S;
	struct s_ascii	*T;
	struct s_ascii	*U;
	struct s_ascii	*V;
	struct s_ascii	*W;
	struct s_ascii	*X;
	struct s_ascii	*Y;
	struct s_ascii	*Z;
	struct s_ascii	*a;
	struct s_ascii	*b;
	struct s_ascii	*c;
	struct s_ascii	*d;
	struct s_ascii	*e;
	struct s_ascii	*f;
	struct s_ascii	*g;
	struct s_ascii	*h;
	struct s_ascii	*i;
	struct s_ascii	*j;
	struct s_ascii	*k;
	struct s_ascii	*l;
	struct s_ascii	*m;
	struct s_ascii	*n;
	struct s_ascii	*o;
	struct s_ascii	*p;
	struct s_ascii	*q;
	struct s_ascii	*r;
	struct s_ascii	*s;
	struct s_ascii	*t;
	struct s_ascii	*u;
	struct s_ascii	*v;
	struct s_ascii	*w;
	struct s_ascii	*x;
	struct s_ascii	*y;
	struct s_ascii	*z;
	struct s_ascii	*space;
	struct s_ascii	*excl;
	struct s_ascii	*quote;
	struct s_ascii	*num;
	struct s_ascii	*dollar;
	struct s_ascii	*percent;
	struct s_ascii	*and;
	struct s_ascii	*squote;
	struct s_ascii	*op;
	struct s_ascii	*cp;
	struct s_ascii	*star;
	struct s_ascii	*plus;
	struct s_ascii	*coma;
	struct s_ascii	*minus;
	struct s_ascii	*point;
	struct s_ascii	*slash;
	struct s_ascii	*dbpoint;
	struct s_ascii	*pointcoma;
	struct s_ascii	*left;
	struct s_ascii	*equal;
	struct s_ascii	*right;
	struct s_ascii	*inter;
	struct s_ascii	*arob;
	struct s_ascii	*oc;
	struct s_ascii	*backslash;
	struct s_ascii	*cc;
	struct s_ascii	*up;
	struct s_ascii	*under;
	struct s_ascii	*accent;
	struct s_ascii	*ov;
	struct s_ascii	*pipe;
	struct s_ascii	*cv;
	struct s_ascii	*tild;
	char			*result;
}					t_ascii;

typedef t_ascii** F(t_ascii*);

t_ascii		*make_node(void);
void		make_node_2(t_ascii*);
void		make_node_3(t_ascii*);
void		make_node_4(t_ascii*);
void		make_node_5(t_ascii*);
t_ascii		**ret_space(t_ascii *node);
t_ascii		**ret_excl(t_ascii *node);
t_ascii		**ret_quote(t_ascii *node);
t_ascii		**ret_num(t_ascii *node);
t_ascii		**ret_dollar(t_ascii *node);
t_ascii		**ret_percent(t_ascii *node);
t_ascii		**ret_and(t_ascii *node);
t_ascii		**ret_squote(t_ascii *node);
t_ascii		**ret_op(t_ascii *node);
t_ascii		**ret_cp(t_ascii *node);
t_ascii		**ret_star(t_ascii *node);
t_ascii		**ret_plus(t_ascii *node);
t_ascii		**ret_coma(t_ascii *node);
t_ascii		**ret_minus(t_ascii *node);
t_ascii		**ret_point(t_ascii *node);
t_ascii		**ret_slash(t_ascii *node);
t_ascii		**ret_zero(t_ascii *node);
t_ascii		**ret_one(t_ascii *node);
t_ascii		**ret_two(t_ascii *node);
t_ascii		**ret_three(t_ascii *node);
t_ascii		**ret_four(t_ascii *node);
t_ascii		**ret_five(t_ascii *node);
t_ascii		**ret_six(t_ascii *node);
t_ascii		**ret_seven(t_ascii *node);
t_ascii		**ret_eight(t_ascii *node);
t_ascii		**ret_nine(t_ascii *node);
t_ascii		**ret_dbpoint(t_ascii *node);
t_ascii		**ret_pointcoma(t_ascii *node);
t_ascii		**ret_left(t_ascii *node);
t_ascii		**ret_equal(t_ascii *node);
t_ascii		**ret_right(t_ascii *node);
t_ascii		**ret_inter(t_ascii *node);
t_ascii		**ret_arob(t_ascii *node);
t_ascii		**ret_A(t_ascii *node);
t_ascii		**ret_B(t_ascii *node);
t_ascii		**ret_C(t_ascii *node);
t_ascii		**ret_D(t_ascii *node);
t_ascii		**ret_E(t_ascii *node);
t_ascii		**ret_F(t_ascii *node);
t_ascii		**ret_G(t_ascii *node);
t_ascii		**ret_H(t_ascii *node);
t_ascii		**ret_I(t_ascii *node);
t_ascii		**ret_J(t_ascii *node);
t_ascii		**ret_K(t_ascii *node);
t_ascii		**ret_L(t_ascii *node);
t_ascii		**ret_M(t_ascii *node);
t_ascii		**ret_N(t_ascii *node);
t_ascii		**ret_O(t_ascii *node);
t_ascii		**ret_P(t_ascii *node);
t_ascii		**ret_Q(t_ascii *node);
t_ascii		**ret_R(t_ascii *node);
t_ascii		**ret_S(t_ascii *node);
t_ascii		**ret_T(t_ascii *node);
t_ascii		**ret_U(t_ascii *node);
t_ascii		**ret_V(t_ascii *node);
t_ascii		**ret_W(t_ascii *node);
t_ascii		**ret_X(t_ascii *node);
t_ascii		**ret_Y(t_ascii *node);
t_ascii		**ret_Z(t_ascii *node);
t_ascii		**ret_oc(t_ascii *node);
t_ascii		**ret_backslash(t_ascii *node);
t_ascii		**ret_cc(t_ascii *node);
t_ascii		**ret_up(t_ascii *node);
t_ascii		**ret_under(t_ascii *node);
t_ascii		**ret_accent(t_ascii *node);
t_ascii		**ret_a(t_ascii *node);
t_ascii		**ret_b(t_ascii *node);
t_ascii		**ret_c(t_ascii *node);
t_ascii		**ret_d(t_ascii *node);
t_ascii		**ret_e(t_ascii *node);
t_ascii		**ret_f(t_ascii *node);
t_ascii		**ret_g(t_ascii *node);
t_ascii		**ret_h(t_ascii *node);
t_ascii		**ret_i(t_ascii *node);
t_ascii		**ret_j(t_ascii *node);
t_ascii		**ret_k(t_ascii *node);
t_ascii		**ret_l(t_ascii *node);
t_ascii		**ret_m(t_ascii *node);
t_ascii		**ret_n(t_ascii *node);
t_ascii		**ret_o(t_ascii *node);
t_ascii		**ret_p(t_ascii *node);
t_ascii		**ret_q(t_ascii *node);
t_ascii		**ret_r(t_ascii *node);
t_ascii		**ret_s(t_ascii *node);
t_ascii		**ret_t(t_ascii *node);
t_ascii		**ret_u(t_ascii *node);
t_ascii		**ret_v(t_ascii *node);
t_ascii		**ret_w(t_ascii *node);
t_ascii		**ret_x(t_ascii *node);
t_ascii		**ret_y(t_ascii *node);
t_ascii		**ret_z(t_ascii *node);
t_ascii		**ret_ov(t_ascii *node);
t_ascii		**ret_pipe(t_ascii *node);
t_ascii		**ret_cv(t_ascii *node);
t_ascii		**ret_tild(t_ascii *node);

#endif
