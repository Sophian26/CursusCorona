/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 04:35:16 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/04 05:45:25 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aff_int(long long nb, char *base, t_st *st)
{
	int i;

	i = 0;
	ft_get_int_len(nb, st);
	if (!(nb == 0 && st->point == 1 && st->precision == 0))
	{
		if (st->minus == 0)
		{
			ft_if_no_minus(nb, st);
			ft_putnbr_decimal(nb, base, st);
		}
		else
			ft_withminus(nb, base, st);
	}
	else
	{
		while (i < st->size)
		{
			st->ret += write(1, " ", 1);
			i++;
		}
	}
}

void	ft_get_int_len(long long nb, t_st *st)
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

void	ft_putnbr_decimal(long long nb, char *base, t_st *st)
{
	if (nb < 0)
		nb = nb * (-1);
	if (nb < 10)
		st->ret += write(1, &base[nb], 1);
	else
	{
		ft_putnbr_decimal((nb / 10), base, st);
		ft_putnbr_decimal((nb % 10), base, st);
	}
}
