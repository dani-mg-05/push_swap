/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:39:00 by damedina          #+#    #+#             */
/*   Updated: 2024/07/23 20:42:39 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

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

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	return (1);
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	return (1);
}
