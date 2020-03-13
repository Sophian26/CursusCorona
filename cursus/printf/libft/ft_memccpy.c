/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 14:26:33 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 18:09:34 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int				i;
	const char		*src2;
	unsigned char	*dest2;
	unsigned char	c2;

	i = 0;
	dest2 = dest;
	src2 = src;
	c2 = c;
	while ((unsigned char)src2[i] != c2 && n > 0)
	{
		dest2[i] = (unsigned char)src2[i];
		i++;
		n--;
	}
	if ((unsigned char)src2[i] == c2)
	{
		dest2[i] = (unsigned char)src2[i];
		return (&dest[i + 1]);
	}
	return (0);
}
