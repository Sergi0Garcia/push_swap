/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/31 12:04:19 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	print_ab(t_node *stack_a, t_node *stack_b)
{
	ft_printf("---------\n");
	ft_printf("--- a ---\n");
	ft_print_list(stack_a);
	ft_printf("--- b ---\n");
	ft_print_list(stack_b);
	ft_printf("---------\n");
}

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
	while (ft_lst_size(*stack_a) >= 3)
	{
		// ft_printf("Iteration: %i\n", iterations);
		max_len = ft_lst_size(*stack_a);
		middle_point = get_middle_point_index(stack_a, max_len);
		minimum_idx = get_minimum_index_from_pile(stack_a, max_len);
		// ft_printf("max_len: %i\n", max_len);
		// ft_printf("middle_point: %i\n", middle_point);
		// ft_printf("minimum_idx: %i\n", minimum_idx);
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
	// print_ab(*stack_a, *stack_b);
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
		// ft_printf("middle_point init_piles_b: %i\n", middle_point);
		// ft_printf("minimum_idx init_piles_b: %i\n", minimum_idx);
		while ((pushs + rotations) < (total_count_cpy))
		{
			// ft_printf("pushs + rotations: %i\n", pushs + rotations);
			// ft_printf("total_count: %i\n", total_count_cpy);
			// ft_printf("here\n");
			// exit(0);
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
		// ft_printf("pushs: %i\n", pushs);
		// ft_printf("rotations: %i\n", rotations);
		// ft_printf("max_len: %i\n", max_len);
		// ft_printf("total_count: %i\n", total_count);
		// print_ab(*stack_a, *stack_b);
	}
	// ft_printf("END OF init_piles_b\n");
	if (ft_lst_size(*stack_b) > 1)
		if ((*stack_b)->index < (*stack_b)->next->index)
			swap_b(stack_b);
	// print_ab(*stack_a, *stack_b);
	// ft_printf("iterations init piles b: %i\n", iterations);
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
		// ft_printf("middle_point init_piles_a: %i\n", middle_point);
		// ft_printf("minimum_idx init_piles_a: %i\n", minimum_idx);
		while ((pushs + rotations) < (total_count_copy))
		{
			// ft_printf("here\n");
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
		// ft_printf("pushs: %i\n", pushs);
		// ft_printf("rotations: %i\n", rotations);
		// ft_printf("max_len: %i\n", max_len);
	}
	if (ft_lst_size(*stack_a) > 1)
		if ((*stack_a)->index > (*stack_a)->next->index)
			swap_a(stack_a);
	// print_ab(*stack_a, *stack_b);
	// ft_printf("iterations init piles b: %i\n", iterations);
	return (iterations);
}

static int is_3_sorted_descending(t_node **stack)
{
	int first;
	int second;
	int third;

	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;

	if (first > second && second > third && third < first)
		return (1);
	else
		return (0);
}

// static void middle_point_a(t_node **stack_a, t_node **stack_b, int pile_len)
// {
// 	// int number_of_piles_in_a;
// 	int iterations;

// 	// print_ab(*stack_a, *stack_b);
// 	iterations = 0;
// 	// ft_printf("individual pile len A: %i\n", pile_len);
// 	if (pile_len == 1)
// 		push_b(stack_a, stack_b);
// 	else if (pile_len == 2)
// 	{
// 		if ((*stack_a)->index > (*stack_a)->next->index)
// 			swap_a(stack_a);
// 		push_b(stack_a, stack_b);
// 		push_b(stack_a, stack_b);
// 		// ft_printf("------ x ------");
// 		// print_ab(*stack_a, *stack_b);
// 	}
// 	else
// 	{
// 		printf("SIGKILLNXXX\n");
// 		return ;
// 		// number_of_piles_in_a = init_piles_a(stack_a, stack_b, pile_len);
// 		// ft_printf("number_of_piles_in_a: %i\n", number_of_piles_in_a);
// 		// return ;
// 		// while (iterations < number_of_piles_in_a)
// 		// {
// 		// 	// middle_point_b(stack_a, stack_b, get_pile_len(pile_len, number_of_piles_in_a, iterations, 0));
// 		// 	iterations++;
// 		// }
// 		// while (pile_len > 0)
// 		// {
// 		// 	push_b(stack_a, stack_b);
// 		// 	pile_len--;
// 		// }
// 	}
// }


