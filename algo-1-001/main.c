/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 09:05:42 by rgary             #+#    #+#             */
/*   Updated: 2013/12/20 15:53:56 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <wchar.h>
#include "includes/ft_printf.h"

#define	SP ft_printf("--------------------\n")
#define RE ft_putstr("Resultat est = ")
#define DE ft_putstr("Devrait etre = ")

#define PRT(s, a) ft_printf("-------------\nmy ft = "); \
	retftp = ft_printf(s, a); \
	printf("libft = ");		  \
	retp = printf(s, a); \
	testcnt += 1;\
	printf("retOK? %s\n", ((retftp == retp) ? "\e[32mOui\e[0m" : "\e[31mNon\e[0m"));\
	rescnt += ((retftp == retp) ? 1 : 0);


#define PRT2(s, a, b) ft_printf("-------------\nmy ft = ");	\
    retftp = ft_printf(s, a, b);								\
    printf("libft = ");       \
    retp = printf(s, a, b);												\
    printf("retOK? %s\n", ((retftp == retp) ? "\e[32mOui\e[0m" : "\e[31mNon\e[0m\
"));

#define PRT3(s, a, b, c) ft_printf("-------------\nmy ft = ");	\
    retftp = ft_printf(s, a, b, c);								\
    printf("libft = ");       \
    retp = printf(s, a, b, c);											\
    printf("retOK? %s\n", ((retftp == retp) ? "\e[32mOui\e[0m" : "\e[31mNon\e[0m\
"));

#define PR ft_putstr("retftp = ");\
ft_putnbrl(retftp);\
ft_putstr("retp   = ");\
ft_putnbrl(retp);

/*char        *ft_strdup(const char *str);*/
/*void        ft_putchar(char);*/
int         ft_printf(const char *format, ...)
	__attribute__((format(printf, 1, 2)));

int		testcnt = 0;
int		rescnt = 0;
int retftp, retp;
short	i = 105;
short	j = -115;
long	k = 1234567890;
long	l = -1234567890;
int		m = INT_MAX;
int		n = INT_MIN;
int		o = 0;
int		p = -0;
int		q = 105;
int		r = -115;
int		s = 15;
int		t = 22;

char    z = 'r';

char *str = "DROLILOL";

