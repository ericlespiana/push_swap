/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:13:49 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:02:32 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	find_position(t_push **stacks)
{
	t_stack	*curr;
	int		position;

	position = 0;
	curr = (*stacks)->stack_a;
	while (curr)
	{
		curr->pos = position++;
		curr = curr->next;
	}
	position = 0;
	curr = (*stacks)->stack_b;
	while (curr)
	{
		curr->pos = position++;
		curr = curr->next;
	}
}

void	find_target_pos(t_push **stacks)
{
	t_stack	*curr_a;
	t_stack	*curr_b;

	curr_b = (*stacks)->stack_b;
	while (curr_b)
	{
		curr_b->target_pos = INT_MAX;
		curr_a = (*stacks)->stack_a;
		while (curr_a)
		{
			if (curr_b->index < curr_a->index
				&& (curr_a->index < curr_b->target_pos || !curr_b->target_pos))
			{
				curr_b->target_pos = curr_a->index;
			}
			curr_a = curr_a->next;
		}
		curr_b = curr_b->next;
	}
}

int	get_min_position(t_stack *stack_a)
{
	t_stack	*curr;
	int		min_index;
	int		min_pos;

	curr = stack_a;
	min_index = INT_MAX;
	min_pos = curr->pos;
	while (curr)
	{
		if (curr->index < min_index)
		{
			min_index = curr->index;
			min_pos = curr->pos;
		}
		curr = curr->next;
	}
	return (min_pos);
}