static void middle_point_b(t_node **stack_a, t_node **stack_b, int pile_len)
{
	int number_of_piles_in_a;
	int iterations;
	int is_even;

	iterations = 0;
	is_even = 0;
	if (pile_len % 2 == 0)
		is_even = 1;
	// print_ab(*stack_a, *stack_b);
	// ft_printf("individual pile len in middle point b: %i\n", pile_len);
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
		if (pile_len == 3 && (is_3_sorted_descending(stack_b)))
		{
			push_a(stack_a, stack_b);
			push_a(stack_a, stack_b);
			push_a(stack_a, stack_b);
			return ;
		}
		// ft_printf("middle_point_b is_even: %i\n", is_even);
		number_of_piles_in_a = init_piles_b(stack_a, stack_b, pile_len, is_even);
		// ft_printf("number_of_piles_in_a: %i\n",  number_of_piles_in_a);
		// print_ab(*stack_a, *stack_b);
		while (iterations < number_of_piles_in_a)
		{
			// ft_printf("XX_pile_len: %i\n", pile_len);
			// ft_printf("XX_number_of_piles_in_a: %i\n", number_of_piles_in_a);
			// ft_printf("XX_iterations: %i\n", iterations);
			// print_ab(*stack_a, *stack_b);
			// middle_point_a(stack_a, stack_b, get_pile_len(pile_len, number_of_piles_in_a, iterations));
			int pile_len_x;
			int number_of_piles_in_a_x;
			int iterations_x;
			iterations_x = 0;
			// ft_printf("[xx] pile_len: %i\n", pile_len);
			// ft_printf("[xx] number_of_piles_in_a: %i\n", number_of_piles_in_a);
			// ft_printf("[xx] iterations: %i\n", iterations);
			pile_len_x =  get_pile_len(pile_len, number_of_piles_in_a, iterations);
		 	// ft_printf("pile_len_x: %i\n", pile_len_x);
			if (pile_len_x == 1)
				push_b(stack_a, stack_b);
			else if (pile_len_x == 2)
			{
				if ((*stack_a)->index > (*stack_a)->next->index)
					swap_a(stack_a);
				push_b(stack_a, stack_b);
				push_b(stack_a, stack_b);
				// ft_printf("------ x ------");
				// print_ab(*stack_a, *stack_b);
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
			// END OF INNEER LOOOOP
			// ------------
			iterations++;
		}
		// print_ab(*stack_a, *stack_b);
		while (pile_len > 0)
		{
			push_a(stack_a, stack_b);
			pile_len--;
		}
	}
	// print_ab(*stack_a, *stack_b);
}

void sort_big(t_node **stack_a, t_node **stack_b)
{
	int max_size;
	int number_of_piles;
	int iterations;

	iterations = 0;
	max_size = ft_lst_size(*stack_a);
	number_of_piles = init_piles(stack_a, stack_b);
	// print_ab(*stack_a, *stack_b);
	// ft_printf("Number of piles init: %i\n",  number_of_piles);
	// int i = 0;
	// while(i < number_of_piles)
	// {
	// 	ft_printf("Pile[%i]: %i\n", i, get_pile_len(max_size, number_of_piles, i));
	// 	i++;
	// }
	while (iterations < number_of_piles)
	{
		middle_point_b(stack_a, stack_b, get_pile_len(max_size, number_of_piles, iterations));
		iterations++;
	}
	print_ab(*stack_a, *stack_b);
}
