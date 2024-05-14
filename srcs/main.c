/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:23:20 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:02:41 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char *argv[])
{
	t_push	*stacks;

	ft_parse_arguments(argc, argv);
	init_list(&stacks);
	init_stack(&stacks->stack_a);
	stacks->stack_a = init_stack_a(argc, argv);
	push_swap(&stacks);
	free_list(stacks->stack_a);
	return (0);
}
