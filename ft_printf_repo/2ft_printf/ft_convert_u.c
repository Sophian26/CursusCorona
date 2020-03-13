/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:39:04 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/10 15:56:17 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convert_u(unsigned int nb, char *base, unsigned int blen, t_st *st)
{
	int		i;

	i = 0;
	if (nb < 0)
		nb += 4294967295;
	ft_get_nblen(nb, st);
	if(!(nb == 0 && st->point == 1 && st->precision == 0))
	{
		if (st->minus == 0)
		{
			ft_noominus(nb, st);
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

void	ft_putunbr_base(unsigned long nb, char *base, unsigned int blen, t_st *st)
{
//	if (nb < 0)
//		nb += 4294967295;
	if (nb < blen)
		st->ret += write(1, &base[nb], 1);
	else
	{
		ft_putunbr_base((nb / blen), base, blen, st);
		ft_putunbr_base((nb % blen), base, blen, st);
	}
}
