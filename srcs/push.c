/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:46:28 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:00:37 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;

	if (!(*stack_a))
		return ;
	tmp_a = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp_a -> next = *stack_b;
	*stack_b = tmp_a;
	ft_printf("pb\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;

	if (!(*stack_b))
		return ;
	tmp_b = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp_b -> next = *stack_a;
	*stack_a = tmp_b;
	ft_printf("pa\n");
}
