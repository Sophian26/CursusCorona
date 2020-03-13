/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 04:19:38 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/04 04:34:48 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aff_char(char c, t_st *st)
{
	int		i;

	i = 0;
	if (st->minus == 1)
		st->ret += write(1, &c, 1);
	if (st->size > 1)
	{
		while (i < (st->size - 1))
		{
			st->ret += write (1, " ", 1);
			i++;
		}
	}
	if (st->minus == 0)
		st->ret += write(1, &c, 1);
}
