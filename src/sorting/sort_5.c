/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:24:38 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/12 15:25:32 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	handle_index_1(t_node **stack_a, t_node **stack_b)
{
	swap_a(stack_a);
	push_b(stack_a, stack_b);
}

static void	handle_index_2(t_node **stack_a, t_node **stack_b)
{
	rotate_a(stack_a);
	rotate_a(stack_a);
	push_b(stack_a, stack_b);
}

static void	handle_index_3(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
}

static void	handle_index_4(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	smallest_idx;

	smallest_idx = find_smallest_idx(stack_a);
	if (smallest_idx == 0)
		push_b(stack_a, stack_b);
	else if (smallest_idx == 1)
		handle_index_1(stack_a, stack_b);
	else if (smallest_idx == 2)
		handle_index_2(stack_a, stack_b);
	else if (smallest_idx == 3)
		handle_index_3(stack_a, stack_b);
	else if (smallest_idx == 4)
		handle_index_4(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
