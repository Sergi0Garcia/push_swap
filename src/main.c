/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:46:01 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/13 11:48:15 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (num > 0 && num > INT_MAX)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
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
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		res = (res * 10) + (str[i] - '0');
		check_max(res * sign);
		i++;
	}
	return ((int)res * sign);
}

t_node	*save_into_stack(t_node *stack, int value)
{
	t_node	*new;
	t_node	*ptr;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		ft_printf("Malloc Error in Stack allocation");
		exit(EXIT_FAILURE);
	}
	new->value = value;
	new->next = NULL;
	if (stack == NULL)
		stack = new;
	else
	{
		ptr = stack;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	return (stack);
}

static t_node	*arg_validation(int argc, char **argv, t_node *stack_a)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc >= 2)
	{
		while (argv[i])
		{
			split = ft_split(argv[i], ' ');
			if (!split)
			{
				ft_printf("Error in ft_split function \n");
				exit(EXIT_FAILURE);
			}
			j = 0;
			while (split[j])
			{
				stack_a = save_into_stack(stack_a, ft_atoi_checker(split[j]));
				free(split[j]);
				j++;
			}
			free(split);
			i++;
		}
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = arg_validation(argc, argv, stack_a);
	ft_print_list(stack_a);
	ft_print_list(stack_b);
	system("leaks push_swap");
	/** Loop and check for repeated numbers */
	return (0);
}
