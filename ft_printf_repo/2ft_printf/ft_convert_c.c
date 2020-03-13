/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:36:42 by dpuccion          #+#    #+#             */
/*   Updated: 2020/02/28 18:28:42 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convert_c(char c, t_st *st)
{
	int		i;

	i = 0;
	if (st->minus == 0)
	{
		if (st->size > 1)
		{
			while (i < (st->size - 1))
			{
				st->ret += write(1, " ", 1);
				i++;
			}
		}
		st->ret += write(1, &c, 1);
	}
	else
	{
		st->ret = write(1, &c, 1);
		if (st->size > 1)
		{
			while (i < (st->size - 1))
			{
				st->ret += write(1, " ", 1);
				i++;
			}
		}
	}
}
