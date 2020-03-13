/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_xX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:46:54 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/10 15:56:22 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convert_xX(long long nb, char *base, int blen, t_st *st)
{
	int		i;

	i = 0;
	if (nb < 0)
		nb += 4294967296;
	ft_get_xX_len(nb, blen, st);
	if(!(nb == 0 && st->point == 1 && st->precision == 0))
	{
		if (st->minus == 0)
		{
			ft_noominus(nb, st);
//			dprintf(1, "|%lld|%d|%d|", nb, st->len, blen);
			ft_putunbr_base(nb, base, blen, st);
		}
		else
			ft_withminusu(nb, base, blen, st);
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

void	ft_get_xX_len(long long nb, int blen, t_st *st)
{
	if (nb < blen)
		st->len++;
	else
	{
		ft_get_xX_len((nb / blen), blen, st);
		ft_get_xX_len((nb % blen), blen, st);
	}
}
