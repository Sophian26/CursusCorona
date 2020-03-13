/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 14:31:25 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 18:34:41 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	const char		*src2;

	i = 0;
	dest2 = dest;
	src2 = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > i)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
