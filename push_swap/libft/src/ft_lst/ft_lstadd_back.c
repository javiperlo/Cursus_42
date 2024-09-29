/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:05:15 by javperez          #+#    #+#             */
/*   Updated: 2023/09/29 12:48:03 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Descripción: Añade el nodo 'new' al final de la lista 'lst'
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}
/**
 * Utilizamos una variable de apoyo como
 * es t_list *last para poder almacenar
 * el valor del puntero *lst y jugar con el.
 * 
 * Poner (*lst) es lo mismo que poner
 * una variable de apoyo que sea por ej
 * t_list *last = *lst;
 * 
 * En primer lugar verificamos si el
 * primer elemento de la estructura lst
 * es NULO. Si es nulo, me asignas el valor
 * de new en el primer valor del nodo lst.
 * 
 * Si no, mientras que el next de lst no sea
 * nulo, entonces sigues iterando lst.
 * 
 * En la iteración donde se haya quedado
 * *lst -> next significa que es el último,
 * de modo que me asignas el valor de new en ese
 * nodo.
*/