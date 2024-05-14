/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:32:46 by bda-mota          #+#    #+#             */
/*   Updated: 2024/05/14 03:18:52 by erpiana          ###   ########.fr       */
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
	(*stacks)->max_value = 0;
	(*stacks)->media = 0;
}

t_stack	*init_stack_a(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	t_stack	*node;
	int		i;

	i = 1;
	stack_a = new_node(ft_atoi(argv[i]));
	tmp = stack_a;
	while (++i < argc)
	{
		node = new_node(ft_atoi(argv[i]));
		tmp -> next = node;
		tmp = tmp->next;
	}
	return (stack_a);
}
