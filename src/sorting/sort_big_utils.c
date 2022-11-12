/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:10:02 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/12 20:37:40 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Func to get the minimun idx of a pile
 * We reduce scope size fo stack with pile_len
 * We compare numbers idx and not with number for precision
 * @param stack
 * @param pile_len
 * @return int
 */
int	get_minimum_index_from_pile(t_node **stack, int pile_len)
{
	t_node	*tmp;
	int		smallest_idx;
	int		i;

	tmp = *stack;
	i = 0;
	smallest_idx = tmp->index;
	while (tmp->next && i < pile_len - 1)
	{
		if (tmp->next->index < smallest_idx)
			smallest_idx = tmp->next->index;
		tmp = tmp->next;
		i++;
	}
	return (smallest_idx);
}

/**
 * Func to get the idx value of the middle
 * Ej: 1 2 3 4 5
 * middle_point_idx = 3
 * @param stack
 * @param pile_len
 * @return int
 */
int	get_middle_point_index(t_node **stack, int pile_len)
{
	int	smallest_idx;
	int	middle_point;

	smallest_idx = get_minimum_index_from_pile(stack, pile_len);
	middle_point = smallest_idx + (pile_len / 2);
	return (middle_point);
}

/**
 * Function to validate if stack is strictly ordered
 * Strictly ordered defined as ordered with idx
 * We ordered the stack and gave each number the idx it corresponds
 * @param stack
 * @param len
 * @return int
 */
int	is_strict_sorted_ascending(t_node **stack, int len)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp && tmp->next && i < len)
	{
		if (tmp->index + 1 != tmp->next->index)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

/**
 * Fucn to get the length of a stack depending on actual iteration
 * We calculate each chunk size mathematically by dividing
 * Ex:
 * max_size = 10
 * Iteration[0] = 1
 * Iteration[1] = 2
 * Iteration[2] = 5
 * Remaining = 2 in stack
 * This means we sent 3 chunks to the other stack of sizes 1,2,5
 * @param max_size
 * @param max_piles
 * @param iterations
 * @return int
 */
int	pile_len(int max_size, int max_piles, int iterations)
{
	int	i;
	int	res;
	int	start;

	i = 0;
	res = max_size;
	start = max_size;
	while (i < (max_piles - iterations))
	{
		if (start != res)
			res++;
		if (start % 2 != 0)
		{
			start /= 2;
			start++;
		}
		else
			start /= 2;
		res /= 2;
		i++;
	}
	return (res);
}
