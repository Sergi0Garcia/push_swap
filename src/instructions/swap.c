/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:01:14 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/19 13:38:21 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_a(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_ab(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
