/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 12:24:36 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/02 12:24:37 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOSE_H
# define VERBOSE_H

# define V_KILLED "Process killed: %d (%d alive)\n\n"
# define V_XOR "xor: value %ld | value %ld -> reg%ld\n"
# define V_ADD "add: value %ld + value %ld -> reg%ld\n"
# define V_AND "and: value %ld & value %ld -> reg%ld\n"
# define V_FORK "fork: %ld bytes from pc %d to pc %d\n"
# define V_LD "ld: value %d -> reg%ld\n"
# define V_LDI "ldi: value %d -> reg%ld\n"
# define V_LFORK "lfork: %d bytes from pc %d to pc %d\n"
# define V_LLD "lld: value %ld -> reg%ld\n"
# define V_LLDI "lldi: value %ld -> reg%ld\n"
# define V_OR "or: value %ld | value %ld -> reg%ld\n"
# define V_ST "st: value %d -> addr%d\n"
# define V_STI "sti: value %d -> addr%ld\n"
# define V_SUB "sub: value %ld - value %ld -> reg%ld\n"
# define V_ZJMP_S1 "zjmp: %ld bytes from pc %d "
# define V_ZJMP_S2 "to pc %d [SUCCESS]\n"
# define V_ZJMP_F "zjmp: %ld bytes from pc %d [FAIL]\n"

#endif /* !VERBOSE_H */
