/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:15:39 by damedina          #+#    #+#             */
/*   Updated: 2024/01/29 13:15:41 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	insert_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = stack_a->top;
	if (stack_b->top->value > stack_a->max_value
		|| stack_b->top->value < stack_a->min_value)
	{
		while (node->value != stack_a->min_value)
			node = node->next;
	}
	else
	{
		while (!(node->prev->value < stack_b->top->value
				&& node->value > stack_b->top->value))
			node = node->next;
	}
	while (node->position > stack_a->size / 2 && stack_a->top != node)
		rra(stack_a);
	while (node->position <= stack_a->size / 2 && stack_a->top != node)
		ra(stack_a);
	pa(stack_a, stack_b);
}

void	insert_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	int		min_cost;
	int		i;

	if (stack_b->size == 0 || stack_b->size == 1)
		pb(stack_a, stack_b);
	else
	{
		count_moves(stack_a, stack_b);
		min_cost = stack_a->top->cost;
		tmp = stack_a->top;
		i = -1;
		while (++i < stack_a->size)
		{
			if (tmp->cost < min_cost)
				min_cost = tmp->cost;
			tmp = tmp->next;
		}
		push_min_cost(stack_a, stack_b, min_cost);
	}
}

void	sort_stack_a(t_stack *stack_a)
{
	t_node	*node;

	node = stack_a->top;
	while (node->value != stack_a->min_value)
		node = node->next;
	while (node->position > stack_a->size / 2 && stack_a->top != node)
		rra(stack_a);
	while (node->position <= stack_a->size / 2 && stack_a->top != node)
		ra(stack_a);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sort_down(stack_a))
	{
		if (stack_a->size <= 3)
			short_sort(stack_a);
		else
		{
			while (stack_a->size != 3)
				insert_b(stack_a, stack_b);
			short_sort(stack_a);
			while (stack_b->size > 0)
				insert_a(stack_a, stack_b);
			while (!is_sort_down(stack_a))
				sort_stack_a(stack_a);
		}
	}
}
