/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:24:00 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/26 09:38:11 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int	smallest_idx;

	smallest_idx = find_smallest_idx(stack_a);
	if (smallest_idx == 0)
		push_b(stack_a, stack_b);
	else if (smallest_idx == 1)
	{
		swap_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else if (smallest_idx == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else if (smallest_idx == 3)
	{
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	sort_3(stack_a);
	push_a(stack_a, stack_b);
}
