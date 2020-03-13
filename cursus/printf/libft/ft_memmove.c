/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 16:16:01 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 18:54:06 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest2;
	const char		*src2;

	dest2 = dest;
	src2 = src;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
		dest2 = ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i > 0 && n > 0)
		{
			dest2[i - 1] = src2[i - 1];
			i--;
		}
	}
	return (dest2);
}
