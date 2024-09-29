/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:05:10 by javperez          #+#    #+#             */
/*   Updated: 2023/10/13 12:03:52 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * PARÁMETROS
 * 
 * lst: la dirección de un puntero a un nodo.
 * del: un puntero a función utilizado para eliminar
 * el contenido de un nodo.
 * 
 * DESCRIPCIÓN
 * 
 * Elimina y libera el nodo ’lst’ dado y todos los
 * consecutivos de ese nodo, utilizando la función
 * ’del’ y free(3).
 * Al final, el puntero a la lista debe ser NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*mylst;
	t_list		*aux;

	mylst = *lst;
	if (!lst || !del)
		return ;
	while (mylst != NULL)
	{
		aux = mylst->next;
		del(mylst->content);
		free(mylst);
		mylst = aux;
	}
	*lst = NULL;
}
/**
 * En primer lugar, verificamos que lst y del
 * contenga algo, de lo contrario, se cortará el programa
 * 
 * Recorremos la lista, mientras que no sea nulo, recorremos
 * la lista. He creado dos variables auxiliares. 
 * 
 * mylist: Almacena el valor del puntero de *lst.
 * aux: almacena el valor del siguiente elemento antes
 * de borrar y haacer el free.
 * 
 * Entonces en el bucle while, por cada elemento, se almacena en aux
 * y posteriormente se borra el contenido del elemento iterado y 
 * posteriormente se libera la memoria de ese elemento.
 * Y se asigna el valor de aux iterado en mylst.
 * 
 * Como tiene que terminar en NULL la lista enlazada.
 * Ponemos que el puntero despues de iterar toda la cadena, que
 * será el último, sea NULL.
*/