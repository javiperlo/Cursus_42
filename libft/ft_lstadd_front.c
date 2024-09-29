/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:20:31 by javperez          #+#    #+#             */
/*   Updated: 2023/09/29 12:02:07 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
echo -e "${endColour}"
	lst: la dirección de un puntero al primer nodo de
	una lista.
	new: un puntero al nodo que añadir al principio de
	la lista.*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new -> next = *lst;
		*lst = new;
	}
}
/*
int	main(void)
{
	t_list *lst;
	t_list *new;
	
	lst = ft_lstnew("Hola");
	new = ft_lstnew("Mundo");
	ft_lstadd_front(&lst, new);
	printf("%s\n", (char *)lst -> content);
	printf("%s\n", (char *)lst -> next -> content);
	return (0);
}*/