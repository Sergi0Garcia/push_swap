/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:11:22 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/26 12:39:04 by segarcia         ###   ########.fr       */
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

int find_smallest_number_no_idx(t_node *stack)
{
	int		smallest;
	t_node	*tmp;
	t_node	*head;

	head = stack;
	tmp = stack;
	while (tmp && tmp->index != 0)
		tmp = tmp->next;
	smallest = tmp->value;
	tmp = head;
	while (tmp->next)
	{
		if (tmp->next->index == 0 && tmp->next->value < smallest)
			smallest = tmp->next->value;
		tmp = tmp->next;
	}
	return (smallest);
}

void	set_index_to_list(t_node **stack_a)
{
	t_node	*tmp;
	int		idx;
	int		list_size;
	int		smallest;

	tmp = *stack_a;
	list_size = ft_lst_size(*stack_a);
	idx = 1;
	while (idx <= list_size)
	{
		smallest = find_smallest_number_no_idx(*stack_a);
		while (tmp)
		{
			if (tmp->value == smallest)
				tmp->index = idx;
			tmp = tmp->next;
		}
		idx++;
		tmp = *stack_a;
	}
}
