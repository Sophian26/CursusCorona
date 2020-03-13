/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_4x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 05:29:31 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/04 05:39:48 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_40(int diff2, t_st *st)
{
	int	i;

	i = 0;
	st->ret += write (1, "-", 1);
	while (i < (diff2 - 1))
	{
		st->ret += write(1, "0", 1);
		i++;
	}
}

void	ft_flags_41(int diff3, t_st *st)
{
	int	i;

	i = 0;
	st->ret += write(1, "-", 1);
	while (i < diff3)
	{
		st->ret += write(1, "0", 1);
		i++;
	}
}

void	ft_flags_42(int diff3, t_st *st)
{
	int	i;

	i = 0;
	if (st->precision > st->len)
	{
		while (i < diff3)
		{
			st->ret += write(1, "0", 1);
			i++;
		}
	}
}

void	ft_flags_43(int diff3, t_st *st)
{
	int	i;

	i = 0;
	if (st->precision > st->len)
	{
		st->ret += write(1, "-", 1);
		while (i < diff3)
		{
			st->ret += write(1, "0", 1);
			i++;
		}
	}
	else
		st->ret += write(1, "-", 1);
}
