/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:45:51 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:02:47 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_ordered(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_highest(t_stack *stack)
{
	t_stack	*curr;
	int		max;

	curr = stack;
	max = curr->data;
	while (curr)
	{
		if (curr->data > max)
			max = curr->data;
		curr = curr->next;
	}
	return (max);
}
