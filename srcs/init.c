/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:32:46 by bda-mota          #+#    #+#             */
/*   Updated: 2024/05/14 02:00:17 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	init_list(t_push **stacks)
{
	*stacks = (t_push *)malloc(sizeof(t_push));
	if (*stacks == NULL)
		exit(1);
	(*stacks)->stack_a = NULL;
	(*stacks)->stack_b = NULL;
}

void	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!(*stack))
		return ;
	(*stack)->data = 0;
	(*stack)->index = 0;
	(*stack)->pos = 0;
	(*stack)->target_pos = 0;
	(*stack)->cost_a = 0;
	(*stack)->cost_b = 0;
	(*stack)->next = NULL;
}
