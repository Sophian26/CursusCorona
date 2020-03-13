/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_format11x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:37:17 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/11 16:27:41 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_format110(long long nb, t_st *st)
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
		while (i < diff1)
			i += ft_putchar_inc(' ', st);
		i = 0;
		while (i < diff3)
			i += ft_putchar_inc('0', st);
	}
	else
	{
		while (i < diff2)
			i += ft_putchar_inc(' ', st);
	}
}

void	ft_int_format111(long long nb, t_st *st)
{
	int	i;
	int	diff3;

	i = 0;
	diff3 = st->precision - st->len;
	while (i < diff3)
		i += ft_putchar_inc('0', st);
}

void	ft_int_format112(long long nb, t_st *st)
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
		while (i < (diff1 - 1))
			i += ft_putchar_inc(' ', st);
		st->ret += write (1, "-", 1);
		i = 0;
		while (i < diff3)
			i += ft_putchar_inc('0', st);
	}
	else
	{
		while (i < (diff2 - 1))
			i += ft_putchar_inc(' ', st);
		st->ret += write(1, "-", 1);
	}
}

void	ft_int_format113(long long nb, t_st *st)
{
	int	i;
	int	diff3;

	i = 0;
	diff3 = st->precision - st->len;
	st->ret += write(1, "-", 1);
	while (i < diff3)
		i += ft_putchar_inc('0', st);
}
