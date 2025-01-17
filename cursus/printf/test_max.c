/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_max.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 20:15:33 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 20:16:14 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 20:12:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/27 21:53:53 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>
#include <limits.h>
#include <stdio.h>

#define F fflush(stdout)

int			main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("1 argument requis compris entre 1 et 5 inclus.\n");
		return (0);
	}
	char	*p1;
	char	*p2;
	char	*p3;
	char **tab;
	int i = -1;
	int j;
	char c = 33;
	char *string = NULL;
	short	zeroshort = 0;
	short	short1 = 15;
	short	short2 = -15;
	short	short_max = 32767;
	short	short_min = -32767;
	int		zeroint = 0;
	int		int1 = 25;
	int		int2 = -25;
	int		int_max = 2147483647;
	int		int_min = -2147483648;
	long	zerolong = 0;
	long	long1 = 35;
	long	long2 = -35;
	long	long_max = 9223372036854775807;
	long	long_min = -9223372036854775807;
	long long	zerolonglong = 0;
	long long	longlong1 = 45;
	long long	longlong2 =		-45;
	long long	longlong_max = 9223372036854775807;
	long long	longlong_min = -9223372036854775807;
	double crash_float = 0.0 / 0.0;
	double crash_float2 = pow(1024, 1024);
	double t_f1 = 0.0;
	float  t_f2 = 1.6;
	double t_f3 = -1.6;
	double t_f4 = 50.4;
	double t_f5 = -50.4;
	double t_f6 = 2147483647.0;
	double t_f7 = -2147483648.0;
	long double t_f = 1234567890.1234567890;
	long t_bit = 2147483647;
	long double t_f8  = 0.000001;
	char	hh_test = 'E';
	int t_o = 102;
	int t_x = 15;
	int t_X		= 15;
	int t_d = 42;
	unsigned int t_u = 52;
	char t_c = '*';
	char*pointer_test;
	char *t_s = "    123456789     ";
	float t_fl = 123.12345;

	p1 = "Testitude1";
	p2 = "Testitude2";
	p3 = "Testitude3";


	char **tab2;
	int i2 = -1;
	int j2;
	char c2 = 33;

	int		test_nb = ft_atoi(av[1]);

	if (test_nb < 1 || test_nb > 5)
	{
		ft_printf("L'argument doit etre compris entre 1 et 5 inclus.\n");
		return (0);
	}

	int		test_part1 = 0;
	int		test_part2 = 0;
	int		test_part3 = 0;
	int		test_part4 = 0;
	int		test_part5 = 0;

	test_part1 = test_nb == 1 ? 1 : 0;
	test_part2 = test_nb == 2 ? 1 : 0;
	test_part3 = test_nb == 3 ? 1 : 0;
	test_part4 = test_nb == 4 ? 1 : 0;
	test_part5 = test_nb == 5 ? 1 : 0;

	float	nb;
	int		**int_tab;
	int		fill_tab;
	int		fill_case;
	int		put_int = 1;


	char	***example_triple;
	int		m = -1;
	int		n;
	int		o;


	if (test_part1 == 1)
	{
		// D TESTS

		printf("printf =    Test du %%%d, %s%%\n", 10, "hello"), F;
		ft_printf("ft_printf = Test du %%%d, %s%%\n\n\n", 10, "hello");


		printf("		TEST OF d\n\n"), F;
		printf("expected =  Testd /%d/ /%d/ /%d/\n", 15, -50, 123456), F;
		ft_printf("ft_printf = Testd /%d/ /%d/ /%d/\n\n\n", 15, -50, 123456);

		//	C TESTS
		printf("		TEST OF c\n\n"), F;
		printf("expected =  Testc /%c/ /%c/ /%c/\n", 'j', 'Z', '0'), F;
		ft_printf("ft_printf = Testc /%c/ /%c/ /%c/\n\n\n", 'j', 'Z', '0');

		//	S TESTS

		printf("		TEST OF s\n\n"), F;
		printf("expected =  Tests /%s/ /%s/ /%s/\n", "Hello", "Ca marche", "01254-()"), F;
		ft_printf("ft_printf = Tests /%s/ /%s/ /%s/\n\n\n", "Hello", "Ca marche", "01254-()");

		//	P TESTS

		printf("		TEST OF p\n\n"), F;
		printf("expected =  Testp /%p/ /%p/ /%p/\n", p1, p2, p3), F;
		ft_printf("ft_printf = Testp /%p/ /%p/ /%p/\n\n\n", p1, p2, p3);

		//	I TESTS

		printf("		TEST OF i\n\n"), F;
		printf("expected =  Testi /%i/ /%i/ /%i/\n", 54, -6875, 789521), F;
		ft_printf("ft_printf = Testi /%i/ /%i/ /%i/\n\n\n", 54, -6875, 789521);

		//	O TESTS

		printf("		TEST OF o\n\n"), F;
		printf("expected =  Testo /%o/ /%o/ /%o/\n", 53, 765421, 42), F;
		ft_printf("ft_printf = Testo /%o/ /%o/ /%o/\n\n\n", 53, 765421, 42);

		//	U TESTS

		printf("		TEST OF u\n\n"), F;
		printf("expected =  Testu /%u/ /%u/ /%u/\n", 1542, -4752, 4), F;
		ft_printf("expected =  Testu /%u/ /%u/ /%u/\n\n\n", 1542, -4752, 4);

		//	X TESTS

		printf("		TEST OF x\n\n"), F;
		printf("expected =  Testx /%x/ /%x/ /%x/\n", 45789, 3, -7865), F;
		ft_printf("ft_printf = Testx /%x/ /%x/ /%x/\n\n\n", 45789, 3, -7865);

		//	BIG X TESTS

		printf("		TEST OF X\n\n"), F;
		printf("expected =  TestX /%X/ /%X/ /%X/\n", 45789, 3, -7865), F;
		ft_printf("ft_printf = TestX /%X/ /%X/ /%X/\n\n\n", 45789, 3, -7865);

		//	F TESTS

		printf("		TEST OF f\n\n"), F;
		printf("expected =  Testf /%f/ /%f/ /%f/\n", 128.000001, 53.8975, -7.95), F;
		ft_printf("ft_printf = Testf /%f/ /%f/ /%f/\n\n\n", 128.000001, 53.8975, -7.95);
		printf("test arrondi float /%.0f/ /%.f/ /%.2f/ /%.12f/\n", 55.5994578, 55.5994578, 55.5994578, 55.5994578), F;
		ft_printf("test arrondi float /%.0f/ /%.f/ /%.2f/ /%.12f/\n\n\n", 55.5994578, 55.5994578, 55.5994578, 55.5994578);

		//	MINUS TESTS

		printf("		TEST OF -\n\n"), F;
		printf("expected =  Test-c /%-10c/ /%-3c/ /%--5c/\n", 'a', 'B', 'c'), F;
		ft_printf("ft_printf = Test-c /%-10c/ /%-3c/ /%--5c/\n\n\n", 'a', 'B', 'c');

		printf("expected =  Test-s /%-12s/ /%-s/ /%-5s/\n", "hello", "bouuuh", ""), F;
		ft_printf("ft_printf = Test-s /%-12s/ /%-s/ /%-5s/\n\n\n", "hello", "bouuuh", "");

		printf("expected =  Test-p /%-15p/ /%-12p/ /%-p/\n", p1, p2, p3), F;
		ft_printf("ft_printf = Test-p /%-15p/ /%-12p/ /%-p/\n\n\n", p1, p2, p3);

		printf("expected =  Test-f /%-12f/ /%-0f/ /%-7f/\n", 78.50140, 0.1240002, 41782.1), F;
		ft_printf("ft_printf = Test-f /%-12f/ /%-0f/ /%-7f/\n\n\n", 78.50140, 0.1240002, 41782.1);

		printf("expected =  Test-d /%-d/ /%-15d/ /%-0d/\n", 3, 50412, -2145), F;
		ft_printf("ft_printf = Test-d /%-d/ /%-15d/ /%-0d/\n\n\n", 3, 50412, -2145);

		printf("expected =  Test-i /%-i/ /%-18i/ /%--8i/\n", 78, 364578, 0), F;
		ft_printf("ft_printf = Test-i /%-i/ /%-18i/ /%--8i/\n\n\n", 78, 364578, 0);

		printf("expected =  Test-o /%-o/ /%-0o/ /%-18o/\n", 0, 48, -78954), F;
		ft_printf("ft_printf = Test-o /%-o/ /%-0o/ /%-18o/\n\n\n", 0, 48, -78954);

		printf("expected =  Test-u /%-u/ /%-0u/ /%-19u/\n", 4215, -7584, 0), F;
		ft_printf("ft_printf = Test-u /%-u/ /%-0u/ /%-19u/\n\n\n", 4215, -7584, 0);

		printf("expected =  Test-x /%-x/ /%-0x/ /%-25x/\n", 789456, -45721, 0), F;
		ft_printf("ft_printf = Test-x /%-x/ /%-0x/ /%-25x/\n\n\n", 789456, -45721, 0);

		printf("expected =  Test-X /%-X/ /%-0X/ /%-25X/\n", 789456, -45721, 0), F;
		ft_printf("ft_printf = Test-X /%-X/ /%-0X/ /%-25X/\n\n\n", 789456, -45721, 0);

		//	PLUS TESTS

		printf("		TEST OF +\n\n"), F;
		printf("expected =  Test+c /%+c/ /%+c/ /%++c/\n", 'a', 'B', 'c'), F;
		ft_printf("ft_printf = Test+c /%+c/ /%+c/ /%++c/\n\n\n", 'a', 'B', 'c');

		printf("expected =  Test+s /%+s/ /%+s/ /%++s/\n", "hello", "bouuuh", ""), F;
		ft_printf("ft_printf = Test+s /%+s/ /%+s/ /%++s/\n\n\n", "hello", "bouuuh", "");

		printf("expected =  Test+p /%+p/ /%+p/ /%++p/\n", p1, p2, p3), F;
		ft_printf("ft_printf = Test+p /%+p/ /%+p/ /%++p/\n\n\n", p1, p2, p3);

		printf("expected =  Test+f /%+f/ /%+f/ /%++f/\n", 78.50140, 0.1240002, 41782.1), F;
		ft_printf("ft_printf = Test+f /%+f/ /%+f/ /%++f/\n\n\n", 78.50140, 0.1240002, 41782.1);

		printf("expected =  Test+d /%+d/ /%+d/ /%++d/\n", 3, 50412, -2145), F;
		ft_printf("ft_printf = Test+d /%+d/ /%+d/ /%++d/\n\n\n", 3, 50412, -2145);

		printf("expected =  Test+i /%+i/ /%+i/ /%++i/\n", 78, 364578, 0), F;
		ft_printf("ft_printf = Test+i /%+i/ /%+i/ /%++i/\n\n\n", 78, 364578, 0);

		printf("expected =  Test+o /%+o/ /%+o/ /%++o/\n", 0, 48, -78954), F;
		ft_printf("ft_printf = Test+o /%+o/ /%+o/ /%++o/\n\n\n", 0, 48, -78954);

		printf("expected =  Test+u /%+u/ /%+u/ /%++u/\n", 4215, -7584, 0), F;
		ft_printf("ft_printf = Test+u /%+u/ /%+u/ /%++u/\n\n\n", 4215, -7584, 0);

		printf("expected =  Test+x /%+x/ /%+x/ /%++x/\n", 789456, -45721, 0), F;
		ft_printf("ft_printf = Test+x /%+x/ /%+x/ /%++x/\n\n\n", 789456, -45721, 0);

		printf("expected =  Test+X /%+X/ /%+X/ /%++X/\n", 789456, -45721, 0), F;
		ft_printf("ft_printf = Test+X /%+X/ /%+X/ /%++X/\n\n\n", 789456, -45721, 0);

		//	# TESTS

		printf("expected =  Test#o /%#o/\n", 78945), F;
		ft_printf("ft_printf = Test#o /%#o/\n\n\n", 78945);

		printf("expected =  Test#x /%#x/\n", -7854), F;
		ft_printf("ft_printf = Test#x /%#x/\n\n\n", -7854);

		printf("expected =  Test#X /%#X/\n", 64215), F;
		ft_printf("ft_printf = Test#X /%#X/\n\n\n", 64215);

		printf("expected =  Test#f /%#f/ /%#.f/ /%#.0f/ /%#.5f/\n", 78945.25, 78945.25, 78945.25, 78945.25), F;
		ft_printf("ft_printf = Test#f /%#f/ /%#.f/ /%#.0f/ /%#.5f/\n\n\n", 78945.25, 78945.25, 78945.25, 78945.25);

		printf("expected =  Test#c /%#c/\n", 'a'), F;
		ft_printf("ft_printf = Test#c /%#c/\n\n\n", 'a');


		//	ZERO TESTS

		printf("expected =  Test0d /%0d/ /%010d/ /%-05d/ /%08.5d/\n", 487, 487, 487, 487), F;
		ft_printf("ft_printf = Test0d /%0d/ /%010d/ /%-05d/ /%08.5d/\n\n\n", 487, 487, 487, 487);

		printf("expected =  Test0i /%0i/ /%010i/ /%-05i/ /%08.5i/\n", 487, 487, 487, 487), F;
		ft_printf("ft_printf = Test0i /%0i/ /%010i/ /%-05i/ /%08.5i/\n\n\n", 487, 487, 487, 487);

		printf("expected =  Test0u /%0u/ /%010u/ /%-05u/ /%08.5u/\n", 487, 487, 487, 487), F;
		ft_printf("ft_printf = Test0u /%0u/ /%010u/ /%-05u/ /%08.5u/\n", 487, 487, 487, 487);

		printf("expected =  Test0x /%0x/ /%010x/ /%-05x/ /%08.5x/\n", 487, 487, 487, 487), F;
		ft_printf("ft_printf = Test0x /%0x/ /%010x/ /%-05x/ /%08.5x/\n", 487, 487, 487, 487);

		printf("expected =  Test0X /%0X/ /%010X/ /%-05X/ /%08.5X/\n", 487, 487, 487, 487), F;
		ft_printf("ft_printf = Test0X /%0X/ /%010X/ /%-05X/ /%08.5X/\n", 487, 487, 487, 487);

		printf("expected =  Test0o /%0o/ /%010o/ /%-05o/ /%08.5o/\n", 487, 487, 487, 487), F;
		ft_printf("ft_printf = Test0o /%0o/ /%010o/ /%-05o/ /%08.5o/\n", 487, 487, 487, 487);

		printf("expected =  Test0f /%0f/ /%010f/ /%-05f/\n", 458.36, 458.36, 458.36), F;
		ft_printf("ft_printf = Test0f /%0f/ /%010f/ /%-05f/\n", 458.36, 458.36, 458.36);

		//	PREC TESTS

		printf("expected =  Test.c /%.c/ /%.10c/ /%.0c/ /%5.12c/\n", 'a', 'v', '7', '^'), F;
		ft_printf("ft_printf = Test.c /%.c/ /%.10c/ /%.0c/ /%5.12c/\n\n\n", 'a', 'v', '7', '^');

		printf("expected =  Test.s /%.s/ /%.10s/ /%.0s/ /%5.18s/\n", "hello", "hello", "hello", "hello"), F;
		ft_printf("ft_printf = Test.s /%.s/ /%.18s/ /%.0s/ /%5.18s/\n\n\n", "hello", "hello", "hello", "hello");

		printf("expected =  Test.p /%.p/ /%.10p/ /%.0p/ /%.18p/\n", p1, p2, p3, p1), F;
		ft_printf("ft_printf = Test.p /%.p/ /%.10p/ /%.0p/ /%.18p/\n\n\n", p1, p2, p3, p1);

		printf("expected =  Test.d /%.d/ /%.10d/ /%.0d/ /%5.18d/\n", 7895, 789, -785424, 15547856), F;
		ft_printf("ft_printf = Test.d /%.d/ /%.10d/ /%.0d/ /%5.18d/\n\n\n", 7895, 789, -785424, 15547856);

		printf("expected =  Test.i /%.i/ /%.10i/ /%.0i/ /%5.18i/\n", 7895, 789, -785424, 15547856), F;
		ft_printf("ft_printf = Test.i /%.i/ /%.10i/ /%.0i/ /%5.18i/\n\n\n", 7895, 789, -785424, 15547856);

		printf("expected =  Test.o /%.o/ /%.10o/ /%.0o/ /%5.18o/\n", 7895, 789, -789521, 15547856), F;
		ft_printf("ft_printf = Test.o /%.o/ /%.10o/ /%.0o/ /%5.18o/\n\n\n", 7895, 789, -789521, 15547856);

		printf("expected =  Test.u /%.u/ /%.10u/ /%.0u/ /%5.18u/\n", 7895, 789, -789521, 15547856), F;
		ft_printf("ft_printf = Test.u /%.u/ /%.10u/ /%.0u/ /%5.18u/\n\n\n", 7895, 789, -789521, 15547856);

		printf("expected =  Test.x /%.x/ /%.10x/ /%.0x/ /%5.18x/\n", 7895, 789, -789521, 15547856), F;
		ft_printf("ft_printf = Test.x /%.x/ /%.10x/ /%.0x/ /%5.18x/\n\n\n", 7895, 789, -789521, 15547856);

		printf("expected =  Test.X /%.X/ /%.10X/ /%.0X/ /%5.18X/\n", 7895, 789, -789521, 15547856), F;
		ft_printf("ft_printf = Test.X /%.X/ /%.10X/ /%.0X/ /%5.18X/\n\n\n", 7895, 789, -789521, 15547856);

		printf("FIN\n"), F;

		//		WIDTH TESTS

		printf("		TEST OF WIDTH\n\n"), F;
		printf("expected =  Testc /%15c/ /%5c/ /%-5c/\n", 'a', 'B', 'c'), F;
		ft_printf("ft_printf = Testc /%15c/ /%5c/ /%-5c/\n\n\n", 'a', 'B', 'c');

		printf("expected =  Tests /%-12s/ /%12s/ /%-5s/\n", "hello", "bouuuh", ""), F;
		ft_printf("ft_printf = Tests /%-12s/ /%12s/ /%-5s/\n\n\n", "hello", "bouuuh", "");

		printf("expected =  Testp /%1p/ /%15p/ /%-15p/\n", p1, p2, p3), F;
		ft_printf("ft_printf = Testp /%1p/ /%15p/ /%-15p/\n\n\n", p1, p2, p3);

		printf("expected =  Testf /%0f/ /%+15f/ /%-15f/\n", 78.50140, 0.1240002, 41782.1), F;
		ft_printf("ft_printf = Testf /%0f/ /%+15f/ /%-15f/\n\n\n", 78.50140, 0.1240002, 41782.1);

		printf("expected =  Testd /%15d/ /%+15d/ /%-15d/\n", 3, 50412, -2145), F;
		ft_printf("ft_printf = Testd /%15d/ /%+15d/ /%-15d/\n\n\n", 3, 50412, -2145);

		printf("expected =  Testi /%15i/ /%+15i/ /%-15i/\n", 78, 364578, 0), F;
		ft_printf("ft_printf = Testi /%15i/ /%+15i/ /%-15i/\n\n\n", 78, 364578, 0);

		printf("expected =  Testo /%15o/ /%0o/ /%-15o/\n", 0, 48, -78954), F;
		ft_printf("ft_printf = Testo /%15o/ /%0o/ /%-15o/\n\n\n", 0, 48, -78954);

		printf("expected =  Testu /%15u/ /%0u/ /%-15u/\n", 4215, -7584, 0), F;
		ft_printf("ft_printf = Testu /%15u/ /%0u/ /%-15u/\n\n\n", 4215, -7584, 0);

		printf("expected =  Testx /%15x/ /%0x/ /%-15x/\n", 789456, -45721, 0), F;
		ft_printf("ft_printf = Testx /%15x/ /%0x/ /%-15x/\n\n\n", 789456, -45721, 0);

		printf("expected =  TestX /%15X/ /%0X/ /%-15X/\n", 789456, -45721, 0), F;
		ft_printf("ft_printf = TestX /%15X/ /%0X/ /%-15X/\n\n\n", 789456, -45721, 0);


		//		SPACE TESTS

		printf("		TEST OF SPACE\n\n"), F;
		printf("expected =  Testc /% c/ /% c/ /%c/\n", 'a', 'B', 'c'), F;
		ft_printf("ft_printf = Testc /% c/ /%  c/ /%c/\n\n\n", 'a', 'B', 'c');

		printf("expected =  Tests /% s/ /%   s/ /% +s/\n", "hello", "bouuuh", ""), F;
		ft_printf("ft_printf = Tests /% s/ /%   s/ /% +s/\n\n\n", "hello", "bouuuh", "");

		printf("expected =  Testp /% p/ /%   p/ /% +p/\n", p1, p2, p3), F;
		ft_printf("ft_printf = Testp /% p/ /%   p/ /% +p/\n\n\n", p1, p2, p3);

		printf("expected =  Testf /% f/ /%  f/ /%      +f/\n", 78.50140, 0.1240002, 41782.1), F;
		ft_printf("ft_printf = Testf /% f/ /%  f/ /%      +f/\n\n\n", 78.50140, 0.1240002, 41782.1);

		printf("expected =  Testd /% d/ /%   d/ /% +d/\n", 3, 50412, -2145), F;
		ft_printf("ft_printf = Testd /% d/ /%   d/ /% +d/\n\n\n", 3, 50412, -2145);

		printf("expected =  Testi /% i/ /%   i/ /% +i/\n", 78, 364578, 0), F;
		ft_printf("ft_printf = Testi /% i/ /%   i/ /% +i/\n\n\n", 78, 364578, 0);

		printf("expected =  Testo /% o/ /%   o/ /% +o/\n", 0, 48, -78954), F;
		ft_printf("ft_printf = Testo /% o/ /%   o/ /% +o/\n\n\n", 0, 48, -78954);

		printf("expected =  Testu /% u/ /%   u/ /% +u/\n", 4215, -7584, 0), F;
		ft_printf("ft_printf = Testu /% u/ /%   u/ /% +u/\n\n\n", 4215, -7584, 0);

		printf("expected =  Testx /% x/ /%   x/ /% +x/\n", 789456, -45721, 0), F;
		ft_printf("ft_printf = Testx /% x/ /%   x/ /% +x/\n\n\n", 789456, -45721, 0);

		printf("expected =  TestX /% X/ /%   X/ /% +X/\n", 789456, -45721, 0), F;
		ft_printf("ft_printf = TestX /% X/ /%   X/ /% +X/\n\n\n", 789456, -45721, 0);

		//		TESTS %%


		//		TESTS hh

		printf("printf =    Test avec (hd) %hd test sans %d\n",457845, 457845), F;
		ft_printf("ft_printf = Test avec (hd) %hd test sans %d\n\n\n", 457845, 457845);

		printf("printf =    Test avec (hhd) %hhd test sans %d\n", 457845, 457845), F;
		ft_printf("ft_printf = Test avec (hhd) %hhd test sans %d\n\n\n", 457845, 457845);

		printf("printf =    Test avec (ld) %ld test sans %d\n",  4578453259999999999, 4578453259), F;
		ft_printf("ft_printf = Test avec (ld) %ld test sans %d\n\n\n",  4578453259999999999, 4578453259);

		printf("printf =    Test avec (lld) %lld test sans %d\n",  4578453259999999999, 4578453259), F;
		ft_printf("ft_printf = Test avec (lld) %lld test sans %d\n\n\n",  4578453259999999999, 4578453259);

		printf("printf =    Test avec (ho) %ho test sans %o\n",457845, 457845), F;
		ft_printf("ft_printf = Test avec (hd) %ho test sans %o\n\n\n", 457845, 457845);

		printf("printf =    Test avec (hhd) %hho test sans %o\n", 457845, 457845), F;
		ft_printf("ft_printf = Test avec (hhd) %hho test sans %o\n\n\n", 457845, 457845);

		printf("printf =    Test avec (ld) %lo test sans %o\n",  4578453259999999999, 4578453255), F;
		ft_printf("ft_printf = Test avec (ld) %lo test sans %o\n\n\n",  4578453259999999999, 4578453255);

		printf("printf =    Test avec (lld) %llo test sans %o\n",  4578453259999999999, 4578453259), F;
		ft_printf("ft_printf = Test avec (lld) %llo test sans %o\n\n\n",  4578453259999999999, 4578453259);

		printf("printf =    Test avec (hu) %hu test sans %u\n",457845, 457845), F;
		ft_printf("ft_printf = Test avec (hu) %hu test sans %u\n\n\n", 457845, 457845);

		printf("printf =    Test avec (hhu) %hhu test sans %u\n", 457845, 457845), F;
		ft_printf("ft_printf = Test avec (hhu) %hhu test sans %u\n\n\n", 457845, 457845);

		printf("printf =    Test avec (lu) %lu test sans %u\n",  4578453259999999999, 4578453255), F;
		ft_printf("ft_printf = Test avec (lu) %lu test sans %u\n\n\n",  4578453259999999999, 4578453255);

		printf("printf =    Test avec (llu) %llu test sans %u\n",  4578453259999999999, 4578453259), F;
		ft_printf("ft_printf = Test avec (llu) %llu test sans %u\n\n\n",  4578453259999999999, 4578453259);

		printf("printf =    Test avec (hx) %hx test sans %x\n",457845, 457845), F;
		ft_printf("ft_printf = Test avec (hx) %hx test sans %x\n\n\n", 457845, 457845);

		printf("printf =    Test avec (hhx) %hhx test sans %x\n", 457845, 457845), F;
		ft_printf("ft_printf = Test avec (hhx) %hhx test sans %x\n\n\n", 457845, 457845);

		printf("printf =    Test avec (lx) %lx test sans %x\n",  4578453259999999999, 4578453255), F;
		ft_printf("ft_printf = Test avec (lx) %lx test sans %x\n\n\n",  4578453259999999999, 4578453255);

		printf("printf =    Test avec (llx) %llx test sans %x\n",  4578453259999999999, 4578453259) ,F;
		ft_printf("ft_printf = Test avec (llx) %llx test sans %x\n\n\n",  4578453259999999999, 4578453259);

		printf("printf =    Test avec (hX) %hX test sans %X\n",457845, 457845), F;
		ft_printf("ft_printf = Test avec (hX) %hX test sans %X\n\n\n", 457845, 457845);

		printf("printf =    Test avec (hhX) %hhX test sans %X\n", 457845, 457845), F;
		ft_printf("ft_printf = Test avec (hhX) %hhX test sans %X\n\n\n", 457845, 457845);

		printf("printf =    Test avec (lX) %lX test sans %X\n",  4578453259999999999, 4578453255), F;
		ft_printf("ft_printf = Test avec (lX) %lX test sans %X\n\n\n",  4578453259999999999, 4578453255);

		printf("printf =    Test avec (llX) %llX test sans %X\n",  4578453259999999999, 4578453259), F;
		ft_printf("ft_printf = Test avec (llX) %llX test sans %X\n\n\n",  4578453259999999999, 4578453259);

		printf("printf =    Test avec (lf) %lf test sans %f\n",  4578453259999999999.45421, 4578453255.45421), F;
		ft_printf("ft_printf = Test avec (lf) %lf test sans %f\n\n\n",  4578453259999999999.45421, 4578453255.45421);

	}
	// TEST FLAGS l ll h hh L

	// sur les %d
	//  ------------------------ ANCIENNE PARTIE 1 ------------------------------------
	if (test_part2 == 1)
	{
		printf("v- lalalalala %d\n", 10), F;
		ft_printf("f- lalalalala %d\n", 10);
		printf("v- /%5%/\n"), F;
		ft_printf("f- /%5%/\n");
		printf("v- /%-5%/\n"), F;
		ft_printf("f- /%-5%/\n");
		printf("v- /%.0%/\n"), F;
		ft_printf("f- /%.0%/\n");
		printf("v- /%   %/\n", "test"), F;
		ft_printf("f- /%   %/\n", "test");
		printf("v- /%#x/ /%#x/\n", 0, 5), F;
		ft_printf("f- /%#x/ /%#x/\n", 0, 5);
		printf("v- /%#04x/\n", 42), F;
		ft_printf("f- /%#04x/\n", 42);
		printf("v- /%#-08x/\n", 42), F;
		ft_printf("f- /%#-08x/\n", 42);
		printf("v- /@moulitest: /%#.x/ /%#.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%#.x/ /%#.0x/\n", 0, 0);
		printf("v- /@moulitest: /%.x/ /%.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%.x/ /%.0x/\n", 0, 0);
		printf("v- /@moulitest: /%s/\n", NULL), F;
		ft_printf("f- /@moulitest: /%s/\n", NULL);
		printf("v- /%.2c/\n", NULL), F;
		ft_printf("f- /%.2c/\n", NULL);
		printf("v- /%s %s/\n", NULL, string), F;
		ft_printf("f- /%s %s/\n", NULL, string);
		printf("v- /@moulitest: /%c//\n", 0), F;
		ft_printf("f- /@moulitest: /%c//\n", 0);
		printf("v- /%2c/\n", 0), F;
		ft_printf("f- /%2c/\n", 0);
		printf("v- /null %c and text/\n", 0), F;
		ft_printf("f- /null %c and text/\n", 0);
		printf("v- /% c/\n", 0), F;
		ft_printf("f- /% c/\n", 0);
		printf("v- /%-05o/\n", 2500), F;
		ft_printf("f- /%-05o/\n", 2500);
		printf("v- /@moulitest: /%.o/ /%5.0o/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%.o/ /%5.0o/\n", 0, 0);
		printf("v- /@moulitest: /%5.o/ /%5.0o/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%5.o/ /%5.0o/\n", 0, 0);
		printf("v- /@moulitest: /%#.o/ /%#.0o/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%#.o/ /%#.0o/\n", 0, 0);
		printf("v- /@moulitest: /%.x/ /%.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%.x/ /%.0x/\n", 0, 0);
		printf("v- /@moulitest: /%5.x/ /%5.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%5.x/ /%5.0x/\n", 0, 0);
		printf("v- /@moulitest: /%#.x/ /%#.0x/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%#.x/ /%#.0x/\n", 0, 0);
		printf("v- /% d/\n", -42), F;
		ft_printf("f- /% d/\n", -42);
		printf("v- /%05d/\n", -42), F;
		ft_printf("f- /%05d/\n", -42);
		printf("v- /%0+5d/\n", -42), F;
		ft_printf("f- /%0+5d/\n", -42);
		printf("v- /%-05d/\n", 42), F;
		ft_printf("f- /%-05d/\n", 42);
		printf("v- /%-05d/\n", -42), F;
		ft_printf("f- /%-05d/\n", -42);
		printf("v- /%hd/\n", 32768), F;
		ft_printf("f- /%hd/\n", 32768);
		printf("v- /%hhd/\n", 128), F;
		ft_printf("f- /%hhd/\n", 128);
		printf("v- /%hhd/\n", -129), F;
		ft_printf("f- /%hhd/\n", -129);
		printf("v- /%lld/\n", -9223372036854775808), F;
		ft_printf("f- /%lld/\n", -9223372036854775808);
		printf("v- /%03.2d/\n", -1), F;
		ft_printf("f- /%03.2d/\n", -1);
		printf("v- /@moulitest: %.10d/\n", -42), F;
		ft_printf("f- /@moulitest: %.10d/\n", -42);
		printf("v- /@moulitest: /%.d/ /%.0d/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%.d/ /%.0d/\n", 0, 0);
		printf("v- /@moulitest: /%5.d/ /%5.0d/\n", 0, 0), F;
		ft_printf("f- /@moulitest: /%5.d/ /%5.0d/\n", 0, 0);
		printf("v- /% u/\n", 4294967295), F;
		ft_printf("f- /% u/\n", 4294967295);
		printf("v- /%+u/\n", 4294967295), F;
		ft_printf("f- /%+u/\n", 4294967295);

		printf("-->"), F;
		printf(" ==> [%d] ", printf("%")), F;
		printf("<--\n"), F;
		printf("-->"), F;
		printf(" ==> [%d] ", ft_printf("%")), F;
		printf("<--\n"), F;

		printf("v - {%c}\n", 0), F;
		ft_printf("f - {%c}\n", 0);
		printf("v- {%3c}\n", 0), F;
		ft_printf("f- {%3c}\n", 0);
		printf("v- {%03c}\n", 0), F;
		ft_printf("f- {%03c}\n", 0);
		printf("v- {%+c}\n", 0), F;
		ft_printf("f- {%+c}\n", 0);
		printf("v- {% c}\n", 0), F;
		ft_printf("f- {% c}\n", 0);
		printf("v - {%05.c}\n", 0), F;
		ft_printf("f - {%05.c}\n", 0);

		printf("v - bonjour /%c/ ca va /%c/ ?\n", 0, 0), F;
		ft_printf("f - bonjour /%c/ ca va /%c/ ?\n", 0, 0);

		printf(" --> [%d]\n", printf("v - {%c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f - {%c}", 0));
		printf(" --> [%d]\n", printf("v- {%3c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f- {%3c}", 0));
		printf(" --> [%d]\n", printf("v- {%03c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f- {%03c}", 0));
		printf(" --> [%d]\n", printf("v- {%+c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f- {%+c}", 0));
		printf(" --> [%d]\n", printf("v- {% c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f- {% c}", 0));
		printf(" --> [%d]\n", printf("v - {%05.c}", 0)), F;
		printf(" --> [%d]\n", ft_printf("f - {%05.c}", 0));

		printf("v - {%s}\n", 0), F;
		ft_printf("f - {%s}\n", 0);
		printf("v- {%3s}\n", 0), F;
		ft_printf("f- {%3s}\n", 0);
		printf("v- {%03s}\n", 0), F;
		ft_printf("f- {%03s}\n", 0);
		printf("v- {%+s}\n", 0), F;
		ft_printf("f- {%+s}\n", 0);
		printf("v- {% s}\n", 0), F;
		ft_printf("f- {% s}\n", 0);
		printf("v - {%05.s}\n", 0), F;
		ft_printf("f - {%05.s}\n", 0);
		printf("v - {%05s}\n", 0), F;
		ft_printf("f - {%05s}\n", 0);
		printf("v - {%03.s}\n", 0), F;
		ft_printf("f - {%03.s}\n", 0);
		printf("v - {%05.s}\n", "bouuuuh"), F;
		ft_printf("f - {%05.s}\n", "bouuuuh");
		printf("v - {%05s}\n", "ha"), F;
		ft_printf("f - {%05s}\n", "ha");
		printf("v - {%03.s}\n", "mais pourquoi?"), F;
		ft_printf("f - {%03.s}\n", "mais pourquoi?");
		printf("v - {%05.10s}\n", 0), F;
		ft_printf("f - {%05.10s}\n", 0);
		printf("v - {%05s}\n", 0), F;
		ft_printf("f - {%05s}\n", 0);
		printf("v - {%03.4s}\n", 0), F;
		ft_printf("f - {%03.4s}\n", 0);



		printf("v- %o, %ho, %hho\n", -42, -42, -42), F;
		ft_printf("f- %o, %ho, %hho\n", -42, -42, -42);

		printf("v- /%4.s/\n", "42"), F;
		ft_printf("f- /%4.s/\n", "42");

		printf("v- %+- Z0#10.50hhd\n", 42),fflush(stdout);
		ft_printf("f- %+- Z0#10.50hhd\n", 42);
		printf("v - /% +10.5hZhdoooo/\n", 42), fflush(stdout);
		ft_printf("f - /% +10.5hZhdoooo/\n", 42);

		printf("valeur de retour = %d\n", printf("@moulitest: ->%.o<- ->%.0o<-/\n", 0, 0)), F;
		ft_printf("valeur de retour = %d\n", ft_printf("@moulitest: ->%.o<- ->%.0o<-/\n", 0, 0));

		printf("v- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- \n/%lf/\n", 0.0, 2147483647.1234567891011, -2147483648.1234567891011, -1.0, 50.0, -9223372036854775807.0), F;
		ft_printf("f- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- \n/%f/\n", 0.0, 2147483647.1234567891011, -2147483648.1234567891011, -1.0, 50.0, -9223372036854775807.0);


		printf("@moulitest: /%.d/ /%.0d/\n", 0, 0), F;
		ft_printf("@moulitest: /%.d/ /%.0d/\n", 0, 0);
	}
	//	-------------------- ANCIENNE PARTIE 2 ------------------------------------

	if (test_part3 == 1)
	{
		// test des limites

		printf("-v UCHAR_MAX = %d\n", UCHAR_MAX), F;
		ft_printf("-f UCHAR_MAX = %d\n", UCHAR_MAX);

		printf("-v USHRT_MAX = %d\n", USHRT_MAX), F;
		ft_printf("-f USHRT_MAX = %d\n", USHRT_MAX);

		printf("v- The number of bits in a byte %d\n", CHAR_BIT), F;
		ft_printf("f- The number of bits in a byte %d\n", CHAR_BIT);

		printf("v- The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN), F;
		ft_printf("f- The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
		printf("v- The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX), F;
		ft_printf("f- The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
		printf("v- The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX), F;
		ft_printf("f- The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

		printf("v- The minimum value of SHORT INT = %d\n", SHRT_MIN), F;
		ft_printf("f- The minimum value of SHORT INT = %d\n", SHRT_MIN);
		printf("v- The maximum value of SHORT INT = %d\n", SHRT_MAX), F;
		ft_printf("f- The maximum value of SHORT INT = %d\n", SHRT_MAX);

		printf("v- The minimum value of INT = %d\n", INT_MIN), F;
		ft_printf("f- The minimum value of INT = %d\n", INT_MIN);
		printf("v- The maximum value of INT = %d\n", INT_MAX), F;
		ft_printf("f- The maximum value of INT = %d\n", INT_MAX);

		printf("v- The minimum value of CHAR = %d\n", CHAR_MIN), F;
		ft_printf("f- The minimum value of CHAR = %d\n", CHAR_MIN);
		printf("v- The maximum value of CHAR = %d\n", CHAR_MAX), F;
		ft_printf("f- The maximum value of CHAR = %d\n", CHAR_MAX);

		printf("v- The minimum value of LONG = %ld\n", LONG_MIN), F;
		ft_printf("f- The minimum value of LONG = %ld\n", LONG_MIN);
		printf("v- The maximum value of LONG = %ld\n", LONG_MAX), F;
		ft_printf("f- The maximum value of LONG = %ld\n", LONG_MAX);

		//TEST DES H L LL

		// sur les %d
		printf("\n\nTEST DES H L LL\n"), F;
		printf("\n\nSUR LES d\n"), F;
		printf("TEST VALEUR SHORT\n"), F;
		printf("zeroshort = %hd // short1 = %hd // short2 = %hd // short_max = %hd // short_min = %hd\n", zeroshort, short1, short2, short_max, short_min), F;
		ft_printf("zeroshort = %hd // short1 = %hd // short2 = %hd // short_max = %hd // short_min = %hd\n", zeroshort, short1, short2, short_max, short_min);

		printf("TEST VALEUR INT\n"), F;
		printf("zeroint = %d // int1 = %d // int2 = %d // int_max = %d // int_min = %d\n", zeroint, int1, int2, int_max, int_min), F;
		ft_printf("zeroint = %d // int1 = %d // int2 = %d // int_max = %d // int_min = %d\n", zeroint, int1, int2, int_max, int_min);

		printf("TEST VALEUR LONG\n"), F;
		printf("zerolong = %ld // long1 = %ld // long2 = %ld // long_max = %ld // long_min = %ld\n", zerolong, long1, long2, long_max, long_min), F;
		ft_printf("zerolong = %ld // long1 = %ld // long2 = %ld // long_max = %ld // long_min = %ld\n", zerolong, long1, long2, long_max, long_min);

		printf("TEST VALEUR LONG LONG\n"), F;
		printf("zerolonglong = %lld // longlong1 = %lld // longlong2 = %lld // longlong_max = %lld // longlong_min = %lld\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min), F;
		ft_printf("zerolonglong = %lld // longlong1 = %lld // longlong2 = %lld // longlong_max = %lld // longlong_min = %lld\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);

		// sur les %o


		printf("\n\nSUR LES o\n"), F;
		printf("\nTEST VALEUR SHORT SUR CONVERSION o\n"), F;
		printf("zeroshort = %ho // short1 = %ho // short2 = %ho // short_max = %ho // short_min = %ho\n", zeroshort, short1, short2, short_max, short_min), F;
		ft_printf("zeroshort = %ho // short1 = %ho // short2 = %ho // short_max = %ho // short_min = %ho\n", zeroshort, short1, short2, short_max, short_min);

		printf("\nTEST VALEUR INT SUR CONVERSION o\n"), F;
		printf("zeroint = %o // int1 = %o // int2 = %o // int_max = %o // int_min = %o\n", zeroint, int1, int2, int_max, int_min), F;
		ft_printf("zeroint = %o // int1 = %o // int2 = %o // int_max = %o // int_min = %o\n", zeroint, int1, int2, int_max, int_min);

		printf("\nTEST VALEUR LONG SUR CONVERSION o\n"), F;
		printf("zerolong = %lo // long1 = %lo // long2 = %lo // long_max = %lo // long_min = %lo\n", zerolong, long1, long2, long_max, long_min), F;
		ft_printf("zerolong = %lo // long1 = %lo // long2 = %lo // long_max = %lo // long_min = %lo\n", zerolong, long1, long2, long_max, long_min);

		printf("\nTEST VALEUR LONG LONG SUR CONVERSION o\n"), F;
		printf("zerolonglong = %llo // longlong1 = %llo // longlong2 = %llo // longlong_max = %llo // longlong_min = %llo\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min), F;
		ft_printf("zerolonglong = %llo // longlong1 = %llo // longlong2 = %llo // longlong_max = %llo // longlong_min = %llo\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);

		// sur les %x

		printf("\n\nSUR LES x\n"), F;
		printf("\nTEST VALEUR SHORT SUR CONVERSION x\n"), F;
		printf("zeroshort = %hx // short1 = %hx // short2 = %hx // short_max = %hx // short_min = %hx\n", zeroshort, short1, short2, short_max, short_min), F;
		ft_printf("zeroshort = %hx // short1 = %hx // short2 = %hx // short_max = %hx // short_min = %hx\n", zeroshort, short1, short2, short_max, short_min);

		printf("\nTEST VALEUR INT	SUR CONVERSION x\n"), F;
		printf("zeroint = %x // int1 = %x // int2 = %x // int_max = %x // int_min = %x\n", zeroint, int1, int2, int_max, int_min), F;
		ft_printf("zeroint = %x // int1 = %x // int2 = %x // int_max = %x // int_min = %x\n", zeroint, int1, int2, int_max, int_min);

		printf("\nTEST VALEUR LONG SUR CONVERSION x\n"), F;
		printf("zerolong = %lx // long1 = %lx // long2 = %lx // long_max = %lx // long_min = %lx\n", zerolong, long1, long2, long_max, long_min), F;
		ft_printf("zerolong = %lx // long1 = %lx // long2 = %lx // long_max = %lx // long_min = %lx\n", zerolong, long1, long2, long_max, long_min);

		printf("\nTEST VALEUR LONG LONG SUR CONVERSION x\n"), F;
		printf("zerolonglong = %llx // longlong1 = %llx // longlong2 = %llx // longlong_max = %llx // longlong_min = %llx\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min), F;
		ft_printf("zerolonglong = %llx // longlong1 = %llx // longlong2 = %llx // longlong_max = %llx // longlong_min = %llx\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);

		// sur les %u


		printf("\n\nSUR LES u\n"), F;
		printf("\nTEST VALEUR SHORT SUR CONVERSION u\n"), F;
		printf("zeroshort = %hu // short1 = %hu // short2 = %hu // short_max = %hu // short_min = %hu\n", zeroshort, short1, short2, short_max, short_min), F;
		ft_printf("zeroshort = %hu // short1 = %hu // short2 = %hu // short_max = %hu // short_min = %hu\n", zeroshort, short1, short2, short_max, short_min);

		printf("\nTEST VALEUR INT SUR CONVERSION u\n"), F;
		printf("zeroint = %u // int1 = %u // int2 = %u // int_max = %u // int_min = %u\n", zeroint, int1, int2, int_max, int_min), F;
		ft_printf("zeroint = %u // int1 = %u // int2 = %u // int_max = %u // int_min = %u\n", zeroint, int1, int2, int_max, int_min);

		printf("\nTEST VALEUR LONG SUR CONVERSION u\n"), F;
		printf("zerolong = %lu // long1 = %lu // long2 = %lu // long_max = %lu // long_min = %lu\n", zerolong, long1, long2, long_max, long_min), F;
		ft_printf("zerolong = %lu // long1 = %lu // long2 = %lu // long_max = %lu // long_min = %lu\n", zerolong, long1, long2, long_max, long_min);

		printf("\nTEST VALEUR LONG LONG SUR CONVERSION u\n"), F;
		printf("zerolonglong = %llu // longlong1 = %llu // longlong2 = %llu // longlong_max = %llu // longlong_min = %llu\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min), F;
		ft_printf("zerolonglong = %llu // longlong1 = %llu // longlong2 = %llu // longlong_max = %llu // longlong_min = %llu\n", zerolonglong, longlong1, longlong2, longlong_max, longlong_min);

		// sur les %f

		printf("\n\nSUR LES f\n"), F;


		printf("valeur ==>[%d] -- \n", printf("/%-+10f/", crash_float)), F;
		printf("valeur ==>[%d] -- \n", ft_printf("/%-+10f/", crash_float)), F;
		printf("valeur ==>[%d] -- \n", printf("/%-+10f/", crash_float2)), F;
		printf("valeur ==>[%d] -- \n", ft_printf("/%-+10f/", crash_float2)), F;

		printf("/%-+10f/\n", crash_float), F;
		ft_printf("/%-+10f/\n\n", crash_float);

		printf("/%-+10f/\n", crash_float2), F;
		ft_printf("/%-+10f/\n\n", crash_float2);

		printf("/%+10f/\n", crash_float), F;
		ft_printf("/%+10f/\n\n", crash_float);

		printf("/%+10f/\n", crash_float2), F;
		ft_printf("/%+10f/\n\n", crash_float2);

		printf("/%-10f/\n", crash_float), F;
		ft_printf("/%-10f/\n\n", crash_float);

		printf("/%-10f/\n", crash_float2), F;
		ft_printf("/%-10f/\n\n", crash_float2);

		printf("/%10f/\n", crash_float2), F;
		ft_printf("/%10f/\n\n", crash_float2);

		printf("/%f/\n", crash_float), F;
		ft_printf("/%f/\n\n", crash_float);

		// sur les %f

		printf("v- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/\n", t_f1, t_f2, t_f3, t_f4, t_f5, t_f6, t_f7, -5.6), F;
		ft_printf("f- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/\n", t_f1, t_f2, t_f3, t_f4, t_f5, t_f6, t_f7, -5.6);

		printf("v- /%.9Lf/\n", t_f), F;
		ft_printf("f- /%.9Lf/\n", t_f);

		printf("v- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/\n", 0.0, 2147483647.1234567891011, -2147483648.1234567891011, -1.0, 50.0, -9223372036854775807.123456789), F;
		ft_printf("f- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/ -- /%f/\n", 0.0, 2147483647.1234567891011, -2147483648.1234567891011, -1.0, 50.0, -9223372036854775807.123456789);

		printf("v - /%x/ -- /%#x/ \n", t_bit, t_bit), F;
		ft_printf("f - /%x/ -- /%#x/ \n", t_bit, t_bit);
		ft_printf("f - /%#.Lf/\n", t_f8);
		printf("v - /%#.Lf/\n", t_f8), F;


		// TEST DES HH


		printf("\n\nTEST DES HH\n"), F;
		printf("/%hhd/ -- /%hho/ -- /%hhu/ -- /%hhx/\n", hh_test, hh_test, hh_test, hh_test), F;
		ft_printf("/%hhd/ -- /%hho/ -- /%hhu/ -- /%hhx/\n", hh_test, hh_test, hh_test, hh_test);


		//  TEST FLAGS 0 + - ' ' #


		printf("\n\nTEST SUR LES FLAGS 0 ' ' + _ #\n"), F;
		// sur les %o

		// ----------- TEST FLAG HASH -----------

		printf("\n\n Test on %%o\nTESTS FLAG HASH\n"), F;
		printf("v- rien /%o/\n", t_o), F;
		ft_printf("f- rien /%o/\n", t_o);
		printf("v- seul /%#o/\n", t_o), F;
		ft_printf("f- seul /%#o/\n", t_o);
		printf("v- avec size /%#10o/\n", t_o), F;
		ft_printf("f- avec size /%#10o/\n", t_o);
		printf("v- size > accu /%#10.5o/\n", t_o), F;
		ft_printf("f- size > accu /%#10.5o/\n", t_o);
		printf("v- size < accu /%#5.10o/\n", t_o), F;
		ft_printf("f- size < accu /%#5.10o/\n", t_o);

		printf("\n\n TESTS FLAG MINUS\n"), F;
		printf("v- rien /%-o/\n", t_o), F;
		ft_printf("f- rien /%-o/\n", t_o);
		printf("v- seul /%-o/\n", t_o), F;
		ft_printf("f- seul /%-o/\n", t_o);
		printf("v- avec size /%-10o/\n", t_o), F;
		ft_printf("f- avec size /%-10o/\n", t_o);
		printf("v- size > accu /%o/ /%-o/ /%-10o/ /%-10.o/ /%-10.5o/\n", t_o, t_o, t_o, t_o, t_o), F;
		ft_printf("f- size > accu /%o/ /%-o/ /%-10o/ /%-10.o/ /%-10.5o/\n", t_o, t_o, t_o, t_o, t_o);
		printf("v- size < accu /%o/ /%-o/ /%-5o/ /%-5.o/ /%-5.10o/\n", t_o, t_o, t_o, t_o, t_o), F;
		ft_printf("f- size < accu /%o/ /%-o/ /%-5o/ /%-5.o/ /%-5.10o/\n", t_o, t_o, t_o, t_o, t_o);


		printf("\n\n TESTS FLAG MINUS AND HASH\n"), F;
		printf("v- rien /%#-o/\n", t_o), F;
		ft_printf("f- rien /%#-o/\n", t_o);
		printf("v- seul /%#-o/\n", t_o), F;
		ft_printf("f- seul /%#-o/\n", t_o);
		printf("v- avec size /%#-10o/\n", t_o), F;
		ft_printf("f- avec size /%#-10o/\n", t_o);
		printf("v- size > accu /%#-10.5o/\n", t_o), F;
		ft_printf("f- size > accu /%#-10.5o/\n", t_o);
		printf("v- size < accu /%#-5.10o/\n", t_o), F;
		ft_printf("f- size < accu /%#-5.10o/\n", t_o);

		//	sur les %x
	}
	// ----------- TEST FLAG HASH -----------

	if (test_part4 == 1)
	{
		printf("\n\n Test on %%x\nTESTS FLAG HASH\n"), F;
		printf("v- rien /%x/\n", t_x), F;
		ft_printf("f- rien /%x/\n", t_x);
		printf("v- seul /%#x/\n", t_x), F;
		ft_printf("f- seul /%#x/\n", t_x);
		printf("v- avec size /%#10x/\n", t_x), F;
		ft_printf("f- avec size /%#10x/\n", t_x);
		printf("v- size > accu /%#10.5x/\n", t_x), F;
		ft_printf("f- size > accu /%#10.5x/\n", t_x);
		printf("v- size < accu /%#5.10x/\n", t_x), F;
		ft_printf("f- size < accu /%#5.10x/\n", t_x);
		printf("v- rien /%-x/\n", t_x), F;
		ft_printf("f- rien /%-x/\n", t_x);
		printf("v- seul /%-x/\n", t_x), F;
		ft_printf("f- seul /%-x/\n", t_x);
		printf("v- avec size /%-10x/\n", t_x), F;
		ft_printf("f- avec size /%-10x/\n", t_x);
		printf("v- size > accu /%-10.5x/\n", t_x), F;
		ft_printf("f- size > accu /%-10.5x/\n", t_x);
		printf("v- size < accu /%-5.10x/\n", t_x), F;
		ft_printf("f- size < accu /%-5.10x/\n", t_x);
		printf("v- rien /%#-x/\n", t_x), F;
		ft_printf("f- rien /%#-x/\n", t_x);
		printf("v- seul /%#-x/\n", t_x), F;
		ft_printf("f- seul /%#-x/\n", t_x);
		printf("v- avec size /%#-10x/\n", t_x), F;
		ft_printf("f- avec size /%#-10x/\n", t_x);
		printf("v- size > accu /%#-10.5x/\n", t_x), F;
		ft_printf("f- size > accu /%#-10.5x/\n", t_x);
		printf("v- size < accu /%#-5.10x/\n", t_x), F;
		ft_printf("f- size < accu /%#-5.10x/\n", t_x);

		//	sur les %X

		// ----------- TEST FLAG HASH -----------


		printf("\n\n Test on %%X\nTESTS FLAG HASH\n"), F;
		printf("v- rien /%X/\n", t_X), F;
		ft_printf("f- rien /%X/\n", t_X);
		printf("v- seul /%#X/\n", t_X), F;
		ft_printf("f- seul /%#X/\n", t_X);
		printf("v- avec size /%#10X/\n", t_X), F;
		ft_printf("f- avec size /%#10X/\n", t_X);
		printf("v- size > accu /%#10.5X/\n", t_X), F;
		ft_printf("f- size > accu /%#10.5X/\n", t_X);
		printf("v- size < accu /%#5.10X/\n", t_X), F;
		ft_printf("f- size < accu /%#5.10X/\n", t_X);
		printf("v- rien /%-X/\n", t_X), F;
		ft_printf("f- rien /%-X/\n", t_X);
		printf("v- seul /%-X/\n", t_X), F;
		ft_printf("f- seul /%-X/\n", t_X);
		printf("v- avec size /%-10X/\n", t_X), F;
		ft_printf("f- avec size /%-10X/\n", t_X);
		printf("v- size > accu /%-10.5X/\n", t_X), F;
		ft_printf("f- size > accu /%-10.5X/\n", t_X);
		printf("v- size < accu /%-5.10X/\n", t_X), F;
		ft_printf("f- size < accu /%-5.10X/\n", t_X);
		printf("v- rien /%#-X/\n", t_X), F;
		ft_printf("f- rien /%#-X/\n", t_X);
		printf("v- seul /%#-X/\n", t_X), F;
		ft_printf("f- seul /%#-X/\n", t_X);
		printf("v- avec size /%#-10X/\n", t_X), F;
		ft_printf("f- avec size /%#-10X/\n", t_X);
		printf("v- size > accu /%#-10.5X/\n", t_X), F;
		ft_printf("f- size > accu /%#-10.5X/\n", t_X);
		printf("v- size < accu /%#-5.10X/\n", t_X), F;
		ft_printf("f- size < accu /%#-5.10X/\n", t_X);
		printf("v- size = accu /%#-10.10X/\n", t_X), F;
		ft_printf("f- size = accu /%#-10.10X/\n", t_X);

		// sur les %d

		// ----------- TEST FLAG PLUS ------------

		printf("\n\nTest on %%d\nTESTS FLAG PLUS\n"), F;
		printf("v- plus tout seul        /%+d/\n", t_d), F;
		ft_printf("f- plus tout seul        /%+d/\n", t_d);
		printf("v- plus avec size        /%+10d/\n", t_d), F;
		ft_printf("f- plus avec size        /%+10d/\n", t_d);
		printf("v- plus avec accu        /%+.5d/\n", t_d), F;
		ft_printf("f- plus avec accu        /%+.5d/\n", t_d);
		printf("v- plus avec size > accu /%+10.5d/\n", t_d), F;
		ft_printf("f- plus avec size > accu /%+10.5d/\n", t_d);
		printf("v- plus avec size < accu /%+5.10d/\n", t_d), F;
		ft_printf("f- plus avec size < accu /%+5.10d/\n", t_d);
		printf("v- plus avec size = accu /%+10.10d/\n", t_d), F;
		ft_printf("f- plus avec size = accu /%+10.10d/\n", t_d);

		// ------------ TEST FLAG ZERO --------------

		printf("\n\nTEST FLAG ZERO\n"), F;
		printf("v- zero tout seul            /%0d/\n", t_d), F;
		ft_printf("f- zero tout seul            /%0d/\n", t_d);
		printf("v- zero avec size            /%010d/\n", t_d), F;
		ft_printf("f- zero avec size            /%010d/\n", t_d);
		printf("v- zero avec accu            /%0.5d/\n", t_d), F;
		ft_printf("f- zero avec accu            /%0.5d/\n", t_d);
		printf("v- zero avec size > accu     /%010.5d/\n", t_d), F;
		ft_printf("f- zero avec size > accu     /%010.5d/\n", t_d);
		printf("v- zero avec size < accu     /%05.10d/\n", t_d), F;
		ft_printf("f- zero avec size < accu     /%05.10d/\n", t_d);
		printf("v- zero avec size = accu     /%010.10d/\n", t_d), F;
		ft_printf("f- zero avec size = accu     /%010.10d/\n", t_d);

		// ------------ TEST FLAG SPACE --------------

		printf("\n\nTEST FLAG SPACE\n"), F;
		printf("v- space tout seul            /% d/\n", t_d), F;
		ft_printf("f- space tout seul            /% d/\n", t_d);
		printf("v- space avec size            /% 10d/\n", t_d), F;
		ft_printf("f- space avec size            /% 10d/\n", t_d);
		printf("v- space avec accu            /% .5d/\n", t_d), F;
		ft_printf("f- space avec accu            /% .5d/\n", t_d);
		printf("v- space avec size > accu     /% 10.5d/\n", t_d), F;
		ft_printf("f- space avec size > accu     /% 10.5d/\n", t_d);
		printf("v- space avec size < accu     /% 5.10d/\n", t_d), F;
		ft_printf("f- space avec size < accu     /% 5.10d/\n", t_d);
		printf("v- space avec size = accu     /% 10.10d/\n", t_d), F;
		ft_printf("f- space avec size = accu     /% 10.10d/\n", t_d);

		// ------------- TEST FLAG MINUS ------------

		printf("\n\nTEST FLAG MINUS\n"), F;
		printf("v- minus tout seul            /%-d/\n", t_d), F;
		ft_printf("f- minus tout seul            /%-d/\n", t_d);
		printf("v- minus avec size            /%-10d/\n", t_d), F;
		ft_printf("f- minus avec size            /%-10d/\n", t_d);
		printf("v- minus avec accu            /%-.5d/\n", t_d), F;
		ft_printf("f- minus avec accu            /%-.5d/\n", t_d);
		printf("v- minus avec size > accu     /%-10.5d/\n", t_d), F;
		ft_printf("f- minus avec size > accu     /%-10.5d/\n", t_d);
		printf("v- minus avec size < accu     /%-5.10d/\n", t_d), F;
		ft_printf("f- minus avec size < accu     /%-5.10d/\n", t_d);
		printf("v- minus avec size = accu     /%-10.10d/\n", t_d), F;
		ft_printf("f- minus avec size = accu     /%-10.10d/\n", t_d);

		// ------------- TEST FLAG PLUS ZERO SPACE MINUS

		printf("\n\nTEST FLAG PLUS ZERO SPACE MINUS\n"), F;
		printf("v- plus et minus seuls            /%+-d/\n", t_d), F;
		ft_printf("f- plus et minus seuls            /%+-d/\n", t_d);
		printf("v- plus et minus avec size        /%+-10d/\n", t_d), F;
		ft_printf("f- plus et minus avec size        /%+-10d/\n", t_d);
		printf("v- plus et minus avec accu        /%+-.5d/\n", t_d), F;
		ft_printf("f- plus et minus avec accu        /%+-.5d/\n", t_d);
		printf("v- plus et minus avec size > accu /%+-10.5d/\n", t_d), F;
		ft_printf("f- plus et minus avec size > accu /%+-10.5d/\n", t_d);
		printf("v- plus et minus avec size < accu /%+-5.10d/\n", t_d), F;
		ft_printf("f- plus et minus avec size < accu /%+-5.10d/\n", t_d);
		printf("v- plus et minus avec size = accu /%+-10.10d/\n", t_d), F;
		ft_printf("f- plus et minus avec size = accu /%+-10.10d/\n", t_d);

		printf("\n2 by 2 ==> PLUS and ZERO\n"), F;
		printf("v- plus et zero seuls            /%+0d/\n", t_d), F;
		ft_printf("f- plus et zero seuls            /%+0d/\n", t_d);
		printf("v- plus et zero avec size        /%+010d/\n", t_d), F;
		ft_printf("f- plus et zero avec size        /%+010d/\n", t_d);
		printf("v- plus et zero avec accu        /%+0.5d/\n", t_d), F;
		ft_printf("f- plus et zero avec accu        /%+0.5d/\n", t_d);
		printf("v- plus et zero avec size > accu /%+010.5d/\n", t_d), F;
		ft_printf("f- plus et zero avec size > accu /%+010.5d/\n", t_d);
		printf("v- plus et zero avec size < accu /%+05.10d/\n", t_d), F;
		ft_printf("f- plus et zero avec size < accu /%+05.10d/\n", t_d);
		printf("v- plus et zero avec size = accu /%+010.10d/\n", t_d), F;
		ft_printf("f- plus et zero avec size = accu /%+010.10d/\n", t_d);

		printf("\n2 by 2 ==> MINUS and SPACE\n"), F;
		printf("v- minus et space seuls            /%- d/\n", t_d), F;
		ft_printf("f- minus et space seuls            /%- d/\n", t_d);
		printf("v- minus et space avec size        /%- 10d/\n", t_d), F;
		ft_printf("f- minus et space avec size        /%- 10d/\n", t_d);
		printf("v- minus et space avec accu        /%- .5d/\n", t_d), F;
		ft_printf("f- minus et space avec accu        /%- .5d/\n", t_d);
		printf("v- minus et space avec size > accu /%- 10.5d/\n", t_d), F;
		ft_printf("f- minus et space avec size > accu /%- 10.5d/\n", t_d);
		printf("v- minus et space avec size < accu /%- 5.10d/\n", t_d), F;
		ft_printf("f- minus et space avec size < accu /%- 5.10d/\n", t_d);
		printf("v- minus et space avec size = accu /%- 10.10d/\n", t_d), F;
		ft_printf("f- minus et space avec size = accu /%- 10.10d/\n", t_d);

		printf("\n2 by 2 ==> SPACE and ZERO \n"), F;
		printf("v- space et zero seuls            /% 0d/\n", t_d), F;
		ft_printf("f- space et zero seuls            /% 0d/\n", t_d);
		printf("v- space et zero avec size        /% 010d/\n", t_d), F;
		ft_printf("f- space et zero avec size        /% 010d/\n", t_d);
		printf("v- space et zero avec accu        /% 0.5d/\n", t_d), F;
		ft_printf("f- space et zero avec accu        /% 0.5d/\n", t_d);
		printf("v- space et zero avec size > accu /% 010.5d/\n", t_d), F;
		ft_printf("f- space et zero avec size > accu /% 010.5d/\n", t_d);
		printf("v- space et zero avec size < accu /% 05.10d/\n", t_d), F;
		ft_printf("f- space et zero avec size < accu /% 05.10d/\n", t_d);
		printf("v- space et zero avec size = accu /% 010.10d/\n", t_d), F;
		ft_printf("f- space et zero avec size = accu /% 010.10d/\n", t_d);

		// test sur les %u

		printf("\n\n TEST DES %%u"), F;
		printf("\n\nTEST SUR ZERO\n"), F;
		printf("v- zero tout seul            /%0u/\n", t_u), F;
		ft_printf("f- zero tout seul            /%0u/\n", t_u);
		printf("v- zero avec size            /%010u/\n", t_u), F;
		ft_printf("f- zero avec size            /%010u/\n", t_u);
		printf("v- zero avec accu            /%0.5u/\n", t_u), F;
		ft_printf("f- zero avec accu            /%0.5u/\n", t_u);
		printf("v- zero avec size > accu     /%010.5u/\n", t_u), F;
		ft_printf("f- zero avec size > accu     /%010.5u/\n", t_u);
		printf("v- zero avec size < accu     /%05.10u/\n", t_u), F;
		ft_printf("f- zero avec size < accu     /%05.10u/\n", t_u);
		printf("v- zero avec size = accu     /%010.10u/\n", t_u), F;
		ft_printf("f- zero avec size = accu     /%010.10u/\n", t_u);

		printf("\nTEST SUR MINUS\n"), F;
		printf("v- minus tout seul            /%-u/\n", t_u), F;
		ft_printf("f- minus tout seul            /%-u/\n", t_u);
		printf("v- minus avec size            /%-10u/\n", t_u), F;
		ft_printf("f- minus avec size            /%-10u/\n", t_u);
		printf("v- minus avec accu            /%-.5u/\n", t_u), F;
		ft_printf("f- minus avec accu            /%-.5u/\n", t_u);
		printf("v- minus avec size > accu     /%-10.5u/\n", t_u), F;
		ft_printf("f- minus avec size > accu     /%-10.5u/\n", t_u);
		printf("v- minus avec size < accu     /%-5.10u/\n", t_u), F;
		ft_printf("f- minus avec size < accu     /%-5.10u/\n", t_u);
		printf("v- minus avec size = accu     /%-10.10u/\n", t_u), F;
		ft_printf("f- minus avec size = accu     /%-10.10u/\n", t_u);


		//  sur les %c

		// ------------- TEST FLAG MINUS ------------

		printf("\n\nTest on %%c\n"), F;
		printf("TEST FLAG MINUS\n"), F;
		printf("v- minus tout seul            /%-c/\n", t_c),F;
		ft_printf("f- minus tout seul            /%-c/\n", t_c);
		printf("v- minus avec size            /%-10c/\n", t_c), F;
		ft_printf("f- minus avec size            /%-10c/\n", t_c);

		// sur les %s

		printf("\n\nTest on %%s\n"), F;

		printf("v- moins /%-s/\n", t_s), F;
		ft_printf("f- moins /%-s/\n", t_s);
		printf("v- size /%20s/\n", t_s), F;
		ft_printf("f- size /%20s/\n", t_s);
		printf("v- accu /%.5s/\n", t_s), F;
		ft_printf("f- accu /%.5s/\n", t_s);
		printf("v- size > accu /%20.5s/\n", t_s), F;
		ft_printf("f- size > accu /%20.5s/\n", t_s);
		printf("v- size < accu /%20.30s/\n", t_s), F;
		ft_printf("f- size < accu /%20.30s/\n", t_s);

		printf("v- moins et size /%-20s/\n", t_s), F;
		ft_printf("f- moins et size /%-20s/\n", t_s);
		printf("v- moins et accu /%.5s/\n", t_s), F;
		ft_printf("f- moins et accu /%.5s/\n", t_s);
		printf("v- moins et size > accu /%-20.5s/\n", t_s), F;
		ft_printf("f- moins et size > accu /%-20.5s/\n", t_s);
		printf("v- moins et size < accu /%-20.30s/\n", t_s), F;
		ft_printf("f- moins et size < accu /%-20.30s/\n", t_s);

		// RETURNED INT


		pointer_test = "bonjour";

		ft_printf("nombre rendu = |%d|\n", ft_printf("\n\nbonjour je rends un nombre %+d %+-d %10.5d hahahah\n", 42, 43, 44));
		printf("nombre rendu = |%d|\n", printf("\n\nbonjour je rends un nombre %+d %+-d %10.5d hahahah\n", 42, 43, 44)), F;


		ft_printf("%x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x \n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18);
		printf("%x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x / %x \n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18), F;
		ft_printf("test normaux, %% voila le %%d ->%d<- et le %%c ->%c<- et le %%s ->%s<- et le %%x ->%x<- et le %%p ->%p<- et le 0 ->%x<-\n", 42, 'A', "Coucou", 1024, pointer_test, 0);
		printf("test normaux, %% voila le %%d ->%d<- et le %%c ->%c<- et le %%s ->%s<- et le %%x ->%x<- et le %%p ->%p<- et le 0 ->%x<-\n", 42, 'A', "Coucou", 1024, pointer_test, 0), F;
		ft_printf("check des hexa sur 4 octets : %x /-/ %x /-/ %x\n", 1024, -1024, 2147483647);
		printf("check des hexa sur 4 octets : %x /-/ %x /-/ %x\n", 1024, -1024, 2147483647), F;
		ft_printf("check des hexa plus dur : %x /-/ %x /-/ %lx /-/ %x\n", 2147483647, -2147483647, 2147483656, -1);
		printf("check des hexa plus dur : %x /-/ %x /-/ %lx /-/ %x\n", 2147483647, -2147483647, 2147483656, -1), F;


		printf("\n\n Test on %%f\nTESTS FLAG HASH\n"), F;
		printf("v- rien /%f/\n", t_fl), F;
		ft_printf("f- rien /%f/\n", t_fl);
		printf("v- seul /%#f/\n", t_fl), F;
		ft_printf("f- seul /%#f/\n", t_fl);
		printf("v- avec size /%#10f/\n", t_fl), F;
		ft_printf("f- avec size /%#10f/\n", t_fl);
		printf("v- size > accu /%#10.5f/\n", t_fl), F;
		ft_printf("f- size > accu /%#10.5f/\n", t_fl);
		printf("v- size < accu /%#5.10f/\n", t_fl), F;
		ft_printf("f- size < accu /%#5.10f/\n", t_fl);

		printf("\n\n TESTS FLAG MINUS\n"), F;
		printf("v- rien /%-f/\n", t_fl), F;
		ft_printf("f- rien /%-f/\n", t_fl);
		printf("v- seul /%-f/\n", t_fl), F;
		ft_printf("f- seul /%-f/\n", t_fl);
		printf("v- avec size /%-10f/\n", t_fl), F;
		ft_printf("f- avec size /%-10f/\n", t_fl);
		printf("v- size > accu /%-10.5f/\n", t_fl), F;
		ft_printf("f- size > accu /%-10.5f/\n", t_fl);
		printf("v- size < accu /%-5.10f/\n", t_fl), F;
		ft_printf("f- size < accu /%-5.10f/\n", t_fl);

		printf("\n\n TESTS FLAG MINUS AND HASH\n"), F;
		printf("v- rien /%#-f/\n", t_fl), F;
		ft_printf("f- rien /%#-f/\n", t_fl);
		printf("v- seul /%#-f/\n", t_fl), F;
		ft_printf("f- seul /%#-f/\n", t_fl);
		printf("v- avec size /%#-10f/\n", t_fl), F;
		ft_printf("f- avec size /%#-10f/\n", t_fl);
		printf("v- size > accu /%#-10.5f/\n", t_fl), F;
		ft_printf("f- size > accu /%#-10.5f/\n", t_fl);
		printf("v- size < accu /%#-5.10f/\n", t_fl), F;
		ft_printf("f- size < accu /%#-5.10f/\n", t_fl);

		// ------------ TEST FLAG PLUS --------------

		printf("\n\nTest on %%d\nTESTS FLAG PLUS\n"), F;
		printf("v- plus tout seul        /%+f/\n", t_fl), F;
		ft_printf("f- plus tout seul        /%+f/\n", t_fl);
		printf("v- plus avec size        /%+10f/\n", t_fl), F;
		ft_printf("f- plus avec size        /%+10f/\n", t_fl);
		printf("v- plus avec accu        /%+.5f/\n", t_fl), F;
		ft_printf("f- plus avec accu        /%+.5f/\n", t_fl);
		printf("v- plus avec size > accu /%+10.5f/\n", t_fl), F;
		ft_printf("f- plus avec size > accu /%+10.5f/\n", t_fl);
		printf("v- plus avec size < accu /%+5.10f/\n", t_fl), F;
		ft_printf("f- plus avec size < accu /%+5.10f/\n", t_fl);
		printf("v- plus avec size = accu /%+10.10f/\n", t_fl), F;
		ft_printf("f- plus avec size = accu /%+10.10f/\n", t_fl);

		// ------------ TEST FLAG ZERO --------------

		printf("\n\nTEST FLAG ZERO\n"), F;
		printf("v- zero tout seul            /%0f/\n", t_fl), F;
		ft_printf("f- zero tout seul            /%0f/\n", t_fl);
		printf("v- zero avec size            /%010f/\n", t_fl), F;
		ft_printf("f- zero avec size            /%010f/\n", t_fl);
		printf("v- zero avec accu            /%0.5f/\n", t_fl), F;
		ft_printf("f- zero avec accu            /%0.5f/\n", t_fl);
		printf("v- zero avec size > accu     /%010.5f/\n", t_fl), F;
		ft_printf("f- zero avec size > accu     /%010.5f/\n", t_fl);
		printf("v- zero avec size < accu     /%05.10f/\n", t_fl), F;
		ft_printf("f- zero avec size < accu     /%05.10f/\n", t_fl);
		printf("v- zero avec size = accu     /%010.10f/\n", t_fl), F;
		ft_printf("f- zero avec size = accu     /%010.10f/\n", t_fl);

		// ------------ TEST FLAG SPACE --------------

		printf("\n\nTEST FLAG SPACE\n"), F;
		printf("v- space tout seul            /% f/\n", t_fl), F;
		ft_printf("f- space tout seul            /% f/\n", t_fl);
		printf("v- space avec size            /% 10f/\n", t_fl), F;
		ft_printf("f- space avec size            /% 10f/\n", t_fl);
		printf("v- space avec accu            /% .5f/\n", t_fl), F;
		ft_printf("f- space avec accu            /% .5f/\n", t_fl);
		printf("v- space avec size > accu     /% 10.5f/\n", t_fl), F;
		ft_printf("f- space avec size > accu     /% 10.5f/\n", t_fl);
		printf("v- space avec size < accu     /% 5.10f/\n", t_fl), F;
		ft_printf("f- space avec size < accu     /% 5.10f/\n", t_fl);
		printf("v- space avec size = accu     /% 10.10f/\n", t_fl), F;
		ft_printf("f- space avec size = accu     /% 10.10f/\n", t_fl);

		// ------------- TEST FLAG MINUS ------------

		printf("\n\nTEST FLAG MINUS\n"), F;
		printf("v- minus tout seul            /%-f/\n", t_fl), F;
		ft_printf("f- minus tout seul            /%-f/\n", t_fl);
		printf("v- minus avec size            /%-10f/\n", t_fl), F;
		ft_printf("f- minus avec size            /%-10f/\n", t_fl);
		printf("v- minus avec accu            /%-.5f/\n", t_fl), F;
		ft_printf("f- minus avec accu            /%-.5f/\n", t_fl);
		printf("v- minus avec size > accu     /%-10.5f/\n", t_fl), F;
		ft_printf("f- minus avec size > accu     /%-10.5f/\n", t_fl);
		printf("v- minus avec size < accu     /%-5.10f/\n", t_fl), F;
		ft_printf("f- minus avec size < accu     /%-5.10f/\n", t_fl);
		printf("v- minus avec size = accu     /%-10.10f/\n", t_fl), F;
		ft_printf("f- minus avec size = accu     /%-10.10f/\n", t_fl);

		// ------------- TEST FLAG PLUS ZERO SPACE MINUS

		printf("\n\nTEST FLAG PLUS ZERO SPACE MINUS\n"), F;
		printf("v- plus et minus seuls            /%+-f/\n", t_fl), F;
		ft_printf("f- plus et minus seuls            /%+-f/\n", t_fl);
		printf("v- plus et minus avec size        /%+-10f/\n", t_fl), F;
		ft_printf("f- plus et minus avec size        /%+-10f/\n", t_fl);
		printf("v- plus et minus avec accu        /%+-.5f/\n", t_fl), F;
		ft_printf("f- plus et minus avec accu        /%+-.5f/\n", t_fl);
		printf("v- plus et minus avec size > accu /%+-10.5f/\n", t_fl), F;
		ft_printf("f- plus et minus avec size > accu /%+-10.5f/\n", t_fl);
		printf("v- plus et minus avec size < accu /%+-5.10f/\n", t_fl), F;
		ft_printf("f- plus et minus avec size < accu /%+-5.10f/\n", t_fl);
		printf("v- plus et minus avec size = accu /%+-10.10f/\n", t_fl), F;
		ft_printf("f- plus et minus avec size = accu /%+-10.10f/\n", t_fl);

		printf("\n2 by 2 ==> PLUS and ZERO\n"), F;
		printf("v- plus et zero seuls            /%+0f/\n", t_fl), F;
		ft_printf("f- plus et zero seuls            /%+0f/\n", t_fl);
		printf("v- plus et zero avec size        /%+010f/\n", t_fl), F;
		ft_printf("f- plus et zero avec size        /%+010f/\n", t_fl);
		printf("v- plus et zero avec accu        /%+0.5f/\n", t_fl), F;
		ft_printf("f- plus et zero avec accu        /%+0.5f/\n", t_fl);
		printf("v- plus et zero avec size > accu /%+010.5f/\n", t_fl), F;
		ft_printf("f- plus et zero avec size > accu /%+010.5f/\n", t_fl);
		printf("v- plus et zero avec size < accu /%+05.10f/\n", t_fl), F;
		ft_printf("f- plus et zero avec size < accu /%+05.10f/\n", t_fl);
		printf("v- plus et zero avec size = accu /%+010.10f/\n", t_fl), F;
		ft_printf("f- plus et zero avec size = accu /%+010.10f/\n", t_fl);

		printf("\n2 by 2 ==> MINUS and SPACE\n"), F;
		printf("v- minus et space seuls            /%- f/\n", t_fl), F;
		ft_printf("f- minus et space seuls            /%- f/\n", t_fl);
		printf("v- minus et space avec size        /%- 10f/\n", t_fl), F;
		ft_printf("f- minus et space avec size        /%- 10f/\n", t_fl);
		printf("v- minus et space avec accu        /%- .5f/\n", t_fl), F;
		ft_printf("f- minus et space avec accu        /%- .5f/\n", t_fl);
		printf("v- minus et space avec size > accu /%- 10.5f/\n", t_fl), F;
		ft_printf("f- minus et space avec size > accu /%- 10.5f/\n", t_fl);
		printf("v- minus et space avec size < accu /%- 5.10f/\n", t_fl), F;
		ft_printf("f- minus et space avec size < accu /%- 5.10f/\n", t_fl);
		printf("v- minus et space avec size = accu /%- 10.10f/\n", t_fl), F;
		ft_printf("f- minus et space avec size = accu /%- 10.10f/\n", t_fl);

		printf("\n2 by 2 ==> SPACE and ZERO \n"), F;
		printf("v- space et zero seuls            /% 0f/\n", t_fl), F;
		ft_printf("f- space et zero seuls            /% 0f/\n", t_fl);
		printf("v- space et zero avec size        /% 010f/\n", t_fl), F;
		ft_printf("f- space et zero avec size        /% 010f/\n", t_fl);
		printf("v- space et zero avec accu        /% 0.5f/\n", t_fl), F;
		ft_printf("f- space et zero avec accu        /% 0.5f/\n", t_fl);
		printf("v- space et zero avec size > accu /% 010.5f/\n", t_fl), F;
		ft_printf("f- space et zero avec size > accu /% 010.5f/\n", t_fl);
		printf("v- space et zero avec size < accu /% 05.10f/\n", t_fl), F;
		ft_printf("f- space et zero avec size < accu /% 05.10f/\n", t_fl);
		printf("v- space et zero avec size = accu /% 010.10f/\n", t_fl), F;
		ft_printf("f- space et zero avec size = accu /% 010.10f/\n\n", t_fl);

		printf("%%%%%%%\n"), F;
		ft_printf("%%%%%%%");
		printf("\n\n");
	}
	if (test_part5)
	{
		nb = 0;
		ft_printf("null prec : %+.0f\n", nb);
		dprintf(2, "null prec : %+.0f\n", nb);
		nb = 12.5;
		ft_printf("null prec : %+.0f\n", nb);
		dprintf(2, "null prec : %+.0f\n", nb);
		nb = -25632.2541;
		ft_printf("null prec : %+.0f\n", nb);
		dprintf(2, "null prec : %+.0f\n", nb);
		nb = -1.0123;
		ft_printf("null prec : %+.0f\n", nb);
		dprintf(2, "null prec : %+.0f\n", nb);
		nb = 12354.569874;
		ft_printf("null prec : %+.0f\n", nb);
		dprintf(2, "null prec : %+.0f\n\n", nb);

		nb = 1.0/0.0;
		ft_printf("%f\n", nb);
		dprintf(2,"%f\n", nb);
		ft_printf("%12f\n", nb);
		dprintf(2,"%12f\n", nb);
		ft_printf("%-12f\n", nb);
		dprintf(2,"%-12f\n", nb);
		ft_printf("%5.9f\n", nb);
		dprintf(2,"%5.9f\n", nb);

		nb = -1.0/0.0;
		ft_printf("%f\n", nb);
		dprintf(2,"%f\n", nb);
		ft_printf("%12f\n", nb);
		dprintf(2,"%12f\n", nb);
		ft_printf("%-12f\n", nb);
		dprintf(2,"%-12f\n", nb);
		ft_printf("%5.9f\n", nb);
		dprintf(2,"%5.9f\n", nb);

		nb = 0.0/0.0;
		ft_printf("%f\n", nb);
		dprintf(2,"%f\n", nb);
		ft_printf("%12f\n", nb);
		dprintf(2,"%12f\n", nb);
		ft_printf("%-12f\n", nb);
		dprintf(2,"%-12f\n", nb);
		ft_printf("%5.9f\n", nb);
		dprintf(2,"%5.9f\n\n", nb);

		nb = -0.000;

		ft_printf("space:% f\n", nb);
		dprintf(2, "space:% f\n", nb);
	}
	return (0);
}
