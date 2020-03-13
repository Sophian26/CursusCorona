/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberbagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:49:59 by sberbagu          #+#    #+#             */
/*   Updated: 2020/02/22 17:50:00 by sberbagu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		ft_printflags(t_varprintf *str, int cbase)
{
	if (cbase > str->precis)
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
	else
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
}

void		ft_printflagsmin(t_varprintf *str)
{
	while (str->end < str->length)
	{
		if (str->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		str->end += 1;
	}
}

void		ft_printprec(t_varprintf *str, int cbase)
{
	while (cbase < str->precis)
	{
		write(1, "0", 1);
		str->end += 1;
		cbase++;
	}
}

int			ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int			ft_atoi(const char *nptr, t_varprintf *str)
{
	long	i;
	int		n;
	long	f;

	i = str->index;
	n = 1;
	f = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n = -n;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		f = (f * 10) + nptr[i] - '0';
		i++;
	}
	str->index = i;
	return (f * n);
}
