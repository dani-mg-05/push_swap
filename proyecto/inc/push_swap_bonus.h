/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:39:05 by damedina          #+#    #+#             */
/*   Updated: 2024/07/23 20:45:49 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 1

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
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack);
int		sa(t_stack *stack_a);
int		sb(t_stack *stack_b);
int		ss(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
int		ra(t_stack *stack_a);
int		rb(t_stack *stack_b);
int		rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
int		rra(t_stack *stack_a);
int		rrb(t_stack *stack_b);
int		rrr(t_stack *stack_a, t_stack *stack_b);
void	change_max_min(t_stack *dst, t_stack *src, t_node *node);
int		check_instructions(t_stack *stack_a, t_stack *stack_b);
char	*get_next_line(int fd);
char	**parse_args(int argc, char **argv, int *num_args);
int		in_stack(t_stack *stack, int n);
t_stack	*clean_stack(t_stack *stack);
char	**free_split(char **split);
char	**free_args(char **args, int num_args);
int		show_error(void);

#endif
