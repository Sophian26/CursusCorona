/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 18:05:11 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 13:56:17 by sberbagu    ###    #+. /#+    ###.fr     */
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

void		ft_putnbr_rec(int nb, int fd)
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
		ft_putnbr_rec(i / 10, fd);
		ft_int_to_char(i % 10, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else
		ft_putnbr_rec(n, fd);
}
