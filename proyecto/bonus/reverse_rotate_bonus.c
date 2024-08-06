/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:51:05 by damedina          #+#    #+#             */
/*   Updated: 2024/07/24 05:15:23 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size <= 1)
		return ;
	stack->top = stack->top->prev;
	node = stack->top;
	while (node->position != stack->size - 1)
	{
		node->position++;
		node = node->next;
	}
	node->position = 0;
}

int	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	return (1);
}

int	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	return (1);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (1);
}
