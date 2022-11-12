/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:46:01 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/12 14:50:06 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

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
	set_index_to_list(&stack_a);
	if (stack_size == 2)
		sort_2(&stack_a);
	else if (stack_size == 3)
		sort_3(&stack_a);
	else if (stack_size == 4)
		sort_4(&stack_a, &stack_b);
	else if (stack_size == 5)
		sort_5(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
	// system("leaks push_swap");
	return (0);
}
