/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:25:24 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/11 14:55:43 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_withminus(long long nb, char *base, t_st *st)
{
	int		i;
	int		diff1;
	int		diff2;
	int		diff3;

	i = 0;
	diff1 = st->size - st->precision;
	diff2 = st->size - st->len;
	diff3 = st->precision - st->len;
	if (st->zero == 0)
	{
		if (st->size > st->len && st->point == 0)
		{
			if (nb >= 0)
			{
				ft_putnbr_decimal(nb, base, st);
				while (i < diff2)
				{
					st->ret += write(1, " ", 1);
					i++;
				}
			}
			else
			{
				st->ret += write(1, "-", 1);
				ft_putnbr_decimal(nb, base, st);
				while (i < (diff2 - 1))
				{
					st->ret += write(1, " ", 1);
					i++;
				}
			}
		}
		else if (st->size > st->len && st->point == 1)
		{
			if (nb >= 0)
			{
				if (st->size > st->precision)
				{
					if (st->precision > st->len)
					{
						i = 0;
						while (i < diff3)
						{
							st->ret += write(1, "0", 1);
							i++;
						}
						i = 0;
						ft_putnbr_decimal(nb, base, st);
						while (i < diff1)
						{
							st->ret += write(1, " ", 1);
							i++;
						}
					}
					else
					{
						ft_putnbr_decimal(nb, base, st);
						while (i < diff2)
						{
							st->ret += write(1, " ", 1);
							i++;
						}
					}
				}
				else
				{
					while (i < diff3)
					{
						st->ret += write(1, "0", 1);
						i++;
					}
					ft_putnbr_decimal(nb, base, st);
				}
			}
			else
			{
				if (st->size > st->precision)
				{
					if (st->precision > st->len)
					{
						st->ret += write(1, "-", 1);
						while (i < diff3)
						{
							st->ret += write(1, "0", 1);
							i++;
						}
						i = 0;
						ft_putnbr_decimal(nb, base, st);
						while (i < (diff1 - 1))
						{
							st->ret += write(1, " ", 1);
							i++;
						}
					}
					else
					{
						st->ret += write(1, "-", 1);
						ft_putnbr_decimal(nb, base, st);
						while (i < (diff2 - 1))
						{
							st->ret += write(1, " ", 1);
							i++;
						}
					}
				}
				else
				{
					st->ret += write(1, "-", 1);
					while (i < diff3)
					{
						st->ret += write(1, "0", 1);
						i++;
					}
					ft_putnbr_decimal(nb, base, st);
				}
			}
		}
		else if (st->size <= st->len && st->point == 1)
		{
			if (nb >= 0)
			{
				if (st->precision > st->len)
				{
					while (i < diff3)
					{
						st->ret += write (1, "0", 1);
						i++;
					}
					ft_putnbr_decimal(nb, base, st);
				}
				else
					ft_putnbr_decimal(nb, base, st);
			}
			else
			{
				if (st->precision > st->len)
				{
					st->ret += write(1, "-", 1);
					while (i < diff3)
					{
						st->ret += write(1, "0", 1);
						i++;
					}
					ft_putnbr_decimal(nb, base, st);
				}
				else
				{
					st->ret += write(1, "-", 1);
					ft_putnbr_decimal(nb, base, st);
				}
			}
		}
		else if (st->size <= st->len && st->point == 0)
		{
			if (nb < 0)
			{
				st->ret += write(1, "-", 1);
				ft_putnbr_decimal(nb, base, st);
			}
			else
				ft_putnbr_decimal(nb, base, st);
		}
		else
		{
			if (nb < 0)
				st->ret += write(1, "-", 1);
			ft_putnbr_decimal(nb, base, st);
		}
	}
}
