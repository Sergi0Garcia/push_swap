/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:24:07 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/19 09:58:20 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void is_double_nbr(t_node *stack, int nbr)
{
	while(stack)
	{
		if (stack->value == nbr)
			exit_error();
		stack = stack->next;
	}
}

void	save_into_stack(t_node **stack, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = ft_new_node(value);
	if (!new)
		ft_printf("Free all nodes");
	if (*stack == 0)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	parse_input(char **argv, t_node **stack_a)
{
	char	**split;
	int		nbr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			exit_error();
		j = 0;
		while (split[j])
		{
			nbr = ft_atoi_checker(split[j]);
			is_double_nbr(*stack_a, nbr);
			save_into_stack(*stack_a, nbr);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
}