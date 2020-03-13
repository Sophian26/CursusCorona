/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:47:39 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 18:21:05 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char		*ft_subsub(void)
{
	char *s2;

	if (!(s2 = malloc(sizeof(char) * 1)))
		return (NULL);
	s2[0] = '\0';
	return (s2);
}

char			*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*s2;

	if (!s)
		return (0);
	if (len < 0)
	{	
		free(s);
		return (NULL);
	}
	i = start;
	j = 0;
	if (start > ft_strlen(s))
		return (ft_subsub());
	while (s[i] != '\0' && (len > i - start))
		i++;
	if (!(s2 = malloc(sizeof(char) * i - start + 1)))
		return (NULL);
	while (j < len && s[start] != '\0')
	{
		s2[j] = s[start];
		start++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}