/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:34:51 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 17:46:41 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int ssrc;

	if (!dst || !src)
		return (0);
	i = 0;
	ssrc = 0;
	while (src[ssrc])
		ssrc++;
	if (size == 0)
		return (ssrc);
	while (src[i] != '\0' && (size - 1) > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ssrc);
}
