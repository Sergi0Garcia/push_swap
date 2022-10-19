/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:46:01 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/19 09:56:07 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int is_stack_ordered(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	swap(t_node **stack)
{
	t_node	*node_1;
	t_node	*node_2;

	node_1 = *stack;
	node_2 = node_1->next;
	if (node_1 && node_2)
	{
		node_1->next = node_2->next;
		node_2->next = node_1;
	}
	*stack = node_2;
}

static void	push(t_node	**origin, t_node **destination)
{
	t_node	*o;
	t_node	*d;
	t_node	*tmp;

	o = *origin;
	d = *destination;

	if (!o)
		return ;
	tmp = o->next;
	o->next = d;
	d = o;
	o = tmp;
	*origin = o;
	*destination = d;
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
	swap(&stack_a);
	// save_into_stack(&stack_b, 8);
	// save_into_stack(&stack_b, 7);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	ft_printf("--- a ---\n");
	ft_print_list(stack_a);
	ft_printf("--- b ---\n");
	ft_print_list(stack_b);
	system("leaks push_swap");
	return (0);
}
