/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_aux_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:44:54 by damedina          #+#    #+#             */
/*   Updated: 2024/07/23 20:45:01 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

static void	change_positions(t_stack *dst, t_stack *src)
{
	t_node	*tmp;
	int		i;

	i = 1;
	tmp = dst->top;
	if (dst->size > 0)
	{
		while (tmp != dst->top->prev)
		{
			tmp->position = i;
			i++;
			tmp = tmp->next;
		}
		tmp->position = i;
	}
	i = 0;
	tmp = src->top->next;
	while (tmp != src->top)
	{
		tmp->position = i;
		i++;
		tmp = tmp->next;
	}
}

static void	change_max_min_aux(t_stack *src, t_node *node)
{
	t_node	*tmp;
	int		aux;

	tmp = src->top->next;
	aux = tmp->value;
	if (node->value == src->max_value)
	{
		while (tmp != src->top)
		{
			if (tmp->value > aux)
				aux = tmp->value;
			tmp = tmp->next;
		}
		src->max_value = aux;
	}
	if (node->value == src->min_value)
	{
		while (tmp != src->top)
		{
			if (tmp->value < aux)
				aux = tmp->value;
			tmp = tmp->next;
		}
		src->min_value = aux;
	}
}

void	change_max_min(t_stack *dst, t_stack *src, t_node *node)
{
	if (node->value > dst->max_value)
		dst->max_value = node->value;
	if (node->value < dst->min_value)
		dst->min_value = node->value;
	if (src->size == 1)
	{
		src->max_value = 0;
		src->min_value = 0;
	}
	if (dst->size == 0)
	{
		dst->max_value = node->value;
		dst->min_value = node->value;
	}
	change_max_min_aux(src, node);
	change_positions(dst, src);
}
