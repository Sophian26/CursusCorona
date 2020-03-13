/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 15:30:36 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 12:38:41 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_endtrim(char const *s1, char const *set)
{
	int i;
	int j;
	int test;

	i = 0;
	j = 0;
	test = 0;
	while (s1[i] != '\0')
		i++;
	while (i != 0 && test == 0)
	{
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (set[j] != s1[i])
		{
			test = 1;
			i++;
		}
		i--;
		j = 0;
	}
	return (i + 1);
}

int			ft_starttrim(char const *s1, char const *set)
{
	int k;
	int j;
	int test;

	k = 0;
	j = 0;
	test = 0;
	while (s1[k] != '\0' && test == 0)
	{
		while (s1[k] != set[j] && set[j] != '\0')
			j++;
		if (set[j] != s1[k])
			test = 1;
		k++;
		j = 0;
	}
	return (k);
}

char		*ft_strtrimz(char const *s1, int i, int k)
{
	int		j;
	char	*s2;

	j = 0;
	if (!(s2 = malloc(sizeof(char) * (i - k + 1))))
		return (0);
	while (k < i)
	{
		s2[j] = s1[k];
		k++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	i = ft_endtrim(s1, set);
	j = 0;
	k = ft_starttrim(s1, set) - 1;
	if (i <= k)
	{
		if (!(s2 = ft_calloc(sizeof(char), 1)))
			return (0);
	}
	else
		s2 = ft_strtrimz(s1, i, k);
	return (s2);
}
