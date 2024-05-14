/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:39:48 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:03:20 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	update_rrr(t_push **stacks, int a, int b)
{
	t_stack	*curr;

	curr = (*stacks)->stack_a;
	while (curr && curr->index != a)
		curr = curr->next;
	curr->cost_a++;
	curr = (*stacks)->stack_b;
	while (curr && curr->index != b)
		curr = curr->next;
	curr->cost_b++;
	rrr(&(*stacks)->stack_a, &(*stacks)->stack_b);
}

void	update_rr(t_push **stacks, int a, int b)
{
	t_stack	*curr;

	curr = (*stacks)->stack_a;
	while (curr && curr->index != a)
		curr = curr->next;
	curr->cost_a--;
	curr = (*stacks)->stack_b;
	while (curr && curr->index != b)
		curr = curr->next;
	curr->cost_b--;
	rr(&(*stacks)->stack_a, &(*stacks)->stack_b);
}
