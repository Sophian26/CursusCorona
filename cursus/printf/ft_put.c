/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberbagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:41:32 by sberbagu          #+#    #+#             */
/*   Updated: 2020/02/22 17:41:34 by sberbagu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr_pf(char *s, t_varprintf *str)
{
	int i;

	i = 0;
	if (str->ispre == 0)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	else
	{
		while (s[i] && i < str->precis)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_int_to_char(int i, int fd)
{
	char c;

	c = '0' + i;
	write(fd, &c, 1);
}

int			ft_putnbr_rec(long nb, int fd, int count)
{
	long i;

	i = nb;
	if (i < 0)
	{
		write(fd, "-", 1);
		i = -i;
	}
	if (i != 0)
	{
		ft_putnbr_rec(i / 10, fd, count + 1);
		ft_int_to_char(i % 10, fd);
	}
	return (count);
}

int			ft_putnbr_fd(long n, int fd)
{
	int i;

	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		i = 1;
	}
	else
		i = ft_putnbr_rec(n, fd, i);
	return (i);
}
