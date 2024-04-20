/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:05:51 by damedina          #+#    #+#             */
/*   Updated: 2023/12/30 17:05:55 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof (t_stack));
	if (!stack)
		return (0);
	stack->top = 0;
	stack->size = 0;
	stack->max_value = 0;
	stack->min_value = 0;
	return (stack);
}

void	add_elem(t_stack *stack, t_node *node, int value)
{
	node->value = value;
	node->position = stack->size;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->max_value = node->value;
		stack->min_value = node->value;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev->next = node;
		stack->top->prev = node;
		if (node->value < stack->min_value)
			stack->min_value = node->value;
		else if (node->value > stack->max_value)
			stack->max_value = node->value;
	}
	stack->size++;
}

static t_stack	*fill_a_aux(t_stack *stack_a, char **args, int num_args)
{
	t_node	*node;
	int		i;

	i = -1;
	while (++i < num_args)
	{
		node = (t_node *)malloc(sizeof (t_node));
		if (!node || (ft_atoi(args[i]) == 0 && args[i][0] != '0')
			|| ft_atoi(args[i]) > INT_MAX || ft_atoi(args[i]) < INT_MIN
			|| in_stack(stack_a, ft_atoi(args[i])))
		{
			free(node);
			free_args(args, num_args);
			return (clean_stack(stack_a));
		}
		add_elem(stack_a, node, ft_atoi(args[i]));
	}
	free_args(args, num_args);
	return (stack_a);
}

t_stack	*fill_a(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**args;
	int		num_args;

	stack_a = new_stack();
	if (!stack_a)
		return (0);
	num_args = 0;
	args = parse_args(argc, argv, &num_args);
	if (!args)
		return (clean_stack(stack_a));
	if (num_args < 1)
	{
		free_args(args, num_args);
		return (clean_stack(stack_a));
	}
	return (fill_a_aux(stack_a, args, num_args));
}
/*
void	check_leaks(void)
{
	system("leaks -q push_swap");
}
*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = fill_a(argc, argv);
	if (!stack_a)
		return (show_error());
	if (stack_a->size == 1)
	{
		clean_stack(stack_a);
		return (1);
	}
	stack_b = new_stack();
	if (!stack_b)
	{
		clean_stack(stack_a);
		return (show_error());
	}
	sort(stack_a, stack_b);
	clean_stack(stack_a);
	clean_stack(stack_b);
	return (0);
}
