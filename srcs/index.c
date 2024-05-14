/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:01:44 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 07:51:43 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	calculate_sum_index(t_stack *stack);

void	put_index(t_push **stacks)
{
	t_stack	*curr;
	t_stack	*runner;
	int		index;

	curr = (*stacks)->stack_a;
	while (curr)
	{
		index = 1;
		runner = (*stacks)->stack_a;
		while (runner)
		{
			if (runner->data < curr->data)
				index++;
			runner = runner->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

void	media_and_push(t_push **stacks)
{
	t_stack	*curr;
	int		media;
	int		size;
	int		result;

	curr = (*stacks)->stack_a;
	size = lst_size((*stacks)->stack_a);
	while (size > 3)
	{
		size = lst_size((*stacks)->stack_a);
		if (size == 3)
			break ;
		result = calculate_sum_index((*stacks)->stack_a);
		media = result / size;
		curr = (*stacks)->stack_a;
		if (curr->index <= media)
			pb(&(*stacks)->stack_a, &(*stacks)->stack_b);
		else
			ra(&(*stacks)->stack_a);
	}
}

static int	calculate_sum_index(t_stack *stack)
{
	int	result;

	result = 0;
	while (stack)
	{
		result += stack->index;
		stack = stack->next;
	}
	return (result);
}
