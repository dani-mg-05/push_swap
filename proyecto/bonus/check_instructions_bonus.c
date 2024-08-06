/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:47:46 by damedina          #+#    #+#             */
/*   Updated: 2024/07/24 06:04:36 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

static void	free_gnl(void)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		free(line);
		line = get_next_line(0);
	}
}

static int	is_sort_down(t_stack *stack)
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

static int	check_instruction(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3) || !ft_strncmp(line, "sa\0", 3))
		return (sa(stack_a));
	else if (!ft_strncmp(line, "sb\n", 3) || !ft_strncmp(line, "sb\0", 3))
		return (sb(stack_b));
	else if (!ft_strncmp(line, "ss\n", 3) || !ft_strncmp(line, "ss\0", 3))
		return (ss(stack_a, stack_b));
	else if (!ft_strncmp(line, "pa\n", 3) || !ft_strncmp(line, "pa\0", 3))
		return (pa(stack_a, stack_b));
	else if (!ft_strncmp(line, "pb\n", 3) || !ft_strncmp(line, "pb\0", 3))
		return (pb(stack_a, stack_b));
	else if (!ft_strncmp(line, "ra\n", 3) || !ft_strncmp(line, "ra\0", 3))
		return (ra(stack_a));
	else if (!ft_strncmp(line, "rb\n", 3) || !ft_strncmp(line, "rb\0", 3))
		return (rb(stack_b));
	else if (!ft_strncmp(line, "rr\n", 3) || !ft_strncmp(line, "rr\0", 3))
		return (rr(stack_a, stack_b));
	else if (!ft_strncmp(line, "rra\n", 4) || !ft_strncmp(line, "rra\0", 4))
		return (rra(stack_a));
	else if (!ft_strncmp(line, "rrb\n", 4) || !ft_strncmp(line, "rrb\0", 4))
		return (rrb(stack_b));
	else if (!ft_strncmp(line, "rrr\n", 4) || !ft_strncmp(line, "rrr\0", 4))
		return (rrr(stack_a, stack_b));
	return (0);
}

int	check_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_instruction(stack_a, stack_b, line))
		{
			free(line);
			clean_stack(stack_a);
			clean_stack(stack_b);
			close(0);
			free_gnl();
			return (show_error());
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sort_down(stack_a) && stack_b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clean_stack(stack_a);
	clean_stack(stack_b);
	return (0);
}
