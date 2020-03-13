/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberbagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:38:16 by sberbagu          #+#    #+#             */
/*   Updated: 2020/02/22 17:38:18 by sberbagu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parslength(const char *s, t_varprintf *str)
{
	int i;

	if (s[str->index] == '*')
	{
		i = va_arg(str->lst, int);
		if (i < 0)
		{
			str->min = 1;
			i = -i;
		}
		str->length = i;
		str->index++;
	}
	else
		str->length = ft_atoi(s, str);
}

void		ft_parsprecis(const char *s, t_varprintf *str)
{
	str->index++;
	str->ispre = 1;
	if (s[str->index] == '*')
	{
		str->precis = va_arg(str->lst, int);
		str->index++;
	}
	if (ft_isdigit(s[str->index]) == 1)
		str->precis = ft_atoi(s, str);
}

void		ft_parsflags(const char *s, t_varprintf *str)
{
	while (s[str->index] == '0' || s[str->index] == '-')
	{
		if (s[str->index] == '0')
			str->zero = 1;
		if (s[str->index] == '-')
			str->min = 1;
		str->index++;
	}
}

int			ft_parsing(const char *s, t_varprintf *str)
{
	while (s[str->index] && s[str->index] != '%')
	{
		write(1, s + str->index, 1);
		str->tot++;
		str->index++;
	}
	if (!s[str->index])
		return (0);
	str->index++;
	while (s[str->index] && (s[str->index] > 'z' || s[str->index] < 'a')
		&& s[str->index] != 'X' && s[str->index] != '%')
	{
		ft_parsflags(s, str);
		if (s[str->index] == '*' || ft_isdigit(s[str->index]) == 1)
			ft_parslength(s, str);
		if (s[str->index] == '.')
			ft_parsprecis(s, str);
	}
	str->type = s[str->index];
	str->index++;
	return (0);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
