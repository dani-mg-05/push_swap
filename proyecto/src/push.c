/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:29:12 by damedina          #+#    #+#             */
/*   Updated: 2024/01/29 12:29:16 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_min_cost_aux(t_stack *stack_b, t_node *node)
{
	t_node	*node_aux;

	node_aux = stack_b->top;
	if (node->value < stack_b->min_value || node->value > stack_b->max_value)
	{
		while (node_aux->value != stack_b->max_value)
			node_aux = node_aux->next;
	}
	else
	{
		while (!(node_aux->prev->value > node->value
				&& node_aux->value < node->value))
			node_aux = node_aux->next;
	}
	while (node_aux->position > stack_b->size / 2 && stack_b->top != node_aux)
		rrb(stack_b);
	while (node_aux->position <= stack_b->size / 2 && stack_b->top != node_aux)
		rb(stack_b);
}

void	push_min_cost(t_stack *stack_a, t_stack *stack_b, int min_cost)
{
	t_node	*node;
	int		b_moves;

	node = stack_a->top;
	while (node->cost != min_cost)
		node = node->next;
	b_moves = moves_b(stack_b, node->value, &node->dir_b);
	while (node->dir_a == node->dir_b && node != stack_a->top && b_moves > 0)
	{
		if (node != stack_a->top && node->dir_a == 0)
			rr(stack_a, stack_b);
		if (b_moves-- > 0 && node->dir_a == 1)
			rrr(stack_a, stack_b);
	}
	if (node != stack_a->top)
	{
		while (node->dir_a == 0 && node != stack_a->top)
			ra(stack_a);
		while (node->dir_a == 1 && node != stack_a->top)
			rra(stack_a);
	}
	push_min_cost_aux(stack_b, node);
	pb(stack_a, stack_b);
}

void	push(t_stack *dst, t_stack *src)
{
	t_node	*src_top;

	if (src->size < 1)
		return ;
	src_top = src->top;
	change_max_min(dst, src, src_top);
	src->top = src->top->next;
	src->top->prev = src_top->prev;
	src_top->prev->next = src->top;
	src->size--;
	if (dst->size == 0)
	{
		dst->top = src_top;
		dst->top->next = dst->top;
		dst->top->prev = dst->top;
	}
	else
	{
		src_top->next = dst->top;
		src_top->prev = dst->top->prev;
		dst->top->prev = src_top;
		src_top->prev->next = src_top;
		dst->top = src_top;
	}
	dst->size++;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}
