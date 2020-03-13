/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dpuccion <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 12:21:07 by dpuccion     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/29 15:48:33 by dpuccion         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_parsing(const char *s, t_st *st)
{
	st->i++;
	ft_check_flags(s, st);
	ft_what_size(s, st);
	ft_what_precision(s, st);
	st->type = s[st->i];
}

void	ft_check_flags(const char *s, t_st *st)
{
	while (s[st->i] == '-' || s[st->i] == '0')
	{
		if (s[st->i] == '-')
			st->minus = 1;
		else if (s[st->i] == '0')
			st->zero = 1;
		st->i++;
	}
}

void	ft_what_size(const char *s, t_st *st)
{
	if (s[st->i] == '*')
	{
		st->size = va_arg(st->ap, int);
//		dprintf(1, "| %d |\n", st->size);
		if (st->size < 0)
		{
			st->size = st->size * (-1);
//			dprintf(1, "| %d |\n", st->size);
			st->minus = 1;
		}
		st->i++;
	}
	else if (s[st->i] >= '0' && s[st->i] <= '9')
	{

		st->size = ft_atoi(s + st->i);
		//dprintf(1, "| %d |\n", st->size);
		while (s[st->i] >= '0' && s[st->i] <= '9')
			st->i++;
	}
}

void	ft_what_precision(const char *s, t_st *st)
{
	if (s[st->i] == '.')
	{
		st->point = 1;
		st->i++;
		if (s[st->i] == '*')
		{
			st->precision = va_arg(st->ap, int);
			st->i++;
		}
		else if (s[st->i] >= '0' && s[st->i] <= '9')
		{
			st->precision = ft_atoi(s + st->i);
			while (s[st->i] >= '0' && s[st->i] <= '9')
				st->i++;
		}
	}
}

int		ft_atoi(const char *str)
{
	int i;
	int res;
	int neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * neg);
}
