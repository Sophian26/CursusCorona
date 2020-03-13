/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:28:15 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/11 17:50:46 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aff_string(char *s, t_st *st)
{
	int	i;

	i = 0;
	st->len = ft_strlen(char *s);
	ft_string_format(s, st);
}

void	ft_string_format(char *s, t_st *st)
{
	if (st->minus == 0)
		ft_string_format1(s, st);
	else
		ft_string_formatm1(s, st);
}

void	ft_string_format1(char *s, t_st *st)
{
	if (st->size > st->len)
		ft_string_format10(s, st);
	else
		ft_string_format11(s, st);
}

void	ft_string_format10(char *s, t_st *st)
{
	if (st->point == 0)
		ft_string_format10(s, st);
	else
	{
		if (st->precision == 0)
			ft_string_format100(s, st);
		else if (st->len > st->precision)
			ft_string_format101(s, st);
		else
			ft_string-format102(s, st);
	}
}

void	ft_string_format11(char *s, t_st *st)
{
	if (st->point == 0)
		ft_string_format110(s, st);
	else
	{
		if (st->precision == 0)
			ft_string_format111(s, st);
		else if (st->precision = st->len)
			ft_string_format112(s, st);
		else
			ft_string_format113(s, st);
	}
}
