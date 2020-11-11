/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:04:45 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/17 20:48:42 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (!new || !alst)
		return ;
	lst = *alst;
	if (!lst)
	{
		*alst = new;
		return ;
	}
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
	new->next = NULL;
}
