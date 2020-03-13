/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 04:17:16 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/04 04:22:53 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_st	st;

	ft_init_struct(&st);
	va_start (st.ap, format);
	st.i = 0;
	st.ret = 0;
	while (format[st.i] != '\0')
	{
		if (format[st.i] == '%')
		{
			ft_init_struct(&st);
			ft_parsing(format, &st);
			ft_reinit_struct(&st);
			ft_what_to_do(&st);
			st.i++;
		}
		if (format[st.i] != '\0' && format[st.i] != '%')
		{
			write(1, &format[st.i], 1);
			st.ret++;
		}
		if (format[st.i] != '\0' && format[st.i] != '%')
			st.i++;
	}
	return (st.ret);
}

void	ft_init_struct(t_st *st)
{
	st->zero = 0;
	st->minus = 0;
	st->size = 0;
	st->point = 0;
	st->precision = 0;
	st->type = '\0';
	st->len = 0;
}

void	ft_reinit_struct(t_st *st)
{
	if (st->zero == 1 && st->minus == 1)
		st->zero = 0;
	if (st->type == 'd' || st->type == 'i' || st->type == 'u' || st->type == 'x' || st->type == 'X')
	{
		if (st->zero == 1 && st->point == 1)
			st->zero = 0;
	}
	if ((st->type == 's' || st->type == 'd') && st->size < 0)
	{
		st->size = st->size * -1;
		st->minus = 1;
	}
	if (st->type == 's' && st->precision < 0)
		st->point = 0;
}
void	ft_what_to_do(t_st *st)
{
	if (st->type == 'c')
		ft_aff_char(va_arg(st->ap, int), st);
	else if (st->type == 's')
		ft_aff_string(va_arg(st->ap, char *), st);
	else if (st->type == 'p')
		ft_aff_pointer("0123456789abcdef", 16, st);
	else if (st->type == 'd' || st->type == 'i')
		ft_aff_int(va_arg(st->ap, int), "0123456789", st);
	else if (st->type == 'u')
		ft_aff_unsinged_int(va_arg(st->ap, unsigned int), "0123456789", 10, st);
	else if (st->type == 'x')
		ft_aff_hexa(va_arg(st->ap, int), "0123456789abcdef", 16, st);
	else if (st->type == 'X')
		ft_aff_hexa(va_arg(st->ap, int), "0123456789ABCDEF", 16, st);
	else if (st->type == '%')
		ft_aff_percent(st);
}
