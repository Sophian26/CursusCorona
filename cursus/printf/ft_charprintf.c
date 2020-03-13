/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberbagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:05:27 by sberbagu          #+#    #+#             */
/*   Updated: 2020/02/22 18:05:30 by sberbagu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_prints(t_varprintf *str)
{
	char *s;

	s = va_arg(str->lst, char *);
	if (!s)
		s = "(null)";
	if (s != NULL && str->min == 0 && (str->precis != 0 || str->ispre == 0))
		ft_printflagstring(str, ft_strlen(s));
	if ((str->precis == 0 && str->ispre == 1) || s == NULL)
		ft_printflagstring(str, 0);
	else
	{
		if (s != NULL)
			str->end = str->end + ft_putstr_pf(s, str);
		if (str->min == 1)
			ft_printflagstring(str, 0);
	}
}

void		ft_printing(t_varprintf *str)
{
	int		i;

	i = 0;
	if (str->type == 'u' || str->type == 'x' ||
		str->type == 'X' || str->type == 'p')
	{
		if (str->type == 'p')
			str->end += 2;
		ft_printuxx(str);
	}
	if (str->type == 'i' || str->type == 'd')
		ft_printid(str);
	if (str->type == 'c' || str->type == '%')
		ft_printcper(str);
	if (str->type == 's')
		ft_prints(str);
}

void		ft_printflagstring(t_varprintf *str, int cbase)
{
	if (cbase > str->precis && str->ispre != 0)
	{
		while (str->precis + str->end < str->length)
		{
			if (str->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			str->end += 1;
		}
	}
	else
	{
		while (cbase + str->end < str->length)
		{
			if (str->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			str->end += 1;
		}
	}
}

void		ft_printcper(t_varprintf *str)
{
	if (str->type == 'c')
	{
		if (str->min == 0)
			ft_printflags(str, 1);
		str->end = str->end + 1;
		ft_putchar_fd(va_arg(str->lst, int), 1);
		if (str->min == 1)
			ft_printflags(str, 0);
	}
	if (str->type == '%')
	{
		if (str->min == 0)
			ft_printflags(str, 1);
		str->end = str->end + 1;
		ft_putchar_fd('%', 1);
		if (str->min == 1)
			ft_printflags(str, 0);
	}
}
