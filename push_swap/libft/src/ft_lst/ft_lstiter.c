/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:24:19 by javperez          #+#    #+#             */
/*   Updated: 2023/09/29 13:34:01 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * DESCRIPCIÓN:
 * 
 * Itera la lista ’lst’ y aplica la función ’f’ en el
 * contenido de cada nodo.
 * 
 * PARÁMETROS:
 * 
 * lst: un puntero al primer nodo.
 * f: un puntero a la función que utilizará cada nodo.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

/**
 * Recorermos cada elemento de la lista
 * y en cada elemento a aplicamos el valro
 * de f() a lst -> content. 
 * Y seguimos iterando
*/
