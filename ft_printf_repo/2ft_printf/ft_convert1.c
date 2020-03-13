/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:34:17 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/10 15:38:52 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_noominus(long long nb, t_st *st)
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
				if (st->type == 'd' || st->type == 'i')
					st->ret += write(1, "-", 1);
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
					else
					{
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
				}
			}
			else
			{
				if (st->size > st->precision)
				{
					if (st->precision > st->len)
					{
						while (i < (diff1 - 1))
						{
							st->ret += write(1, " ", 1);
							i++;
						}
						if (st->type == 'd' || st->type == 'i')
							st->ret += write (1, "-", 1);
						i = 0;
						while (i < diff3)
						{
							st->ret += write(1, "0", 1);
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
						if (st->type == 'd' || st->type == 'i')
							st->ret += write(1, "-", 1);
					}
				}
				else
				{
					if (st->type == 'd' || st->type == 'i')
						st->ret += write(1, "-", 1);
					while (i < diff3)
					{
						st->ret += write(1, "0", 1);
						i++;
					}
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
				}
			}
			else
			{
				if (st->precision > st->len)
				{
					if (st->type == 'd' || st->type == 'i')
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
		}
		else if (st->size <= st->len && st->point == 0)
		{
			if (nb < 0 && (st->type == 'd' || st->type == 'i'))
				st->ret += write(1, "-", 1);
		}
		else
		{
			if (nb < 0 && (st->type == 'd' || st->type == 'i'))
				st->ret += write(1, "-", 1);
		}
	}
	else
	{
		if (st->size > st->len && st->point == 0)
		{	
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
				if (st->type == 'd' || st->type == 'i')
					st->ret += write(1, "-", 1);
				while (i < (diff2 - 1))
				{
					st->ret += write(1, "0", 1);
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
					else
					{
						while (i < diff2)
						{
							st->ret += write(1, "0", 1);
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
				}
			}
			else
			{
				if (st->size > st->precision)
				{
					if (st->precision > st->len)
					{
						if (st->type == 'd' || st->type == 'i')
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
					else
					{
						if (st->type == 'd' || st->type == 'i')
							st->ret += write (1, "-", 1);
						while (i < (diff2 - 1))
						{
							st->ret += write(1, "0", 1);
							i++;
						}
					}
				}
				else
				{
					if (st->type == 'd' || st->type == 'i')
						st->ret += write(1, "-", 1);
					while (i < diff3)
					{
						st->ret += write(1, "0", 1);
						i++;
					}
				}
			}
		}
		else if (st->size <= st->len || st->point == 1)
		{
			if (nb >= 0)
			{
				if (st->precision > st->len)
				{
					while (i < diff3)
					{
						st->ret += write(1, "0", 1);
						i++;
					}
				}
			}
			else
			{
				if (st->precision > st->len)
				{
					if (st->type == 'd' || st->type == 'i')		
						st->ret += write(1, "-", 1);
					while (i < diff3)
					{
						st->ret += write(1, "0", 1);
						i++;
					}
				}
				else if (st->type == 'd' || st->type == 'i')
					st->ret += write(1, "-", 1);
			}
		}
		else if (st->size <= st->len && st->point == 0)
		{
			if (nb < 0 && (st->type != 'd' || st->type != 'i'))
				st->ret += write(1, "-", 1);
		}
		else
		{
			if (nb < 0 && (st->type == 'd' || st->type == 'i'))
				st->ret += write(1, "-", 1);
		}
	}
}
