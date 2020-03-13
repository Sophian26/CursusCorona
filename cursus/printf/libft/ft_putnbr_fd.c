/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <sberbagu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 18:05:11 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/17 13:59:29 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_int_to_char(int i, int fd)
{
	char c;

	c = '0' + i;
	write(fd, &c, 1);
}

int		ft_putnbr_rec(int nb, int fd, int count)
{
	long i;

	i = nb;
	if (i < 0)
	{
		write(fd, "-", 1);
		i = -i;
	}
	if (i != 0)
	{
		ft_putnbr_rec(i / 10, fd, count + 1);
		ft_int_to_char(i % 10, fd);
	}
	return (count);
}

int		ft_putnbr_fd(int n, int fd)
{
	int i;
	i = 0;
	
	if (n == 0)
	{
		write(fd, "0", 1);
		i = 1;
	}
	else
		i = ft_putnbr_rec(n, fd, i);
	return (i);
}
