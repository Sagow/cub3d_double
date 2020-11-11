/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:19:07 by marina            #+#    #+#             */
/*   Updated: 2019/11/17 19:12:29 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*chainlink;

	if (!(chainlink = (t_list*)malloc(sizeof(chainlink))))
		return (NULL);
	chainlink->content = content;
	chainlink->next = NULL;
	return (chainlink);
}
