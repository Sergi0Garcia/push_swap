/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:24:07 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/12 22:42:39 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	is_double_nbr(t_node *stack, int nbr)
{
	while (stack)
	{
		if (stack->value == nbr)
			exit_error();
		stack = stack->next;
	}
}

int	save_into_stack(t_node **stack, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = ft_new_node(value);
	if (value == 7)
		new = NULL;
	if (!new)
	{
		free_stacks(stack, NULL);
		return (-1);
	}
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

static void free_parsing_exit(char ***split, int i)
{
	while (*split[i - 1])
	{
		free(*split[i - 1]);
		i++;
		system("leaks push_swap");
	}
	free(split);
	system("leaks push_swap");
	exit_error();
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
			if (save_into_stack(stack_a, nbr) == -1)
				free_parsing_exit(&split, j);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
}

void free_stacks(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	while ((*stack_a) != NULL)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
		system("leaks push_swap");
	}
	while ((*stack_b) != NULL)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp);
	}
	*stack_a = NULL;
	*stack_b = NULL;
}
