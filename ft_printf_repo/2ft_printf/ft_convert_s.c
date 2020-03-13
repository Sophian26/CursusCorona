/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:27:39 by dpuccion          #+#    #+#             */
/*   Updated: 2020/02/29 14:36:45 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convert_s(char *s, t_st *st)
{
	int		i;

	i = 0;
	st->len = ft_strlen(s);
//	dprintf(1, "|%d|%d|%d|%d|%d|'%s'", st->minus, st->size, st->point, st->precision, st->len, s);
	if (st->minus == 0)
	{
/*		if (st->point == 1 && st->precision == 0)
		{
			while (i < st->size)
			{
				st->ret += write(1, " ", 1);
				i++;
			}
		}*/
		if (st->size > st->len)
		{
			if (st->point == 0)
			{
				while (i < (st->size - st->len))
				{
					st->ret += write(1, " ", 1);
					i++;
				}
				i = 0;
				while (i < st->len)
				{
					st->ret += write(1, &s[i], 1);
					i++;
				}
			}
			else
			{
				if (st->precision == 0)
				{
					while (i < st->size)
					{
						st->ret += write(1, " ", 1);
						i++;
					}
				}
				else if (st->len > st->precision)
				{
					while (i < (st->size - st->precision))
					{
						st->ret += write(1, " ", 1);
						i++;
					}
					i = 0;
					while (i < st->precision)
					{
						st->ret += write(1, &s[i], 1);
						i++;
					}
				}
				else
				{
					while (i < (st->size - st->len))
					{
						st->ret += write(1, " ", 1);
						i++;
					}
					i = 0;
					while (i < st->len)
					{
						st->ret += write(1, &s[i], 1);
						i++;
					}
				}
			}
		}
		else
		{
			if (st->point == 0)
			{
				while (i < st->len)
				{
					st->ret += write(1, &s[i], 1);
					i++;
				}
			}
			else
			{
				if (st->precision == 0)
				{
					while (i < st->size)
					{
						st->ret += write(1, " ", 1);
						i++;
					}
				}
				else if (st->precision >= st->len)
				{
					while (i < st->len || (s[i] != '\0'))
					{
						st->ret += write(1, &s[i], 1);
						i++;
					}
				}
				else
				{
					while (i < (st->size - st->precision))
					{
						st->ret += write(1, " ", 1);
						i++;
					}
					i = 0;
					while (i < st->precision)
					{
						st->ret += write (1, &s[i], 1);
						i++;
					}
				}
			}
		}
	}
	else
	{
		if (st->size > st->len)
		{
			if (st->point == 0)
			{
				while (i < st->len)
				{
					st->ret += write(1, &s[i], 1);
					i++;
				}
				i = 0;
				while (i < (st->size - st->len))
				{
					st->ret += write(1, " ", 1);
					i++;
				}
			}
			else
			{
				if (st->precision == 0)
				{
					while (i < st->size)
					{
						st->ret += write(1, " ", 1);
						i++;
					}
				}
				else if (st->len > st->precision)
				{
					while (i < st->precision)
					{
						st->ret += write(1, &s[i], 1);
						i++;
					}
					i = 0;
					while (i < (st->size - st->precision))
					{
						st->ret += write(1, " ", 1);
						i++;
					}
				}
				else
				{
					while (i < st->len)
					{
						st->ret += write(1, &s[i], 1);
						i++;
					}
					i = 0;
					while (i < (st->size - st->len))
					{
						st->ret += write(1, " ", 1);
						i++;
					}
				}
			}
		}
		else
		{
			if (st->point == 0)
			{
				while (i < st->len)
				{
					st->ret += write(1, &s[i], 1);
					i++;
				}
			}
			else
			{
				if (st->precision == 0)
				{
					while (i < st->size)
					{
						st->ret += write(1, " ", 1);
						i++;
					}
				}
				else if (st->precision >= st->len)
				{
					while (i < st->len || (s[i] != '\0'))
					{
						st->ret += write(1, &s[i], 1);
						i++;
					}
				}
				else
				{
					while (i < st->precision)
					{
						st->ret += write (1, &s[i], 1);
						i++;
					}
					i = 0;
					while (i < (st->size - st->precision))
					{
						st->ret += write(1, " ", 1);
						i++;
					}
				}
			}
		}
	}
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
