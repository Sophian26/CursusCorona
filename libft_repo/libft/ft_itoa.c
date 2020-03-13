/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dpuccion <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 17:10:15 by dpuccion     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/29 13:01:19 by dpuccion         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		count(int n)
{
	int i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char		*ifnotintmin(int n)
{
	char	*res;
	int		size;
	int		neg;

	neg = 0;
	size = count(n);
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	if (!(res = malloc(sizeof(char) * (size + 1 + neg))))
		return (0);
	if (neg)
		res[0] = '-';
	res[size + neg] = 0;
	while (size)
	{
		res[size - (neg ? 0 : 1)] = '0' + n % 10;
		n = n / 10;
		size--;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (ifnotintmin(n));
}
