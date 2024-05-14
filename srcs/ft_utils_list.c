/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:05:46 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:00:04 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

t_stack	*last_node(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

t_stack	*penult_node(t_stack *lst)
{
	t_stack	*penult;

	penult = NULL;
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		if (lst -> next -> next == NULL)
		{
			penult = lst;
			break ;
		}
		lst = lst -> next;
	}
	return (penult);
}

t_stack	*new_node(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->data = data;
	return (node);
}

void	free_list(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack -> next;
		free(stack);
		stack = tmp;
	}
}
