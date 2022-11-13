/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:32:33 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/13 17:46:12 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	check_max(long long int num)
{
	if (num < 0 && num < INT_MIN)
		return (1);
	if (num > 0 && num > INT_MAX)
		return (1);
	return (0);
}

static void	sign_validation(char num, int *i, int *sign)
{
	*sign = 1;
	if (num == '-' || num == '+')
	{
		if (num == '-')
			*sign = -1;
		*i = *i + 1;
	}
}

/**
 * Atoi checker
 * We check that every number is valid
 * Handling exceptions for INT_MIN and INT_MAX
 * If there is an error we free everyhing from parsing input
 * @param split
 * @param stack_a
 * @param j
 * @return int
 */
int	ft_atoi_checker(char ***split, t_node **stack_a, int j)
{
	long long int	res;
	int				sign;
	int				i;
	char			**split_x;
	char			*str;

	i = 0;
	res = 0;
	split_x = *split;
	str = split_x[j];
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign_validation(str[i], &i, &sign);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			free_parsing_exit(split, stack_a, j);
		res = (res * 10) + (str[i] - '0');
		if (check_max(res * sign))
			free_parsing_exit(split, stack_a, j);
		i++;
	}
	return ((int)res * sign);
}
