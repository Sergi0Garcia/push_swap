/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/26 13:38:33 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int max_len;
	int middle_point;
	t_node *last;

	max_len = ft_lst_size(*stack_a);
	middle_point = (max_len / 2) + 1;
	while (ft_lst_size(*stack_a) > (max_len - middle_point + 1))
	{
		if ((*stack_a)->index < middle_point)
			push_b(stack_a, stack_b);
		else
		{
			last = ft_last_node(*stack_a);
			if (last->index < middle_point)
				reverse_rotate_a(stack_a);
			else
				rotate_a(stack_a);
		}
	}
	sort_3(stack_a);
	max_len = ft_lst_size(*stack_b);
	middle_point = (max_len / 2) + 1;
	while (ft_lst_size(*stack_b) > (max_len - middle_point + 1))
	{
		if ((*stack_b)->index > middle_point)
			push_a(stack_a, stack_b);
		else
		{
			last = ft_last_node(*stack_b);
			if (last->index > middle_point)
				reverse_rotate_b(stack_b);
			else
				rotate_a(stack_b);
		}
	}
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}