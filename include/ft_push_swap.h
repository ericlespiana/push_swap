/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:50:37 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:01:32 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				cost;
	struct s_stack	*next;
}	t_stack;

typedef struct push
{
	int		max_value;
	int		media;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_push;

t_stack		*init_stack_a(int argc, char **argv);
t_stack		*last_node(t_stack *lst);
t_stack		*penult_node(t_stack *lst);
t_stack		*new_node(int data);
long int	ft_atol(const char *n);
void		ft_parse_arguments(int argc, char **argv);
void		ft_error(char *MSG);
void		init_list(t_push **stacks);
void		init_stack(t_stack **stack);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_a);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrb(t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		free_list(t_stack *stack);
void		push_swap(t_push **stacks);
void		put_index(t_push **stacks);
void		media_and_push(t_push **stacks);
void		update_rrr(t_push **stacks, int a, int b);
void		update_rr(t_push **stacks, int a, int b);
int			get_highest(t_stack *stack);
int			ft_strcmp(char *s1, char *s2);
int			lst_size(t_stack *lst);
int			is_ordered(t_stack *stack);
int			get_abs(int a, int b);
int			find_cheaper(t_stack *stack_b);
int			get_min_position(t_stack *stack_a);
void		find_position(t_push **stacks);
void		find_target_pos(t_push **stacks);
void		calculate_costs(t_push **stacks);
void		total_cost(t_push **stacks);
void		find_op(t_push **stacks);

# define INT_MIN -2147483648
# define INT_MAX  2147483647
# define MIN_ARGS 2
# define TRUE 1
# define FALSE 0
# define ERROR "Error\n"

#endif
