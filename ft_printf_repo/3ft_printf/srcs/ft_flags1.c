/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 04:43:20 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/04 05:50:31 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_no_minus(long long nb, t_st *st)
{
	int		i;
	int		diff1;
	int		diff2;
	int		diff3;

	i = 0;
	diff1 = st->size - st->precision;
	diff2 = st->size - st->len;
	diff3 = st->precision - st->len;
	if (st->zero == 0)
	{
		if (st->size > st->len && st->point == 0)
			ft_flags_10(nb, diff2, st);
		else if (st->size > st->len && st->point == 1)
		{
			if (nb >= 0)
				ft_if_no_minus_10(diff1, diff2, diff3, st);
			else
			{
				if (st->size > st->precision)
				{
					if (st->precision > st->len)
						ft_flags_13(diff1, diff3, st);
					else
						ft_flags_20(diff2, st);	
				}
				else
					ft_flags_21(diff3, st);			
			}
		}
		else if (st->size <= st->len && st->point == 1)
		{
			if (nb >= 0)
				ft_flags_22(diff3, st);
			else
				ft_flags_23(diff3, st);
		}
		else
			ft_flags_24(nb ,st);
	}
	else
	{
		if (st->size > st->len && st->point == 0)
			ft_flags_30(nb, diff2, st);
		else if (st->size > st->len && st->point == 1)
		{
			if (nb >= 0)
			{
				if (st->size > st->precision)
				{
					if (st->precision > st->len)
						ft_flags_31(diff1, diff2, st);
					else
						ft_flags_32(diff2, st);
				}
				else
					ft_flags_33(diff3, st);
			}
			else
			{
				if (st->size > st->precision)
				{
					if (st->precision > st->len)
						ft_flags_34(diff1, diff3, st);
					else
						ft_flags_40(diff2, st);			
				}
				else
					ft_flags_41(diff3, st);
			}
		}
		else if (st->size <= st->len && st->point == 1)
		{
			if (nb >= 0)
				ft_flags_42(diff3, st);
			else
				ft_flags_43(diff3, st);			
		}
		else if (nb < 0)
			st->ret += write(1, "-", 1);
	}
}
