/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:05:27 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/19 13:39:00 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
