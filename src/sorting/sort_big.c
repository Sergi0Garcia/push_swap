/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/31 13:58:29 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int get_minimum_index_from_pile(t_node **stack, int pile_len)
{
	t_node *tmp;
	int smallest_idx;
	int i;

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

int	get_middle_point_index(t_node **stack, int pile_len)
{
	int smallest_idx;
	int	middle_point;

	smallest_idx = get_minimum_index_from_pile(stack, pile_len);
	middle_point = smallest_idx + (pile_len / 2);
	return (middle_point);
}

static int	init_piles(t_node **stack_a, t_node **stack_b)
{
	t_node	*last;
	int middle_point;
	int minimum_idx;
	int iterations;
	int max_len;

	iterations = 0;
	while (ft_lst_size(*stack_a) >= 3 || !is_stack_ordered(*stack_a))
	{
		max_len = ft_lst_size(*stack_a);
		middle_point = get_middle_point_index(stack_a, max_len);
		minimum_idx = get_minimum_index_from_pile(stack_a, max_len);
		while (ft_lst_size(*stack_a) > (max_len - (middle_point - minimum_idx)))
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
		iterations++;
	}
	if (ft_lst_size(*stack_a) == 2)
		sort_2(stack_a);
	return (iterations);
}

static int get_pile_len(int max_size, int max_piles, int iterations)
{
	int i;
	int res;
	int start;

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

static int	init_piles_b(t_node **stack_a, t_node **stack_b, int max_len, int is_even)
{
	int middle_point;
	int minimum_idx;
	int iterations;
	int pushs;
	int rotations;
	int total_count;
	int total_count_cpy;

	iterations = 0;
	pushs = 0;
	rotations = 0;
	total_count = max_len;
	while (total_count >= 3)
	{
		total_count_cpy = total_count;
		if (total_count % 2 == 0)
			is_even = 1;
		else
			is_even = 0;
		middle_point = get_middle_point_index(stack_b, total_count);
		minimum_idx = get_minimum_index_from_pile(stack_b, total_count);
		while ((pushs + rotations) < (total_count_cpy))
		{
			if ((*stack_b)->index > (middle_point - is_even))
			{
				push_a(stack_a, stack_b);
				total_count--;
				pushs++;
			}
			else
			{
				rotate_b(stack_b);
				rotations++;
			}
		}
		while (rotations > 0)
		{
			reverse_rotate_b(stack_b);
			rotations--;
		}
		iterations++;
		pushs = 0;
	}
	if (ft_lst_size(*stack_b) > 1)
		if ((*stack_b)->index < (*stack_b)->next->index)
			swap_b(stack_b);
	return (iterations);
}

static int	init_piles_a(t_node **stack_a, t_node **stack_b, int max_len)
{
	int middle_point;
	int minimum_idx;
	int iterations;
	int pushs;
	int rotations;
	int total_count;
	int total_count_copy;

	iterations = 0;
	pushs = 0;
	rotations = 0;
	total_count = max_len;
	while (total_count >= 3)
	{
		total_count_copy = total_count;
		middle_point = get_middle_point_index(stack_a, total_count);
		minimum_idx = get_minimum_index_from_pile(stack_a, total_count);
		while ((pushs + rotations) < (total_count_copy))
		{
			if ((*stack_a)->index < middle_point)
			{
				push_b(stack_a, stack_b);
				total_count--;
				pushs++;
			}
			else
			{
				rotate_a(stack_a);
				rotations++;
			}
		}
		while (rotations > 0)
		{
			reverse_rotate_a(stack_a);
			rotations--;
		}
		iterations++;
		pushs = 0;
	}
	if (ft_lst_size(*stack_a) > 1)
		if ((*stack_a)->index > (*stack_a)->next->index)
			swap_a(stack_a);
	return (iterations);
}

static int is_3_sorted_descending(t_node **stack, int len)
{
	t_node *tmp;
	int 	i;

	i = 0;
	tmp = *stack;
	while (tmp && tmp->next && i < len)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

static int is_3_sorted_ascending(t_node **stack, int len)
{
	t_node *tmp;
	int 	i;

	i = 0;
	tmp = *stack;
	while (tmp && tmp->next && i < len)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

static void middle_point_b(t_node **stack_a, t_node **stack_b, int pile_len)
{
	int number_of_piles_in_a;
	int iterations;
	int is_even;

	// print_ab(*stack_a, *stack_b);
	iterations = 0;
	is_even = 0;
	if (pile_len % 2 == 0)
		is_even = 1;
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
		if (is_3_sorted_descending(stack_b, pile_len))
		{
			while (pile_len > 0)
			{
				push_a(stack_a, stack_b);
				pile_len--;
			}
			return ;
		}
		number_of_piles_in_a = init_piles_b(stack_a, stack_b, pile_len, is_even);
		while (iterations < number_of_piles_in_a)
		{
			// print_ab(*stack_a, *stack_b);
			// START OF INNEER LOOOOP
			// ------------
			// middle_point_a(stack_a, stack_b, get_pile_len(pile_len, number_of_piles_in_a, iterations));
			int pile_len_x;
			int number_of_piles_in_a_x;
			int iterations_x;
			iterations_x = 0;
			pile_len_x =  get_pile_len(pile_len, number_of_piles_in_a, iterations);
			if (pile_len_x == 1 )
				push_b(stack_a, stack_b);
			else if (pile_len_x == 2)
			{
				if ((*stack_a)->index > (*stack_a)->next->index)
					swap_a(stack_a);
				push_b(stack_a, stack_b);
				push_b(stack_a, stack_b);
			}
			else
			{
				if (pile_len == 3 && (is_3_sorted_ascending(stack_a, pile_len)))
				{
					while (pile_len > 0)
					{
						push_b(stack_a, stack_b);
						pile_len--;
					}
					return ;
				}
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
			// END OF INNEER LOOOOP
			// ------------
			iterations++;
		}
		while (pile_len > 0)
		{
			push_a(stack_a, stack_b);
			pile_len--;
		}
	}
}

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
