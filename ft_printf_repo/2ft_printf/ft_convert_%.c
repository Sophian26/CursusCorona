/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_%.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:37 by dpuccion          #+#    #+#             */
/*   Updated: 2020/02/29 16:48:29 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convert_pc(t_st *st)
{
	if (st->minus == 0)
	{
		ft_nominuspc(st);
		st->ret += write(1, "%", 1);
	}
	if (st->minus == 1)
	{
		st->ret += write(1, "%", 1);
		ft_nominuspc(st);
	}
}

void	ft_nominuspc(t_st *st)
{
	int		i;

	i = 0;
	while (i < (st->size - 1))
	{
		if (st->zero  == 0)
			st->ret += write(1, " ", 1);
		else
			st->ret += write(1, "0", 1);
		i++;
	}
}
