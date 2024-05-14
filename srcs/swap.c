/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:46:28 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:00:50 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static	void	swap(t_stack **lst)
{
	t_stack	*second;
	t_stack	*third;

	second = (*lst)->next;
	third = (*lst)->next->next;
	(*lst)->next = third;
	second->next = *lst;
	*lst = second;
}

void	sa(t_stack **stack_a)
{
	if (!(*stack_a) || (*stack_a)->next == NULL)
		return ;
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	if (!(*stack_b) || (*stack_b)->next == NULL)
		return ;
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
