/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:11:22 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/26 09:37:02 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_stack_ordered(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_smallest_idx(t_node **stack)
{
	int		i;
	int		smallest;
	int		smallest_index;
	t_node	*cpy;

	cpy = *stack;
	smallest = cpy->value;
	smallest_index = 0;
	i = 0;
	while (cpy->next)
	{
		if (cpy->next->value < smallest)
		{
			smallest = cpy->next->value;
			smallest_index = i + 1;
		}
		cpy = cpy->next;
		i++;
	}
	return (smallest_index);
}
