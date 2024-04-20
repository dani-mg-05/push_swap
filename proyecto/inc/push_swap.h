/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:05:58 by damedina          #+#    #+#             */
/*   Updated: 2023/12/30 17:06:00 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				position;
	int				cost;
	int				dir_a;
	int				dir_b;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	int		max_value;
	int		min_value;
}	t_stack;

void	push(t_stack *dst, t_stack *src);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	push_min_cost(t_stack *stack_a, t_stack *stack_b, int min_cost);
void	change_max_min(t_stack *dst, t_stack *src, t_node *node);
int		is_sort_down(t_stack *stack);
int		is_sort_up(t_stack *stack);
void	short_sort(t_stack *stack_a);
void	sort(t_stack *stack_a, t_stack *stack_b);
int		moves_a(t_stack *stack_a, int position, int *dir);
int		moves_b(t_stack *stack_b, int value, int *dir);
void	count_moves(t_stack *stack_a, t_stack *stack_b);
char	**parse_args(int argc, char **argv, int *num_args);
int		in_stack(t_stack *stack, int n);
t_stack	*clean_stack(t_stack *stack);
char	**free_split(char **split);
char	**free_args(char **args, int num_args);
int		show_error(void);
void	print_stack(t_stack *stack);
void	print_positions(t_stack *stack);

#endif
