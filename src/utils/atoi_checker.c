/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:32:33 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/26 09:08:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	check_max(long long int num)
{
	if (num < 0 && num < INT_MIN)
		exit_error();
	if (num > 0 && num > INT_MAX)
		exit_error();
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

int	ft_atoi_checker(const char *str)
{
	long long int	res;
	int				sign;
	int				i;

	i = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign_validation(str[i], &i, &sign);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_error();
		res = (res * 10) + (str[i] - '0');
		check_max(res * sign);
		i++;
	}
	return ((int)res * sign);
}
