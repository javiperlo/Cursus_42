/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:49:18 by javperez          #+#    #+#             */
/*   Updated: 2023/09/29 13:06:41 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*2*
 * PARÁMETROS
 * 
 * lst --> El nodo a liberar
 * de --> Un puntero a
 * la función utilizada para liberar el 
 * contenido del nodo.
 * 
 * DESCRIPCIÓN:
 * 
 * Toma como parámetro un nodo ’lst’ y libera la
 * memoria del contenido utilizando la función ’del’
 * dada como parámetro, además de liberar el nodo. La
 * memoria de ’next’ no debe liberarse. 
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
