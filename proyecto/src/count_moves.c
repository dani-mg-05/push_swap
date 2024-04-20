/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:53:25 by damedina          #+#    #+#             */
/*   Updated: 2024/03/23 17:53:26 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	moves_a(t_stack *stack_a, int position, int *dir)
{
	if (position > stack_a->size / 2)
	{
		*dir = 1;
		return (stack_a->size - position);
	}
	*dir = 0;
	return (position);
}

int	moves_b(t_stack *stack_b, int value, int *dir)
{
	t_node	*node;

	node = stack_b->top;
	if (value > stack_b->max_value || value < stack_b->min_value)
	{
		while (node->value != stack_b->max_value)
			node = node->next;
	}
	else
	{
		while (!(node->prev->value > value && node->value < value))
			node = node->next;
	}
	return (moves_a(stack_b, node->position, dir));
}

void	count_moves(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_a;
	int		a_moves;
	int		b_moves;
	int		moves;
	int		i;

	node_a = stack_a->top;
	i = -1;
	while (++i < stack_a->size)
	{
		a_moves = moves_a(stack_a, node_a->position, &node_a->dir_a);
		b_moves = moves_b(stack_b, node_a->value, &node_a->dir_b);
		if (stack_b->size == 2 && a_moves > 0 && b_moves > 0)
			node_a->dir_b = node_a->dir_a;
		moves = a_moves + b_moves;
		while (a_moves != 0 && b_moves != 0 && node_a->dir_a == node_a->dir_b)
		{
			a_moves--;
			b_moves--;
			moves--;
		}
		node_a->cost = moves + 1;
		node_a = node_a->next;
	}
}
