/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/15 10:00:12 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * func to handle movements for piles in b
 * Easy functions to do when having 1 or 2 nums
 * If we have 1 = We just push it back since we do not need sorting
 * If we have 2 = We check, sort and push back again
 * @param stack_a
 * @param stack_b
 * @param pile_len
 * @return int
 */
int	handle_piles_1_2_b(t_node **stack_a, t_node **stack_b, int pile_len)
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
	return (pile_len);
}

/**
 * func to handle movements for piles in a
 * Easy functions to do when having 1 or 2 nums
 * If we have 1 = We just push it back since we do not need sorting
 * If we have 2 = We check, sort and push back again
 * @param stack_a
 * @param stack_b
 * @param x_pile_len
 * @return int
 */
int	x_handle_piles_1_2_a(t_node **stack_a, t_node **stack_b, int x_pile_len)
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
	return (x_pile_len);
}

/**
 * Func to correct piles
 * We do it whenever we have a stack but not the last one
 * Nums were rotated and we need to get those back
 * Iterate i to get remaining nums of chunks back again at level position
 * @param stack_a
 * @param stack_b
 * @param i
 * @param act_stack
 */
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

/**
 * Middle point function
 * Function were all the magic happens [recursive function]
 * Start handling chunk by chunk from the init split
 * Decide if we need to split tile again or handle small pile
 * If small we only push it back again to our pile ASC stack_a
 * With big chunks, we split it again from stack_b and repat proccess
 * Repeat c/chunk until all nums are sorted in ASC in stack_a
 * @param stk_a
 * @param stk_b
 * @param piles_len
 */
static void	mp(t_node **stk_a, t_node **stk_b, int piles_len)
{
	int	i;
	int	xi;
	int	nxt_pile;
	int	xpile_len;
	int	xnxt_pile;

	i = 0;
	if (handle_piles_1_2_b(stk_a, stk_b, piles_len) > 2)
	{
		nxt_pile = init_piles_b(stk_a, stk_b, piles_len);
		while (++i <= nxt_pile)
		{
			xi = 0;
			xpile_len = pile_len(piles_len, nxt_pile, i - 1);
			if (x_handle_piles_1_2_a(stk_a, stk_b, xpile_len) > 2)
			{
				xnxt_pile = init_piles_a(stk_a, stk_b, xpile_len);
				while (++xi <= xnxt_pile)
					mp(stk_a, stk_b, pile_len(xpile_len, xnxt_pile, xi - 1));
				correction_mp(stk_a, stk_b, xpile_len, 'a');
			}
		}
		correction_mp(stk_a, stk_b, piles_len, 'b');
	}
}

/**
 * Main func for big number sorting
 * Using middle point algorithm
 * [1] Get middle point from initial stack
 * [2] Split half to the other (ASC(Stack_a)/DESC(stack_b))
 * [3] Repeat same step with remaining parts until having < 3 nums
 * [4] Do the same procedure in recursive way for each chunk in either stack
 * [5] Sort them until you order stack by stack
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
		mp(stack_a, stack_b, piles_len);
		iterations++;
	}
}
