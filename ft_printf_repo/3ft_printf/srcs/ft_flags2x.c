/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 05:06:56 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/04 05:18:57 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_20(int diff2, t_st *st)
{
	int	i;

	i = 0;
	while (i < (diff2 - 1))
	{
		st->ret += write(1, " ", 1);
		i++;
	}
	st->ret += write(1, "-", 1);
}

void	ft_flags_21(int diff3, t_st *st)
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

void	ft_flags_22(int diff3, t_st *st)
{
	int	i;

	i = 0;
	if (st->precision > st->len)
	{
		while (i < diff3)
		{
			st->ret += write (1, "0", 1);
			i++;
		}
	}
}

void	ft_flags_23(int diff3, t_st *st)
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

void	ft_flags_24(int nb, t_st *st)
{
	int	i;

	i = 0;
	if (nb < 0)
		st->ret += write(1, "-", 1);
}
