/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:46:28 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:00:46 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static	void	rotate(t_stack **lst)
{
	t_stack	*last;
	t_stack	*new_head;

	new_head = (*lst)->next;
	last = last_node(*lst);
	last->next = *lst;
	(*lst)->next = NULL;
	*lst = new_head;
}

void	ra(t_stack **stack_a)
{
	if (!(*stack_a) || (*stack_a)->next == NULL)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	if (!(*stack_b) || (*stack_b)->next == NULL)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
