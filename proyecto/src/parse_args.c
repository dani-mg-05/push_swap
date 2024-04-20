/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:45:45 by damedina          #+#    #+#             */
/*   Updated: 2024/04/07 17:45:47 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	in_stack(t_stack *stack, int n)
{
	t_node	*node;

	if (stack->top != 0)
	{
		node = stack->top;
		while (node->next != stack->top)
		{
			if (n == node->value)
				return (1);
			node = node->next;
		}
		if (n == node->value)
			return (1);
	}
	return (0);
}

static int	count_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		num_args;
	char	**tmp;

	num_args = 0;
	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			tmp = ft_split(argv[i], ' ');
			if (!tmp)
				return (0);
			j = -1;
			while (tmp[++j])
				num_args++;
			free_split(tmp);
		}
		else
			num_args++;
	}
	return (num_args);
}

static char	**parse_args_aux(char **argv, int *num_args, int i, char **args)
{
	char	**tmp;
	int		j;

	if (argv[i][0] == '\0')
		return (free_args(args, *num_args));
	tmp = ft_split(argv[i], ' ');
	if (!tmp)
		return (0);
	j = -1;
	while (tmp[++j])
	{
		args[*num_args] = ft_strdup(tmp[j]);
		if (!args[*num_args])
		{
			free_split(tmp);
			return (free_args(args, *num_args));
		}
		(*num_args)++;
	}
	free_split(tmp);
	return (args);
}

char	**parse_args(int argc, char **argv, int *num_args)
{
	int		i;
	char	**args;

	args = (char **)malloc(count_args(argc, argv) * sizeof (char *));
	if (!args)
		return (0);
	i = 0;
	while (++i < argc)
	{
		args = parse_args_aux(argv, num_args, i, args);
		if (!args)
			return (0);
	}
	return (args);
}
