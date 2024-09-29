/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:10:11 by javperez          #+#    #+#             */
/*   Updated: 2024/02/03 12:25:10 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_stack **head)
{
	t_stack		*temp;

	temp = (*head)->next;
	if (!*head || !(*head)->next)
		return ;
	(*head)->prev = temp;
	(*head)->next = temp->next;
	if (temp->next)
		temp->next->prev = *head;
	temp->next = *head;
	temp->prev = NULL;
	*head = temp;
}

void	sa(t_stack	**stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
