/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:16:00 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/19 13:39:33 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate_a(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
