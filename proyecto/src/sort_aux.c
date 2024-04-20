/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:34:06 by damedina          #+#    #+#             */
/*   Updated: 2024/04/07 17:34:08 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sort_down(t_stack *stack)
{
	t_node	*node;

	if (stack->size <= 1)
		return (1);
	node = stack->top;
	if (node->value < node->next->value)
		node = node->next;
	else
		return (0);
	while (node->next != stack->top)
	{
		if (node->value < node->next->value)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

int	is_sort_up(t_stack *stack)
{
	t_node	*node;

	if (stack->size <= 1)
		return (1);
	node = stack->top;
	if (node->value > node->next->value)
		node = node->next;
	else
		return (0);
	while (node->next != stack->top)
	{
		if (node->value > node->next->value)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

static void	sort_three(t_stack *stack_a, int first, int second, int third)
{
	if (first > second && second > third)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (second > first && second > third && third > first)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (second > first && second > third)
		rra(stack_a);
	else if (third > first && first > second)
		sa(stack_a);
	else
		ra(stack_a);
}

void	short_sort(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!is_sort_down(stack_a))
	{
		if (stack_a->size == 2)
			ra(stack_a);
		else if (stack_a->size == 3)
		{
			first = stack_a->top->value;
			second = stack_a->top->next->value;
			third = stack_a->top->prev->value;
			sort_three(stack_a, first, second, third);
		}
	}
}
