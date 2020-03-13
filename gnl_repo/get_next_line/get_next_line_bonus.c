/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_bonus.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dpuccion <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 16:50:31 by dpuccion     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 16:51:03 by dpuccion    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_join_line(int ret, char *buf, char *stock)
{
	buf[ret] = '\0';
	stock = ft_strjoin(stock, buf);
	return (stock);
}

static char	*ft_get_exce(char **line, char *stock, int nli)
{
	*line = ft_strdup(stock);
	stock = ft_substr(stock, nli);
	return (stock);
}

static char	*ft_reset_stock(char **line, char *stock)
{
	*line = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (stock);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	int			nli;
	static char	*stock;
	char		buf[BUFFER_SIZE + 1];

	ret = 1;
	if (!line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		stock = ft_join_line(ret, buf, stock);
		if (((nli = ft_findnl(stock)) > -1))
		{
			stock = ft_get_exce(line, stock, nli);
			return (1);
		}
	}
	if ((nli == -1) && ret < BUFFER_SIZE)
	{
		stock = ft_reset_stock(line, stock);
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
