/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:44:16 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 17:53:34 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strle(char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			*ft_strdup(const char *src)
{
	char	*mem;
	int		i;
	char	*src2;

	i = 0;
	src2 = (char *)src;
	if (!(mem = malloc((sizeof(char) * (ft_strle(src2) + 1)))))
		return (NULL);
	while (src2[i] != '\0')
	{
		mem[i] = src2[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
