/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:29:56 by damedina          #+#    #+#             */
/*   Updated: 2024/07/23 20:30:05 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

t_stack	*clean_stack(t_stack *stack)
{
	t_node	*node;

	while (stack->size != 0)
	{
		node = stack->top;
		stack->top = stack->top->next;
		stack->size--;
		free(node);
	}
	free(stack);
	return (0);
}

char	**free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (0);
}

char	**free_args(char **args, int num_args)
{
	while (--num_args >= 0)
		free(args[num_args]);
	free(args);
	return (0);
}

int	show_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}
