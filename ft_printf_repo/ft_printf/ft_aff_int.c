/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:08:25 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/11 17:50:50 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aff_int(long long nb, char *base, int blen, t_st *st)
{
	int i;

	i = 0;
	ft_get_nblen(nb, st);
	if (!(nb == 0 && st->point == 1 && st->precision == 0))
	{
		ft_format(nb, base, blen, st);
		if (st->minus == 0)
			ft_putnbr_base(nb, base, blen, st);
	}
	else
	{
		while (i < st->size)
			i += ft_putchar_inc(' ', st);
	}
}

void	ft_get_nblen(long long nb, t_st *st)
{
	st->len = 0;
	if (nb < 0)
		nb = nb * (-1);
	while (nb >= 10)
	{
		st->len++;
		nb = nb / 10;
	}
	st->len++;
}

void	ft_format(long long nb, char *base, int blen, t_st *st)
{
	if (st->minus == 0)
	{
		if (st->zero == 0)
			ft_int_format1(nb, st);
		else
			ft_int_format01(nb ,st);
	}
	else
		ft_int_formatm1(nb, base, blen, st);
}

void	ft_putnbr_base(long long nb, char *base, int blen, t_st *st)
{
	if (st->type == 'd' || st->type == 'i')
	{
		if (nb < 0)
			nb = nb * (-1);
	}
	if (nb < blen)
		st->ret += write(1, &base[nb], 1);
	else
	{
		ft_putnbr_base((nb / blen), base, blen, st);
		ft_putnbr_base((nb % blen), base, blen, st);
	}
}

int		ft_putchar_inc(char c, t_st *st)
{
	st->ret += write(1, &c, 1);
	return (1);
}
