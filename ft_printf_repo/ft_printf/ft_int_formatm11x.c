/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_formatm11x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:11:20 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/11 16:24:46 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_formatm110(long long nb, char *base, int blen, t_st *st)
{
	int		i;
	int		diff1;
	int		diff2;
	int		diff3;

	i = 0;
	diff1 = st->size - st->precision;
	diff2 = st->size - st->len;
	diff3 = st->precision - st->len;
	if (st->precision > st->len)
	{
		while (i < diff3)
			i += ft_putchar_inc('0', st);
		i = 0;
		ft_putnbr_base(nb, base, blen, st);
		while (i < diff1)
			i += ft_putchar_inc(' ', st);
	}
	else
	{
		ft_putnbr_base(nb, base, blen, st);
		while (i < diff2)
			i += ft_putchar_inc(' ', st);
	}
}

void	ft_int_formatm111(long long nb, char *base, int blen, t_st *st)
{
	int		i;
	int		diff3;

	i = 0;
	diff3 = st->precision - st->len;
	while (i < diff3)
		i += ft_putchar_inc('0', st);
	ft_putnbr_base(nb, base, blen, st);
}

void	ft_int_formatm112(long long nb, char *base, int blen, t_st *st)
{
	int		i;
	int		diff1;
	int		diff2;
	int		diff3;

	i = 0;
	diff1 = st->size - st->precision;
	diff2 = st->size - st->len;
	diff3 = st->precision - st->len;
	st->ret += write(1, "-", 1);
	if (st->precision > st->len)
	{
		while (i < diff3)
			i += ft_putchar_inc('0', st);
		i = 0;
		ft_putnbr_base(nb, base, blen, st);
		while (i < (diff1 - 1))
			i += ft_putchar_inc(' ', st);
	}
	else
	{
		ft_putnbr_base(nb, base, blen, st);
		while (i < (diff2 - 1))
			i += ft_putchar_inc(' ', st);
	}
}

void	ft_int_formatm113(long long nb, char *base, int blen, t_st *st)
{
	int		i;
	int		diff3;

	i = 0;
	diff3 = st->precision - st->len;
	if (st->zero == 0)
		st->ret += write(1, "-", 1);
	while (i < diff3)
		i += ft_putchar_inc('0', st);
	ft_putnbr_base(nb, base, blen, st);
}
