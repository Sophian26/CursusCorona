/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dpuccion <dpuccion@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 16:01:49 by dpuccion     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 19:27:46 by dpuccion    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(count * size)))
		return (NULL);
	while (i < (count * size))
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
