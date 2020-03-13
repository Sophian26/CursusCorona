/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 13:54:41 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 17:44:40 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s12;
	unsigned char	*s22;

	s12 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (s12[i] == s22[i] && i < n - 1)
		i++;
	return (s12[i] - s22[i]);
}
