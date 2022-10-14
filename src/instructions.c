/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:21:00 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/14 13:06:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_a(t_node **stack)
{
	t_node	*list;
	t_node	*tmp;

	list = *stack;
	if (list && list->next)
	{
		tmp = list;
		list = list->next;
		list->next = tmp;
	}
	*stack = list;
}