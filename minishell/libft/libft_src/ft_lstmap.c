/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:52:23 by javperez          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*curr;

	head = ft_lstnew(f(lst->content));
	if (!head)
		return (0);
	curr = head;
	while (lst->next)
	{
		lst = lst->next;
		curr = ft_lstnew(f(lst->content));
		if (!curr)
		{
			ft_lstclear(&head, del);
			return (head);
		}
		ft_lstadd_back(&head, curr);
	}
	return (head);
}
