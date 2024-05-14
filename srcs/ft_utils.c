/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:05:46 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 02:00:10 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long int	ft_atol(const char *n)
{
	int			sign;
	int			i;
	long int	num;

	num = 0;
	i = 0;
	sign = 1;
	while ((n[i] >= 9 && n[i] <= 13) || n[i] == 32)
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			sign = -1;
		i++;
		if (n[i] == '\0')
			return (2147483648);
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		num = num * 10 + (n[i] - '0');
		i++;
	}
	if (n[i] == '\0')
		return (num * sign);
	return (2147483648);
}

void	ft_error(char *MSG)
{
	ft_putstr_fd(MSG, 2);
	exit(EXIT_FAILURE);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	lst_size(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst -> next;
		size++;
	}
	return (size);
}

int	get_abs(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}
