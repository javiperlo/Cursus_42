/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:09:04 by javperez          #+#    #+#             */
/*   Updated: 2024/02/03 15:44:24 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct t_stack
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct t_stack		*target_node;
	struct t_stack		*next;
	struct t_stack		*prev;
}	t_stack;

// Checkear Errores en los parámetros introducidos

int		error_non_int(char *str_n);
int		error_duplicate(t_stack *a, int n);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);

// Si no hay errores, introducir los nodos en el stack_a.
void	append_node_if_no_errors(t_stack **a, char **argv);

void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **s, t_stack *n, char c);

// Utilidades

char	**ft_split(char *s, char c);
int		stack_len(t_stack *stack);
t_stack	*find_last(t_stack *stack);
int		stack_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
void	min_on_top(t_stack **stack_a);

// Comandos
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// Algoritmo
void	sort_three(t_stack **a);
void	sort_big(t_stack **a, t_stack **b);

#endif