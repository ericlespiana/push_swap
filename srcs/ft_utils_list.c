/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:05:46 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 03:27:13 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	if (!node)
		return (NULL);
	node -> data = data;
	node -> index = 0;
	node -> pos = 0;
	node -> target_pos = 0;
	node -> cost_a = 0;
	node -> cost_b = 0;
	node -> cost = 0;
	node -> next = NULL;
	return (node);
}
