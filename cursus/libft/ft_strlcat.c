/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 17:24:35 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/27 19:01:38 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strle(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_strnle(char *s, size_t size)
{
	size_t i;

	i = 0;
	while (s[i] && i < size)
		i++;
	return (i);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strnle(dst, size);
	if (size <= len)
		return (ft_strle((char *)src) + size);
	while (src[i] != '\0')
	{
		if ((len + i) < size - 1)
			dst[len + i] = src[i];
		if ((len + i) == size - 1)
			dst[len + i] = '\0';
		i++;
	}
	if (len + i <= size - 1)
		dst[len + i] = '\0';
	return (i + len);
}
