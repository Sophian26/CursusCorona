/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_formatm1x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:54:14 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/11 16:28:49 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_formatm10(long long nb, char *base, int blen, t_st *st)
{
	int		i;
	int		diff2;

	i = 0;
	diff2 = st->size - st->len;
	if (nb >= 0)
	{
		ft_putnbr_base(nb, base, blen, st);
		while (i < diff2)
			i += ft_putchar_inc(' ', st);
	}
	else
	{
		st->ret += write(1, "-", 1);
		ft_putnbr_base(nb, base, blen, st);
		while (i < (diff2 - 1))
			i += ft_putchar_inc(' ', st);
	}
}

void	ft_int_formatm11(long long nb, char *base, int blen, t_st *st)
{
	if (nb >= 0)
	{
		if (st->size > st->precision)
			ft_int_formatm110(nb, base, blen, st);
		else
			ft_int_formatm111(nb, base, blen, st);
	}
	else
	{
		if (st->size > st->precision)
			ft_int_formatm112(nb, base, blen, st);
		else
			ft_int_formatm113(nb, base, blen, st);
	}
}

void	ft_int_formatm12(long long nb, char *base, int blen ,t_st *st)
{
	int		i;
	int		diff3;

	i = 0;
	diff3 = st->precision - st->len;
	if (nb >= 0)
	{
		if (st->precision > st->len)
		{
			while (i < diff3)
				i += ft_putchar_inc('0', st);
		}
		ft_putnbr_base(nb, base, blen, st);
	}
	else
	{
		st->ret += write(1, "-", 1);
		if (st->precision > st->len)
		{
			while (i < diff3)
				i += ft_putchar_inc('0', st);
		}
		ft_putnbr_base(nb, base, blen, st);
	}
}
