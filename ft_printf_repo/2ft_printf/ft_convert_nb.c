/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 05:34:09 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/10 11:07:19 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convert_di(long long nb, char *base, t_st *st)
{
	int i;

	i = 0;
	ft_get_nblen(nb, st);
//	if (!(nb == 0 && st->point == 1 && st->precision == 0 && st->size == 0))
//	{
//		dprintf(1, "aaa");
//		dprintf(1, "|%d", st->point);
//		dprintf(1, "|%d", st->precision);
//		dprintf(1, "|%lld.", nb);
		if (st->minus == 0)
		{
//			if (nb < 0)
//			{
//				st->len++;
//				if (st->point == 1)
//					st->precision++;
//				ft_write_neg0(st);
//			}
//			if (nb < 0 && st->point == 0 && st->size == 0)
//				st->ret += write(1, "-", 1);
			if (!(nb == 0 && st->point == 1 && st->precision == 0))
			{
				ft_noominus(nb, st);
				ft_putnbr_decimal(nb, base, st);
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
		else
		{
			if(!(nb == 0 && st->point == 1 && st->precision == 0))
				ft_withminus(nb, base, st);
			else
			{
				while (i < st->size)
				{
					st->ret += write(1, " ", 1);
					i++;
				}
			}
		}
	}
//}

void	ft_write_neg0(t_st *st)
{
	if (st->zero == 1)
	{
//		dprintf(1, "uho");
		st->ret += write (1, "-", 1);
	}
	else if ((st->precision + 1) >= st->size)
	{
//		dprintf(1, "ohu");
		st->ret += write(1, "-", 1);
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

void	ft_putnbr_decimal(long long nb, char *base, t_st *st)
{
	if (st->type == 'd' || st->type == 'i')
	{
		if (nb < 0)
			nb = nb * (-1);
	}
	if (nb < 10)
		st->ret += write(1, &base[nb], 1);
	else
	{
		ft_putnbr_decimal((nb / 10), base, st);
		ft_putnbr_decimal((nb % 10), base, st);
	}
}
