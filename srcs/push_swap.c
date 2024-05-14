/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:44:26 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:02:27 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_many(t_push **stacks);
static void	sort_three(t_push **stacks);
static void	sort_stack_a(t_push **stacks);

void	push_swap(t_push **stacks)
{
	if (is_ordered((*stacks)->stack_a) == 1)
	{
		free_list((*stacks)->stack_a);
		exit(1);
	}
	if (lst_size((*stacks)->stack_a) <= 3)
		sort_three(stacks);
	else
	{
		put_index(stacks);
		media_and_push(stacks);
		sort_three(stacks);
		sort_many(stacks);
	}
}

void	sort_three(t_push **stacks)
{
	(*stacks)->max_value = get_highest((*stacks)->stack_a);
	if ((*stacks)->stack_a->data == (*stacks)->max_value)
		ra(&(*stacks)->stack_a);
	else if ((*stacks)->stack_a->next->data == (*stacks)->max_value)
		rra(&(*stacks)->stack_a);
	if ((*stacks)->stack_a->data > (*stacks)->stack_a->next->data)
		sa(&(*stacks)->stack_a);
}

static void	sort_many(t_push **stacks)
{
	while ((*stacks)->stack_b != NULL)
	{
		find_position(stacks);
		find_target_pos(stacks);
		calculate_costs(stacks);
		total_cost(stacks);
		find_op(stacks);
	}
	find_position(stacks);
	sort_stack_a(stacks);
}

static void	sort_stack_a(t_push **stacks)
{
	int		lowest_pos;
	int		stack_size;

	stack_size = lst_size((*stacks)->stack_a);
	lowest_pos = get_min_position((*stacks)->stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(&(*stacks)->stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(&(*stacks)->stack_a);
			lowest_pos--;
		}
	}
}
