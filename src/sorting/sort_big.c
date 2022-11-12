/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/12 19:08:27 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void middle_point_b(t_node **stack_a, t_node **stack_b, int pile_len)
{
	int number_of_piles_in_a;
	int iterations;
	int opt;

	opt = 0;
	iterations = 0;

	if (pile_len == 1)
		push_a(stack_a, stack_b);
	else if (pile_len == 2)
	{
		if ((*stack_b)->index < (*stack_b)->next->index)
			swap_b(stack_b);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	else
	{
		number_of_piles_in_a = init_piles_b(stack_a, stack_b, pile_len);
		// printf("number_of_piles_in_a: %i\n", number_of_piles_in_a);
		while (iterations < number_of_piles_in_a)
		{
			// ------------
			// START OF INNEER LOOOOP
			// ------------
			int pile_len_x;
			int number_of_piles_in_a_x;
			int iterations_x;
			iterations_x = 0;
			pile_len_x =  get_pile_len(pile_len, number_of_piles_in_a, iterations);
			if (pile_len_x == 1)
			{
				if (is_strict_sorted_ascending(stack_a, ft_lst_size(*stack_a)))
					opt +=  pile_len_x;
				else
					push_b(stack_a, stack_b);
			}
			else if (pile_len_x == 2)
			{
				if (is_strict_sorted_ascending(stack_a, ft_lst_size(*stack_a)))
				{
					opt += pile_len_x;
				}
				else
				{
					if ((*stack_a)->index > (*stack_a)->next->index)
						swap_a(stack_a);
					push_b(stack_a, stack_b);
					push_b(stack_a, stack_b);
				}
			}
			else
			{
				number_of_piles_in_a_x = init_piles_a(stack_a, stack_b, pile_len_x);
				while (iterations_x < number_of_piles_in_a_x)
				{
					middle_point_b(stack_a, stack_b, get_pile_len(pile_len_x, number_of_piles_in_a_x, iterations_x));
					iterations_x++;
				}
				while (pile_len_x > 0)
				{
					push_b(stack_a, stack_b);
					pile_len_x--;
				}
			}
			// ------------
			// END OF INNEER LOOOOP
			// ------------
			iterations++;
		}
		while (pile_len - opt > 0)
		{
			push_a(stack_a, stack_b);
			pile_len--;
		}
	}
}

/**
 * Main func for big number sorting
 * Using middle point algorithm
 * @param stack_a
 * @param stack_b
 */
void sort_big(t_node **stack_a, t_node **stack_b)
{
	int max_size;
	int number_of_piles;
	int iterations;

	iterations = 0;
	max_size = ft_lst_size(*stack_a);
	number_of_piles = init_piles(stack_a, stack_b);
	while (iterations < number_of_piles)
	{
		middle_point_b(stack_a, stack_b, get_pile_len(max_size, number_of_piles, iterations));
		iterations++;
	}
}
