/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:24:23 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/11 16:38:21 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_format1(long long nb, t_st *st)
{
	if (st->size > st->len && st->point == 0)
		ft_int_format10(nb, st);
	else if (st->size > st->len && st->point == 1)
		ft_int_format11(nb, st);
	else if (st->size <= st->len && st->point == 1)
		ft_int_format12(nb, st);
	else if (nb < 0)
		st->ret += write(1, "-", 1);
}

void	ft_int_format01(long long nb, t_st *st)
{
	if (st->size > st->len && st->point == 0)
		ft_int_format010(nb, st);
	else if (st->size > st->len && st->point == 1)
		ft_int_format011(nb, st);
	else if (st->size <= st->len && st->point == 1)
		ft_int_format012(nb, st);
	else if (nb < 0)
		st->ret += write(1, "-", 1);
}

void	ft_int_formatm1(long long nb, char *base, int blen, t_st *st)
{
	if (st->size > st->len && st->point == 0)
		ft_int_formatm10(nb, base, blen, st);
	else if (st->size > st->len && st->point == 1)
		ft_int_formatm11(nb, base, blen, st);
	else if (st->size <= st->len && st->point == 1)
		ft_int_formatm12(nb, base, blen, st);
	else
	{
		if (nb < 0)
			st->ret += write(1, "-", 1);
		ft_putnbr_base(nb, base, blen, st);
	}
}
