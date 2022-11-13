/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:30:11 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/13 15:32:03 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	exit_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	exit_error_free_stacks(t_node **stack_a, t_node **stack_b)
{
	ft_printf("Error\n");
	free_stacks(stack_a, stack_b);
	exit(EXIT_FAILURE);
}
