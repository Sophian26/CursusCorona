/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 18:41:45 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 18:14:47 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_icount(long n)
{
	long i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*ft_malitoa(long n, long i)
{
	char *str;

	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (n < 0)
		n = -n;
	return (str);
}

char			*ft_itoa(int n)
{
	long i;
	char *str;
	long n2;

	n2 = n;
	i = ft_icount(n2) - 1;
	if (!(str = ft_malitoa(n2, i + 1)))
		return (NULL);
	str[i + 1] = '\0';
	if (n < 0)
		n2 = -n2;
	while (i >= 0)
	{
		str[i] = '0' + (n2 % 10);
		n2 = n2 / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	return (str);
}
