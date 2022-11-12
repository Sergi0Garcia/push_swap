/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:20:11 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/12 17:28:00 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * This func optimizes de next instruction to create initial piles
 * if actual idx is smaller than middle point we send it to stack_b
 * else we check if it is best to rotate stack_a or reverse rotate
 * @param stack_a
 * @param stack_b
 * @param mp
 */
void	init_dispersion(t_node **stack_a, t_node **stack_b, int mp)
{
	if ((*stack_a)->index < mp)
		push_b(stack_a, stack_b);
	else
	{
		if (ft_last_node(*stack_a)->index < mp)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}

/**
 * Func to start the midd point algorithm from stack_a to stack_b
 * We send recursively half the nums greater than middle point
 * Repeat the process until we are left with 2 or 1 numbers in stack_a
 * @param stack_a
 * @param stack_b
 * @return int
 */
int	init_piles(t_node **stack_a, t_node **stack_b)
{
	int		middle_point;
	int		minimum_idx;
	int		iterations;
	int		max_len;

	iterations = 0;
	while (ft_lst_size(*stack_a) >= 3)
	{
		max_len = ft_lst_size(*stack_a);
		middle_point = get_middle_point_index(stack_a, max_len);
		minimum_idx = get_minimum_index_from_pile(stack_a, max_len);
		while (ft_lst_size(*stack_a) > (max_len - (middle_point - minimum_idx)))
			init_dispersion(stack_a, stack_b, middle_point);
		iterations++;
	}
	sort_2(stack_a);
	return (iterations);
}
