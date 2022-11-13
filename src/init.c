/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:24:07 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/13 15:46:44 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_double_nbr(t_node *stack, int nbr)
{
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	save_into_stack(t_node **stack, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = ft_new_node(value);
	if (!new)
		return (-1);
	if (*stack == 0)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}

void	free_parsing_exit(char ***split, t_node **stack_a, int i)
{
	char	**split_x;

	split_x = *split;
	while (split_x[i])
	{
		free(split_x[i]);
		i++;
	}
	free(split_x);
	exit_error_free_stacks(stack_a, NULL);
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
			exit_error_free_stacks(stack_a, NULL);
		j = 0;
		while (split[j])
		{
			nbr = ft_atoi_checker(&split, stack_a, j);
			if (is_double_nbr(*stack_a, nbr)
				|| save_into_stack(stack_a, nbr) == -1)
				free_parsing_exit(&split, stack_a, j);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
}

void	free_stacks(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (stack_a)
	{
		while ((*stack_a) != NULL)
		{
			tmp = *stack_a;
			*stack_a = (*stack_a)->next;
			free(tmp);
		}
		*stack_a = NULL;
	}
	if (stack_b)
	{
		while ((*stack_b) != NULL)
		{
			tmp = *stack_b;
			*stack_b = (*stack_b)->next;
			free(tmp);
		}
		*stack_b = NULL;
	}
}
