/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:21:00 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/13 15:12:31 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Swap movement
 * Swap first value with second one in stack
 * If there is no second one return nothing
 * @param stack
 */
void	swap(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

/**
 * Push movement
 * Push first element from origin to destination
 * Element is placed in top of destination
 * @param origin
 * @param destination
 */
void	push(t_node	**origin, t_node **destination)
{
	t_node	*tmp;

	if (origin == NULL || *origin == NULL)
		return ;
	tmp = *origin;
	*origin = (*origin)->next;
	tmp->next = *destination;
	*destination = tmp;
}

/**
 * Rotate movement
 * Swap first element to last place in stack
 * @param stack
 */
void	rotate(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
}

/**
 * Reverse rotate movement
 * Swap last element in stack to top
 * @param stack
 */
void	reverse_rotate(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
}
