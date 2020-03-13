/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 03:13:53 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/10 15:56:20 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convert_p(char *base, unsigned int blen, t_st *st)
{
	int				i;
	unsigned long	nb;

	nb = (unsigned long)va_arg(st->ap, void *);
	i = 0;
//	if (nb < 0)
//		nb += 18446744073709551616; 
	ft_get_xX_len(nb, blen, st);
	st->len += 2;
	if(!(nb == 0 && st->point == 1 && st->precision == 0))
	{
		if (st->minus == 0)
		{
//			dprintf(1, "%ld", nb);
			ft_noominus(nb, st);
//			dprintf(1, "|%ld|%d|", nb, blen);
			st->ret += write(1, "0x", 2);
			ft_putunbr_base(nb, base, blen, st);
		}
		else
		{
//			dprintf(1, "%ld", nb);
			st->ret += write(1, "0x", 2);
			ft_withminusu(nb, base, blen, st);
		}
	}
}
