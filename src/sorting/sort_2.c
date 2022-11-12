/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:05:21 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/12 19:40:47 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Func to sort 2 numbers
 * Manually checking all combinations for performance
 * @param stack_a
 */
void	sort_2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}
