/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberbagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:52:48 by sberbagu          #+#    #+#             */
/*   Updated: 2020/02/22 16:52:54 by sberbagu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_putnbr_base(unsigned long long nbr, char *base)
{
	int					count;
	unsigned long long	len;

	count = 0;
	len = ft_strlen(base);
	if (nbr < len)
		count += write(1, &base[nbr], 1);
	else
	{
		count += ft_putnbr_base(nbr / len, base);
		count += ft_putnbr_base(nbr % len, base);
	}
	return (count);
}

void		ft_printidend(t_varprintf *str, int cbase, long i)
{
	if (str->min == 0)
	{
		if (i == 0 && str->ispre == 1 && str->precis == 0)
			ft_printflags(str, 0);
		else
			ft_printflags(str, cbase);
	}
	ft_printprec(str, cbase);
	if (!(i == 0 && str->ispre == 1 && str->precis == 0))
	{
		str->end = str->end + cbase;
		ft_putnbr_fd(i, 1);
	}
	if (str->min == 1)
		ft_printflagsmin(str);
}

void		ft_printid(t_varprintf *str)
{
	long	i;
	int		cbase;

	i = 0;
	i = va_arg(str->lst, int);
	cbase = ft_countbase(i, DEC_BASE);
	if (i < 0 && str->precis > 1)
	{
		cbase -= 1;
		str->end += 1;
	}
	if (str->length > ft_countbase(i, DEC_BASE) && str->zero == 0
		&& str->min == 0)
		ft_printflags(str, cbase);
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
		if (str->precis <= 1)
		{
			cbase -= 1;
			str->end += 1;
		}
	}
	ft_printidend(str, cbase, i);
}

void		ft_printuxx(t_varprintf *str)
{
	long long	i;
	char		*base;

	if (str->type == 'u')
		base = DEC_BASE;
	if (str->type == 'x' || str->type == 'p')
		base = HEXA_LOW;
	if (str->type == 'X')
		base = HEXA_UP;
	i = str->type == 'p' ? (intptr_t)va_arg(str->lst, void*)
	: va_arg(str->lst, unsigned int);
	if (str->min == 0)
	{
		if (i == 0 && str->ispre == 1 && str->precis == 0)
			ft_printflags(str, 0);
		else
			ft_printflags(str, ft_countbase(i, base));
	}
	ft_printprec(str, ft_countbase(i, base));
	if (str->type == 'p')
		write(1, "0x", 2);
	if (!(i == 0 && str->ispre == 1 && str->precis == 0))
		str->end = str->end + ft_putnbr_base(i, base);
	if (str->min == 1)
		ft_printflagsmin(str);
}
