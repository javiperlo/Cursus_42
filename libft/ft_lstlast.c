/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:49:23 by javperez          #+#    #+#             */
/*   Updated: 2023/10/11 12:20:08 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Devolver el último nodo de la lista.
/*
** El tipo de función t_list devuelve una lista enlazada. Declarada en libft.h
*/
t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*
** Mientras que lst != NULL
** si lst -> es nulo (No hay un nodo siguiente)
** return (lst) El elemento ultimo
** Si no, sigue avanzando
*/
/*
int	main(void)
{
    t_list	*lst;

    lst = malloc(sizeof(t_list));
    lst->content = (int *)3;
    lst->next = malloc(sizeof(t_list));
	lst->next->content = (int *)5;
    lst->next->next = malloc(sizeof(t_list));
	lst->next->next->content = (int *)7;
    lst->next->next->next = NULL;
    
    t_list *last_node = ft_lstlast(lst);
    printf("El último nodo tiene el valor: %p\n", last_node->content);
    //Y aqui me imprimes el contenido del ultimo elemento
    return (0);
}*/