/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:46:01 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/19 13:42:06 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_stack_ordered(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	print_ab(t_node *stack_a, t_node *stack_b)
{
	ft_printf("--- a ---\n");
	ft_print_list(stack_a);
	ft_printf("--- b ---\n");
	ft_print_list(stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	parse_input(argv, &stack_a);
	if (is_stack_ordered(stack_a))
		exit(EXIT_SUCCESS);
	print_ab(stack_a, stack_b);
	ft_printf("--- Exec sa ---\n");
	swap(&stack_a);
	print_ab(stack_a, stack_b);
	ft_printf("--- Exec pb pb pb ---\n");
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	print_ab(stack_a, stack_b);
	ft_printf("--- Exec rr ---\n");
	rotate_ab(&stack_a, &stack_b);
	print_ab(stack_a, stack_b);
	ft_printf("--- Exec rrr ---\n");
	reverse_rotate_ab(&stack_a, &stack_b);
	print_ab(stack_a, stack_b);
	ft_printf("--- Exec sa ---\n");
	swap(&stack_a);
	print_ab(stack_a, stack_b);
	ft_printf("--- Exec pa pa pa ---\n");
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	print_ab(stack_a, stack_b);
	// system("leaks push_swap");
	return (0);
}
