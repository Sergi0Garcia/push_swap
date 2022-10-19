/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:13:47 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/19 13:39:02 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_a(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
