/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoding.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:49:48 by rgary             #+#    #+#             */
/*   Updated: 2014/02/01 17:38:48 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ENCODING_H
# define ENCODING_H

# define LIVEC	1
# define LDC	2
# define STC	3
# define ADDC	4
# define SUBC	5
# define ANDC	6
# define ORC	7
# define XORC	8
# define ZJMPC	9
# define LDIC	10
# define STIC	11
# define FORKC	12
# define LLDC	13
# define LLDIC	14
# define LFORKC	15
# define AFFC	16

# define LVAL(s)	ft_strcmp(lexer->value, s) == 0

#endif
