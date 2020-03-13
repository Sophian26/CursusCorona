/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear_bonus.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 13:00:52 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 16:48:41 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *cour;

	cour = *lst;
	while (cour != NULL)
	{
		temp = cour;
		cour = cour->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
