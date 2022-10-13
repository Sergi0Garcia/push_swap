/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:46:01 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/13 15:00:51 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	exit_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

static void	sign_validation(char num, int *i, int *sign)
{
	*sign = 1;
	if (num == '-' || num == '+')
	{
		if (num == '-')
			*sign = -1;
		*i = *i + 1;
	}
}

static void	check_max(long long int num)
{
	if (num < 0 && num < INT_MIN)
		exit_error();
	if (num > 0 && num > INT_MAX)
		exit_error();
}

static int	ft_atoi_checker(const char *str)
{
	long long int	res;
	int				sign;
	int				i;

	i = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign_validation(str[i], &i, &sign);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_error();
		res = (res * 10) + (str[i] - '0');
		check_max(res * sign);
		i++;
	}
	return ((int)res * sign);
}

t_node	*save_into_stack(t_node *stack, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = ft_new_node(value);
	if (!new)
		ft_printf("Free all nodes");
	if (stack == NULL)
		stack = new;
	else
	{
		tmp = stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (stack);
}

static void is_double_nbr(t_node *stack, int nbr)
{

	if (!stack)
		return ;
	while(stack)
	{
		if (stack->value == nbr)
			exit_error();
		stack = stack->next;
	}
}

static t_node	*parse_input(char **argv, t_node *stack_a)
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
			is_double_nbr(stack_a, nbr);
			stack_a = save_into_stack(stack_a, nbr);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (stack_a);
}

static void	stack_init(t_node **stack_1, t_node **stack_2)
{
	*stack_1 = NULL;
	*stack_2 = NULL;
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_init(&stack_a, &stack_b);
	stack_a = parse_input(argv, stack_a);
	ft_print_list(stack_a);
	// system("leaks push_swap");
	/** Loop and check for repeated numbers */
	return (0);
}
