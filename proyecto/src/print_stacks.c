/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:06:51 by damedina          #+#    #+#             */
/*   Updated: 2024/04/07 17:06:53 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*top;
	t_node	*tmp;

	if (stack->size > 0)
	{
		top = stack->top;
		tmp = stack->top->next;
		ft_putnbr_fd(top->value, 1);
		ft_putstr_fd("\n", 1);
		while (tmp != top)
		{
			ft_putnbr_fd(tmp->value, 1);
			ft_putstr_fd("\n", 1);
			tmp = tmp->next;
		}
	}
	ft_putstr_fd("\n", 1);
}

void	print_positions(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp != stack->top->prev)
	{
		ft_putnbr_fd(tmp->position, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	ft_putnbr_fd(tmp->position, 1);
	ft_putstr_fd("\n", 1);
}

void	print_costs(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp != stack->top->prev)
	{
		ft_putnbr_fd(tmp->cost, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	ft_putnbr_fd(tmp->cost, 1);
	ft_putstr_fd("\n", 1);
}
