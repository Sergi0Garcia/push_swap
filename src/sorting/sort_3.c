/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:06:39 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/12 19:32:25 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Func to sort 3 numbers
 * Manually checking all combinations for performance
 * @param stack_a
 */
void	sort_3(t_node **stack_a)
{
	int		first;
	int		second;
	int		third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && third > first)
		swap_a(stack_a);
	else if (first < second && second > third && third < first)
		reverse_rotate_a(stack_a);
	else if (first > second && second < third && third < first)
		rotate_a(stack_a);
	else if (first < second && second > third && third > first)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (first > second && second > third && third < first)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
}
