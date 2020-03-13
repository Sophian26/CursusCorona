/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsize_bonus.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 15:08:33 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 14:04:50 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_recsize(t_list *lst, int i)
{
	if (lst->next != NULL)
		return (ft_recsize(lst->next, i + 1));
	else
		return (i);
}

int		ft_lstsize(t_list *lst)
{
	int i;

	if (lst == NULL)
		return (0);
	else if (lst->next == NULL)
		return (1);
	else
		i = ft_recsize(lst, 1);
	return (i);
}
