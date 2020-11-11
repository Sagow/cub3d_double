/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:56:59 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/17 22:12:20 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;

	if (!lst)
		return (0);
	if (!(node = malloc(sizeof(t_list))))
		return (NULL);
	if (lst->next != NULL)
	{
		if ((node->next = ft_lstmap((lst->next), f, del)) == NULL)
		{
			free(node);
			return (NULL);
		}
	}
	node->content = (*f)(lst->content);
	if (lst->next == NULL)
		node->next = NULL;
	return (node);
}
