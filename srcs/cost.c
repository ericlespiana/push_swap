/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:17:05 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:02:10 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	calc_cost_a(t_stack *stack_a);
static void	calc_cost_b(t_stack *stack_b);

void	calculate_costs(t_push **stacks)
{
	calc_cost_a((*stacks)->stack_a);
	calc_cost_b((*stacks)->stack_b);
}

static void	calc_cost_a(t_stack *stack_a)
{
	t_stack	*curr;
	int		media;
	int		size;

	size = lst_size(stack_a);
	media = (size + 1) / 2;
	curr = stack_a;
	while (curr)
	{
		if (curr->pos <= media)
			curr->cost_a = curr->pos;
		else
			curr->cost_a = (size - curr->pos) * -1;
		curr = curr->next;
	}
}

static void	calc_cost_b(t_stack *stack_b)
{
	t_stack	*curr;
	int		media;
	int		size;

	size = lst_size(stack_b);
	media = (size + 1) / 2;
	curr = stack_b;
	while (curr)
	{
		if (curr->pos <= media)
			curr->cost_b = curr->pos;
		else
			curr->cost_b = (size - curr->pos) * -1;
		curr = curr->next;
	}
}

void	total_cost(t_push **stacks)
{
	t_stack	*curr_a;
	t_stack	*curr_b;

	curr_a = (*stacks)->stack_a;
	while (curr_a)
	{
		curr_b = (*stacks)->stack_b;
		while (curr_b)
		{
			if (curr_b->target_pos == curr_a->index)
				curr_b->cost = get_abs(curr_a->cost_a, curr_b->cost_b);
			curr_b = curr_b->next;
		}
		curr_a = curr_a->next;
	}
}

int	find_cheaper(t_stack *stack_b)
{
	t_stack	*curr;
	int		cheapier;

	curr = stack_b;
	cheapier = curr->cost;
	while (curr)
	{
		if (cheapier > curr->cost)
			cheapier = curr->cost;
		curr = curr->next;
	}
	return (cheapier);
}
