/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_init_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:26:51 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/12 19:06:26 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Func to move the nodes back up
 * @param stack_b
 * @param iterations
 */
static void	piles_correction_b(t_node **stack_b, int iterations)
{
	while (iterations > 0)
	{
		reverse_rotate_b(stack_b);
		iterations--;
	}
}

/**
 * Func that handles all the logic for creating new piles from a set
 * If the index value is < middle_point we push it to the other stack
 * If not, we rotate and continue with next number
 * Important to keep track of rotations so we can correct the remaining set
 * @param stack_a
 * @param stack_b
 * @param max_len
 * @param mp
 * @return int
 */
int	piles_dispersion_b(t_node **stack_a, t_node **stack_b, int max_len, int mp)
{
	int	nums_pushed;
	int	movements;
	int	strict_finish;

	movements = 0;
	nums_pushed = 0;
	strict_finish = 0;
	while (movements < max_len && !strict_finish)
	{
		if ((*stack_b)->index > mp)
		{
			push_a(stack_a, stack_b);
			nums_pushed++;
			movements++;
		}
		else if (movements + 1 == max_len)
			strict_finish = 1;
		else
		{
			rotate_b(stack_b);
			movements++;
		}
	}
	piles_correction_b(stack_b, movements - nums_pushed);
	return (nums_pushed);
}

/**
 * Function to create piles from initial set using midd point algorithm
 * We create new sets of smaller chunks from a children set from stack_b
 * @param stack_a
 * @param stack_b
 * @param max_len
 * @return int
 */
int	init_piles_b(t_node **stack_a, t_node **stack_b, int max_len)
{
	int	iterations;
	int	middle_point;

	iterations = 0;
	middle_point = 0;
	while (max_len >= 3 && ft_lst_size(*stack_b) >= 3)
	{
		middle_point = get_middle_point_index(stack_b, max_len);
		if (max_len % 2 == 0)
			middle_point = middle_point - 1;
		max_len -= piles_dispersion_b(stack_a, stack_b, max_len, middle_point);
		iterations++;
	}
	if (ft_lst_size(*stack_b) > 1
		&& (*stack_b)->index < (*stack_b)->next->index)
		swap_b(stack_b);
	return (iterations);
}
