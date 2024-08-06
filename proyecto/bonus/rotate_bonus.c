/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:48:38 by damedina          #+#    #+#             */
/*   Updated: 2024/07/24 05:09:16 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size <= 1)
		return ;
	stack->top = stack->top->next;
	node = stack->top;
	while (node->position != 0)
	{
		node->position--;
		node = node->next;
	}
	node->position = stack->size - 1;
}

int	ra(t_stack *stack_a)
{
	rotate(stack_a);
	return (1);
}

int	rb(t_stack *stack_b)
{
	rotate(stack_b);
	return (1);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	return (1);
}
