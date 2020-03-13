/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils_bonus.c                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dpuccion <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 16:52:41 by dpuccion     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 16:57:13 by dpuccion    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	if (s1)
	{
		while (s1[i])
		{
			newstr[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = 0;
	free(s1);
	return (newstr);
}

int		ft_findnl(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	if (s1)
	{
		while (s1[i] && s1[i] != '\n')
			i++;
	}
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i] && s1[i] != '\n')
		{
			dest[i] = s1[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, int start)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		if (!(newstr = malloc(sizeof(char) * 1)))
			return (0);
		newstr[0] = 0;
		return (newstr);
	}
	if (!(newstr = malloc(sizeof(char) * (ft_strlen(s) - start + 1))))
		return (0);
	start++;
	while (s[start])
	{
		newstr[i] = s[start];
		i++;
		start++;
	}
	newstr[i] = '\0';
	free(s);
	return (newstr);
}
