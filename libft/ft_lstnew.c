/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:45:04 by javperez          #+#    #+#             */
/*   Updated: 2023/09/24 21:52:03 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (new_element == NULL)
		return (NULL);
	new_element -> content = content;
	new_element -> next = NULL;
	return (new_element);
}
/*
int main()
{
    char	*str;
	str = "javi";
	printf("La string a imprimir dentro de la estructura enlazada es: %s\n", str);
    t_list *node = ft_lstnew(str);
	
    printf("Node content: %s\n", (char *)node->content);
    printf("Node next: %p\n", node->next);

    return 0;
}*/