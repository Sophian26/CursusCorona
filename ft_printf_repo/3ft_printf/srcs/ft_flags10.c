/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 04:44:20 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/04 05:06:41 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_10(int nb, int diff2, t_st *st)
{
	int	i;

	i = 0;
	if (nb >= 0)
	{
		while (i < diff2)
		{
			st->ret += write(1, " ", 1);
			i++;
		}
	}
	else
	{
		while (i < (diff2 - 1))
		{
			st->ret += write(1, " ", 1);
			i++;
		}
		st->ret += write(1, "-", 1);
	}
}

void	ft_flags_11(int diff1, int diff3, t_st *st)
{
	int	i;

	i = 0;
	while (i < diff1)
	{
		st->ret += write(1, " ", 1);
		i++;
	}
	i = 0;
	while (i < diff3)
	{
		st->ret += write(1, "0", 1);
		i++;
	}
}

void	ft_flags_12(int diff2, t_st *st)
{
	int	i;

	i = 0;
	while (i < diff2)
	{
		st->ret += write(1, " ", 1);
		i++;
	}
}

void	ft_flags_13(int diff3, t_st *st)
{
	int	i;

	i = 0;
	while (i < diff3)
	{
		st->ret += write(1, "0", 1);
		i++;
	}
}

void	ft_flags_14(int diff1, int diff3, t_st *st)
{
	int	i;

	i = 0;
	while (i < (diff1 - 1))
	{
		st->ret += write(1, " ", 1);
		i++;
	}
	st->ret += write (1, "-", 1);
	i = 0;
	while (i < diff3)
	{
		st->ret += write(1, "0", 1);
		i++;
	}
}
