/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_no_minus_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 05:44:24 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/04 05:50:27 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_no_minus_10(int diff1, int diff2, int diff3, t_st *st)
{
	if (st->size > st->precision)
	{
		if (st->precision > st->len)
			ft_flags_11(diff1, diff3, st);
		else
			ft_flags_12(diff2, st);
	}
	else
		ft_flags_13(diff3, st);
}
