/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:03:11 by javperez          #+#    #+#             */
/*   Updated: 2023/09/25 13:05:36 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i ++;
	}
	return (i);
}
/*
int	main(void)
{
	int		i;
	
	t_list *lst = ft_lstnew((int *)42);
    lst->next = ft_lstnew((int *)24);
    lst->next -> next = ft_lstnew((int *)24);
    lst->next->next -> next = NULL;
	i = ft_lstsize(lst);
	printf("El tamaño de la lista es: %d\n", i);
	return (0);
}*/
