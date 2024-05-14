/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:05:46 by erpiana           #+#    #+#             */
/*   Updated: 2024/05/14 01:59:59 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	check_argv(char **argv);
static void	check_repeat(char **argv, int index);

void	ft_parse_arguments(int argc, char **argv)
{
	if (argc < MIN_ARGS)
		ft_error(NULL);
	check_argv(++argv);
}

static int	check_long(char *str)
{
	int	size;

	size = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (str[size] >= '0' && str[size] <= '9')
	{
		size++;
		if (size > 10)
			return (1);
	}
	return (0);
}

static void	check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX)
			ft_error(ERROR);
		if (check_long(argv[i]))
			ft_error(ERROR);
		if (ft_strcmp(argv[i], "") == 0)
			ft_error(ERROR);
		check_repeat(argv, i++);
	}
}

static void	check_repeat(char **argv, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (ft_strcmp(argv[i], argv[index]) == 0)
			ft_error(ERROR);
		i++;
	}
}
