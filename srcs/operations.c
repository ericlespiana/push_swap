/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:22:02 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:02:38 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	moves(t_push **stacks, int target_pos, int pos_b);
static void	move_a(t_push **stacks, int pos);
static void	move_b(t_push **stacks, int pos);

void	find_op(t_push **stacks)
{
	t_stack	*curr;
	int		cheaper;

	cheaper = find_cheaper((*stacks)->stack_b);
	curr = (*stacks)->stack_b;
	while (curr)
	{
		if (curr->cost == cheaper)
		{
			moves(stacks, curr->target_pos, curr->pos);
			return ;
		}
		curr = curr->next;
	}
}

static void	moves(t_push **stacks, int target_pos, int pos_b)
{
	t_stack	*curr_a;
	t_stack	*curr_b;

	curr_a = (*stacks)->stack_a;
	curr_b = (*stacks)->stack_b;
	while (curr_a->index != target_pos)
		curr_a = curr_a->next;
	while (curr_b->pos != pos_b)
		curr_b = curr_b->next;
	while (curr_b != NULL)
	{
		if (curr_a->cost_a < 0 && curr_b->cost_b < 0)
			update_rrr(stacks, curr_a->index, curr_b->index);
		else if (curr_a->cost_a > 0 && curr_b->cost_b > 0)
			update_rr(stacks, curr_a->index, curr_b->index);
		move_a(stacks, target_pos);
		move_b(stacks, pos_b);
		if (curr_a->cost_a == 0 && curr_b->cost_b == 0)
			break ;
	}
	pa((&(*stacks)->stack_a), &((*stacks)->stack_b));
}

static void	move_a(t_push **stacks, int pos)
{
	t_stack	*curr;

	curr = (*stacks)->stack_a;
	while (curr)
	{
		if (curr->index == pos)
		{
			while (curr->cost_a != 0)
			{
				if (curr->cost_a < 0)
				{
					rra(&(*stacks)->stack_a);
					curr->cost_a++;
				}
				else if (curr->cost_a > 0)
				{
					ra(&(*stacks)->stack_a);
					curr->cost_a--;
				}
			}
			return ;
		}
		curr = curr->next;
	}
}

static void	move_b(t_push **stacks, int pos)
{
	t_stack	*curr;

	curr = (*stacks)->stack_b;
	while (curr)
	{
		if (curr->pos == pos)
		{
			while (curr->cost_b != 0)
			{
				if (curr->cost_b < 0)
				{
					rrb(&(*stacks)->stack_b);
					curr->cost_b++;
				}
				else if (curr->cost_b > 0)
				{
					rb(&(*stacks)->stack_b);
					curr->cost_b--;
				}
			}
			return ;
		}
		curr = curr->next;
	}
}
