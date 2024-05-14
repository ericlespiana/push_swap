/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotatate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:46:28 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:00:42 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static	void	reverse_rotate(t_stack **lst)
{
	t_stack	*last;
	t_stack	*second;
	t_stack	*penult;

	second = (*lst)->next;
	last = last_node(*lst);
	penult = penult_node(*lst);
	penult -> next = NULL;
	last -> next = *lst;
	*lst = last;
}

void	rra(t_stack **stack_a)
{
	if (!(*stack_a) || (*stack_a)->next == NULL)
		return ;
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	if (!(*stack_b) || (*stack_b)->next == NULL)
		return ;
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
