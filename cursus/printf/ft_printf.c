/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberbagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:53:35 by sberbagu          #+#    #+#             */
/*   Updated: 2020/02/22 16:53:38 by sberbagu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		ft_startstr(t_varprintf *str)
{
	str->index = 0;
	str->zero = 0;
	str->min = 0;
	str->precis = 0;
	str->ispre = 0;
	str->length = 0;
	str->type = 0;
	str->end = 0;
	str->tot = 0;
}

void		ft_restart(t_varprintf *str)
{
	str->zero = 0;
	str->min = 0;
	str->precis = 0;
	str->ispre = 0;
	str->length = 0;
	str->type = 0;
	str->end = 0;
}

int			ft_countbase(long nbr, char *base)
{
	int bcount;
	int i;

	bcount = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / bcount;
		i++;
	}
	return (i);
}

void		ft_restruct(t_varprintf *str)
{
	if (str->zero == 1 && str->min == 1)
		str->zero = 0;
	if (str->precis < 0)
	{
		str->ispre = 0;
		str->precis = 0;
	}
	if (((str->zero == 1 && str->type == 'i') ||
		(str->zero == 1 && str->type == 'd') ||
		(str->zero == 1 && str->type == 'u') ||
		(str->zero == 1 && str->type == 'x') ||
		(str->zero == 1 && str->type == 'X')) && str->ispre != 0)
		str->zero = 0;
	if (str->precis > 0 && (str->type == 'c' || str->type == '%'))
		str->precis = 0;
}

int			ft_printf(const char *s, ...)
{
	t_varprintf str;

	ft_startstr(&str);
	va_start(str.lst, s);
	while (str.index < ft_strlen(s))
	{
		ft_restart(&str);
		ft_parsing(s, &str);
		ft_restruct(&str);
		ft_printing(&str);
		str.tot = str.tot + str.end;
	}
	va_end(str.lst);
	return (str.tot);
}
