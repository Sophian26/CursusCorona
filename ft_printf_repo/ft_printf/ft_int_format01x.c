/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_format01x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:24:23 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/11 16:26:42 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_format010(long long nb, t_st *st)
{
	int	i;
	int	diff2;

	i = 0;
	diff2 = st->size - st->len;
	if (nb >= 0)
	{
		while (i < diff2)
			i += ft_putchar_inc('0', st);
	}
	else
	{
		st->ret += write(1, "-", 1);
		while (i < (diff2 - 1))
			i += ft_putchar_inc('0', st);
	}
}

void	ft_int_format011(long long nb, t_st *st)
{
	if (nb >= 0)
	{
		if (st->size > st->precision)
			ft_int_format0110(nb, st);
		else
			ft_int_format0111(nb, st);
	}
	else
	{
		if (st->size > st->precision)
			ft_int_format0112(nb, st);
		else
			ft_int_format0113(nb, st);
	}
}

void	ft_int_format012(long long nb, t_st *st)
{
	int	i;
	int	diff3;

	i = 0;
	diff3 = st->precision - st->len;
	if (nb >= 0)
	{
		if (st->precision > st->len)
		{
			while (i < diff3)
				i += ft_putchar_inc('0', st);
		}
	}
	else
	{
		if (st->precision > st->len)
		{
			st->ret += write(1, "-", 1);
			while (i < diff3)
				i += ft_putchar_inc('0', st);
		}
		else
			st->ret += write(1, "-", 1);
	}
}