int 	main(void)
{
	ft_putendl("************* DEBUT TEST %c***********");
/*	char	c1;
	char	c2;
	wchar_t	c9;
	
	c1 = 0;RE;
	while (c1 != 33)
	{
		ft_printf("| %lc |", c1);
		c1 += 1;
	}
	c1 = 0;DE;
	while (c1 != 33)
	{
		printf("| %lc |", c1);
		c1 += 1;
	}SP;

	ft_putchar('\n');

	c2 = 32;RE;
    while (c2 != 127)
    {
        ft_printf("%c", c2);
        c2 += 1;
    }
    ft_putchar('\n');
    c2 = 32;DE;
    while (c2 != 127)
    {
        printf("%c", c2);
        c2 += 1;
    }SP;

	ft_putchar('\n');

	c9 = 128;RE;
	while (c9 != 255)
	{
		ft_printf("%lc", c9);
		c9 += 1;
	}
	ft_putchar('\n');
	c9 = 128;DE;
	while (c9 != 255)
    printf("retOK? %s\n", ((retftp == retp) ? "\e[32mOui\e[0m" : "\e[31mNon\e[0m\
"));	{
		printf("%lc", c9);
		c9 += 1;
	}SP;*/
	ft_putendl("*********FIN TEST %c***********");
	ft_putendl("************* DEBUT TEST %s***********");
/*	char s1[] = "";
	char *s2 = NULL;
	char s3[] = "\0";
	char s4[] = "DROLILOL";
	
	SP;RE;
	retftp = ft_printf("%s\n", s1);DE;
	retp = printf("%s\n", s1);
	ft_putstr("retftp = ");ft_putnbrl(retftp);ft_putstr("retp   = ");ft_putnbrl(retp);SP;RE;
	retftp = ft_printf("%s\n", s2);DE;
    retp = printf("%s\n", s2);
	ft_putstr("retftp = ");ft_putnbrl(retftp);ft_putstr("retp   = ");ft_putnbrl(retp);SP;RE;
	retftp = ft_printf("%s\n", s3);DE;
    retp = printf("%s\n", s3);
	ft_putstr("retftp = ");ft_putnbrl(retftp);ft_putstr("retp   = ");ft_putnbrl(retp);SP;RE;
	retftp = ft_printf("%s\n", s4);DE;
    retp = printf("%s\n", s4);
	ft_putstr("retftp = ");ft_putnbrl(retftp);ft_putstr("retp   = ");ft_putnbrl(retp);SP;RE;
*/
	ft_putendl("************* FIN TEST %s***********");
	ft_putendl("************DEBUT TEST %u**********");
	/*	unsigned int i1 = 0;
	unsigned int i2 = 164;
	unsigned int i3 = UINT_MAX;
	unsigned int i4 = -40;

	PRT("%u", i1);
	ft_putstr("retftp = ");ft_putnbrl(retftp);ft_putstr("retp   = ");ft_putnbrl(retp);SP;
	PRT("%u", i2);
	ft_putstr("retftp = ");ft_putnbrl(retftp);ft_putstr("retp   = ");ft_putnbrl(retp);SP;
	PRT("%u", i3);
	ft_putstr("retftp = ");ft_putnbrl(retftp);ft_putstr("retp   = ");ft_putnbrl(retp);SP;
	PRT("%u", i4);
	ft_putstr("retftp = ");ft_putnbrl(retftp);ft_putstr("retp   = ");ft_putnbrl(retp);SP;
	*/
	ft_putendl("*************FIN TEST %u***********");
	ft_putendl("**********DEBUT TEST %o***********");
	/*
	int	i = 0;
	unsigned long	j[] = {0, 123, 456, 789, 1234, 5678, 9012, 34567, 89012};
	int				k;

	PRT("%o\n", i);
	k = 0;
	while (k < 9)
	{
		PRT("%#lo\n", j[k]);
		k++;
	}
	*/
	ft_putendl("*************FIN TEST %o***********");

	ft_putendl("**********DEBUT TEST %d***********");
	PRT("m = %d\n", m);
	PRT("n = %d\n", n);
    ft_putendl("***********FIN TEST %d************");
	ft_putendl("**********DEBUT TEST %x***********");

	unsigned long   j[] = {0, 123, 456, 789, 1234, 5678, 9012, 35478, UINT_MAX};
	int		a = 0;

    PRT("%x\n", 0);
    while (a < 9)
    {
        PRT("%#lx\n", j[a]);
        a++;
	}

	ft_putendl("***********FIN TEST %x************ ");
	ft_putendl("**********DEBUT TEST %p**********");

	PRT("%p\n", str);

	ft_putendl("**********FIN TEST %p*************");
	ft_putendl("***********DEBUT TEST %%*********");

	PRT("%d%% et ta mere qui sens le poisson c'est elle le\n", i);
	ft_putstr("retftp = ");
	ft_putnbrl(retftp);
	ft_putstr("retp   = ");
	ft_putnbrl(retp);

	ft_putendl("**********FIN TEST %Z************");
	ft_putendl("***********DEBUT TEST %Z*********");

	retftp = ft_printf("105 = %d et on va voir le big %Z\n", i);
	retp = printf("105 = %d et on va voir le big %%\n", i);
	ft_putstr("retftp = ");
    ft_putnbrl(retftp);
    ft_putstr("retp   = ");
    ft_putnbrl(retp);

	ft_putendl("**********FIN TEST %Z************");

	ft_putendl("***********DEBUT TEST %*********");

	PRT("% ll %c|et si je l'ecriture longtemps, ca fait quoi ?\n", z);
	ft_putstr("retftp = ");
    ft_putnbrl(retftp);
    ft_putstr("retp   = ");
    ft_putnbrl(retp);

	ft_putendl("**********FIN TEST %************");
	ft_putendl("***********DEBUT TEST % d*******");

	PRT("Ca fait =% d\n", i);
	PRT("Ca fait =% d\n", j);
	PRT("Ca fait =% d\n", k);
    PRT("Ca fait =% d\n", l);
	PRT("Ca fait =% d\n", m);
    PRT("Ca fait =% d\n", n);
	PRT("Ca fait =% d\n", o);
	PRT("Ca fait =% d\n", p);

	ft_putendl("***********FIN TEST % d*********");

	ft_putendl("***********DEBUT TEST %+d*******");

    PRT("Ca fait =%+d\n", i);
    PRT("Ca fait =%+d\n", j);
    PRT("Ca fait =%+d\n", k);
    PRT("Ca fait =%+d\n", l);
    PRT("Ca fait =%+d\n", m);
    PRT("Ca fait =%+d\n", n);
    PRT("Ca fait =%+d\n", o);
    PRT("Ca fait =%+d\n", p);

    ft_putendl("***********FIN TEST %+d*********");

	ft_putendl("***********DEBUT TEST %3d*******");

    PRT("Ca fait =%3d\n", i);
    PRT("Ca fait =%3d\n", j);
	PRT("Ca fait =%3d\n", k);
    PRT("Ca fait =%3d\n", l);
    PRT("Ca fait =%3d\n", m);
	PRT("Ca fait =%3d\n", n);
    PRT("Ca fait =%3d\n", o);
    PRT("Ca fait =%3d\n", p);

    ft_putendl("***********FIN TEST %3d*********");

	ft_putendl("***********DEBUT TEST %03d*******");

    PRT("Ca fait =%03d\n", i);
    PRT("Ca fait =%03d\n", j);
    PRT("Ca fait =%03d\n", k);
    PRT("Ca fait =%03d\n", l);
    PRT("Ca fait =%03d\n", m);
    PRT("Ca fait =%03d\n", n);
    PRT("Ca fait =%03d\n", o);
    PRT("Ca fait =%03d\n", p);

    ft_putendl("***********FIN TEST %03d*********");
	
	ft_putendl("***********DEBUT TEST %#15x******");

    PRT("Ca fait =%#15x\n", i);
    PRT("Ca fait =%#15x\n", j);
    PRT("Ca fait =%#15x\n", k);
    PRT("Ca fait =%#15x\n", l);
    PRT("Ca fait =%#15x\n", m);
    PRT("Ca fait =%#15x\n", n);
    PRT("Ca fait =%#15x\n", o);
    PRT("Ca fait =%#15x\n", p);

    ft_putendl("***********FIN TEST %#15x********");

	ft_putendl("***********DEBUT TEST %0#15x*****");

    PRT("Ca fait =%0#15x\n", i);
    PRT("Ca fait =%0#15x\n", j);
    PRT("Ca fait =%0#15x\n", k);
    PRT("Ca fait =%0#15x\n", l);
    PRT("Ca fait =%0#15x\n", m);
    PRT("Ca fait =%0#15x\n", n);
    PRT("Ca fait =%0#15x\n", o);
    PRT2("Ca fait =%0#15x%0#15x\n", p, p);

    ft_putendl("***********FIN TEST %0#15x*******");

	ft_putendl("***********DEBUT TEST %*d********");

	PRT2("Ca fait =%*d\n", q, r);
	PRT2("Ca fait =%*d\n", o, p);
	PRT2("Ca fait =%*d\n", s, t);
	PRT("Ca fait =%*d\n", s);
	PRT("Ca fait =%*d\n", t);
/*    PRT("Ca fait =%*d\n", l);
	PRT("Ca fait =%*d\n", m);
	PRT("Ca fait =%*d\n", n);
	PRT("Ca fait =%*d\n", o);
	PRT("Ca fait =%*d\n", p);*/

    ft_putendl("***********FIN TEST %*d*********");
	
	int		resultat;
	resultat = (100 * rescnt) / testcnt;
	ft_putnbr(resultat);
	ft_putendl("%");
	return (0);
}
/*
int retftp, retp;
short   i = 105;
short   j = -115;
long    k = 1234567890;
long    l = -1234567890;
int     m = INT_MAX;
int     n = INT_MIN;
int     o = 0;
int     p = -0;
int		q = 105;
int		r = -115;
int		s = 15;
int		t = 22;

char    z = 'r';

char *str = "DROLILOL";
*/
