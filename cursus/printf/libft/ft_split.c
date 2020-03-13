/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 17:18:47 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 18:40:22 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_freesplit(char **sf)
{
	int i;

	i = 0;
	while (sf[i] != NULL)
	{
		free(sf[i]);
		i++;
	}
	free(sf);
	return (NULL);
}

static void		ft_ssplit(char const *s, char c, char **sf)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				sf[j][k] = s[i];
				i++;
				k++;
			}
			sf[j][k] = '\0';
			j++;
			k = 0;
		}
		if (s[i] != '\0')
			i++;
	}
	sf[j] = NULL;
}

static void		*ft_malsplit(char const *s, char **sf, char c, int i)
{
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				j++;
				i++;
			}
			if (!(sf[k] = malloc(sizeof(char) * j + 1)))
				return (ft_freesplit(sf));
			j = 0;
			k++;
		}
		if (s[i] != '\0')
			i++;
	}
	sf[k] = NULL;
	return (0);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**sf;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		i++;
	}
	if (!(sf = malloc(sizeof(char *) * j + 1)))
		return (NULL);
	ft_malsplit(s, sf, c, 0);
	ft_ssplit(s, c, sf);
	return (sf);
}
