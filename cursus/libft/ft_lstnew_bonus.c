/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 14:51:57 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 16:49:04 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list) * 1)))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
