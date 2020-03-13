/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_3x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 05:19:16 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/04 05:29:21 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_30(int nb, int diff2, t_st *st)
{
	int	i;

	i = 0;
	if (nb >= 0)
	{
		while (i < diff2)
		{
			st->ret += write(1, "0", 1);
			i++;
		}
	}
	else
	{
		st->ret += write(1, "-", 1);
		while (i < (diff2 - 1))
		{
			st->ret += write(1, "0", 1);
			i++;
		}
	}
}

void	ft_flags_31(int diff1, int diff2, t_st *st)
{
	int	i;

	i = 0;
	while (i < diff1)
	{
		st->ret += write(1, "0", 1);
		i++;
	}
	while (i < diff2)
	{
		st->ret += write(1, "0", 1);
		i++;
	}
}

void	ft_flags_32(int diff2, t_st *st)
{
	int	i;

	i = 0;
	while (i < diff2)
	{
		st->ret += write(1, "0", 1);
		i++;
	}
}

void	ft_flags_33(int diff3, t_st *st)
{
	int	i;

	i = 0;
	while (i < diff3)
	{
		st->ret += write(1, "0", 1);
		i++;
	}
}

void	ft_flags_34(int diff1, int diff3, t_st *st)
{
	int	i;

	i = 0;
	st->ret += write(1, "-", 1);
	while (i < (diff1 - 1))
	{
		st->ret += write(1, "0", 1);
		i++;
	}
	i = 0;
	while (i < diff3)
	{
		st->ret += write(1, "0", 1);
		i++;
	}
}
