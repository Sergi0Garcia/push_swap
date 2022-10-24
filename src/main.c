/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:46:01 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/24 14:49:23 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

// static void	print_ab(t_node *stack_a, t_node *stack_b)
// {
// 	ft_printf("---------\n");
// 	ft_printf("--- a ---\n");
// 	ft_print_list(stack_a);
// 	ft_printf("--- b ---\n");
// 	ft_print_list(stack_b);
// 	ft_printf("---------\n");
// }

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

static void sort_2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}

static void sort_3(t_node **stack_a)
{
	int		first;
	int		second;
	int		third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && third > first)
		swap_a(stack_a);
	else if (first < second && second > third && third < first)
		reverse_rotate_a(stack_a);
	else if (first > second && second < third && third < first)
		rotate_a(stack_a);
	else if (first < second && second > third && third > first)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (first > second && second > third && third < first)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
}

static void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int i;
	t_node *last;

	last = ft_last_node(*stack_a);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	if ((*stack_b)->value > (*stack_b)->next->value)
		swap_b(stack_b);
	sort_3(stack_a);
	i = 0;
	last = ft_last_node(*stack_a);
	if ((*stack_b)->value > last->value)
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
	else
	{
		while ((*stack_b)->value > (*stack_a)->value)
		{
			rotate_a(stack_a);
			i++;
		}
		push_a(stack_a, stack_b);
		while (i > 0)
		{
			reverse_rotate_a(stack_a);
			i--;
		}
	}
	i = 0;
	last = ft_last_node(*stack_a);
	if ((*stack_b)->value > last->value)
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
	else
	{
		while ((*stack_b)->value > (*stack_a)->value)
		{
			rotate_a(stack_a);
			i++;
		}
		push_a(stack_a, stack_b);
		while (i > 0)
		{
			reverse_rotate_a(stack_a);
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		stack_size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	parse_input(argv, &stack_a);
	if (is_stack_ordered(stack_a))
		exit(EXIT_SUCCESS);
	stack_size = ft_lst_size(stack_a);
	if (stack_size == 2)
		sort_2(&stack_a);
	else if (stack_size == 3)
		sort_3(&stack_a);
	else if (stack_size <= 5)
		sort_5(&stack_a, &stack_b);
	// system("leaks push_swap");
	return (0);
}
