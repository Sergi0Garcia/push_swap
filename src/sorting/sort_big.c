/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/12 20:59:01 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	handle_piles_1_2_b(t_node **stack_a, t_node **stack_b, int pile_len)
{
	if (pile_len == 1)
		push_a(stack_a, stack_b);
	else if (pile_len == 2)
	{
		if ((*stack_b)->index < (*stack_b)->next->index)
			swap_b(stack_b);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}

void	x_handle_piles_1_2_a(t_node **stack_a, t_node **stack_b, int x_pile_len)
{
	if (x_pile_len == 1)
		push_b(stack_a, stack_b);
	else if (x_pile_len == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			swap_a(stack_a);
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
	}
}

void	correction_mp(t_node **stack_a, t_node **stack_b, int i, char act_stack)
{
	while (i > 0)
	{
		if (act_stack == 'a')
			push_b(stack_a, stack_b);
		if (act_stack == 'b')
			push_a(stack_a, stack_b);
		i--;
	}
}

static void	middle_point(t_node **stack_a, t_node **stack_b, int piles_len)
{
	t_mp_ctrl *mp_ctrl;
	t_mp_ctrl *x_mp_ctrl;
	// int	iterations;
	int	piles_in_a;
	int	x_pile_len;
	int	x_piles_in_a;
	int	x_iterations;

	mp_ctrl = (t_mp_ctrl *)malloc(sizeof(t_mp_ctrl));
	mp_ctrl->piles_len = piles_len;
	mp_ctrl->iterations = 0;
	mp_ctrl->next_piles = 0;

	// iterations = 0;
	if (mp_ctrl->piles_len == 1 || mp_ctrl->piles_len == 2)
		handle_piles_1_2_b(stack_a, stack_b, mp_ctrl->piles_len);
	else
	{
		piles_in_a = init_piles_b(stack_a, stack_b, mp_ctrl->piles_len);
		mp_ctrl->next_piles = piles_in_a;
		while (mp_ctrl->iterations < piles_in_a)
		{
			x_iterations = 0;
			x_pile_len = pile_len(mp_ctrl->piles_len, piles_in_a, mp_ctrl->iterations);
			if (x_pile_len == 1 || x_pile_len == 2)
				x_handle_piles_1_2_a(stack_a, stack_b, x_pile_len);
			else
			{
				x_piles_in_a = init_piles_a(stack_a, stack_b, x_pile_len);
				while (x_iterations < x_piles_in_a)
				{
					middle_point(stack_a, stack_b,
						pile_len(x_pile_len, x_piles_in_a, x_iterations));
					x_iterations++;
				}
				correction_mp(stack_a, stack_b, x_pile_len, 'a');
			}
			mp_ctrl->iterations++;
		}
		correction_mp(stack_a, stack_b, piles_len, 'b');
	}
}

/**
 * Main func for big number sorting
 * Using middle point algorithm
 * @param stack_a
 * @param stack_b
 */
void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int	max_size;
	int	piles_len;
	int	number_of_piles;
	int	iterations;

	iterations = 0;
	max_size = ft_lst_size(*stack_a);
	number_of_piles = init_piles(stack_a, stack_b);
	while (iterations < number_of_piles)
	{
		piles_len = pile_len(max_size, number_of_piles, iterations);
		middle_point(stack_a, stack_b, piles_len);
		iterations++;
	}
}
