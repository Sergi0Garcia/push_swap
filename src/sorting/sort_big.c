/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:16 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/28 13:58:34 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	print_ab(t_node *stack_a, t_node *stack_b)
{
	ft_printf("---------\n");
	ft_printf("--- a ---\n");
	ft_print_list(stack_a);
	ft_printf("--- b ---\n");
	ft_print_list(stack_b);
	ft_printf("---------\n");
}

int get_minimum_index_from_pile(t_node **stack)
{
	t_node *tmp;
	int smallest_idx;

	tmp = *stack;
	smallest_idx = (*stack)->index;
	while (tmp->next)
	{
		if (tmp->next->index < smallest_idx)
			smallest_idx = tmp->next->index;
		tmp = tmp->next;
	}
	return (smallest_idx);
}

int get_minimum_index_from_pile_b(t_node **stack, int pile_len)
{
	t_node *tmp;
	int smallest_idx;
	int i;

	tmp = *stack;
	i = 0;
	smallest_idx = tmp->index;
	while (tmp->next && i < pile_len - 1)
	{
		// ft_printf("smallest idx: %i with i[%i]\n", smallest_idx, i);
		if (tmp->next->index < smallest_idx)
			smallest_idx = tmp->next->index;
		tmp = tmp->next;
		i++;
	}
	// ft_printf("smallest idx: %i with i[%i]\n", smallest_idx, i);
	return (smallest_idx);
}

int	get_middle_point_index(t_node **stack)
{
	int len;
	int smallest_idx;
	int	middle_point;

	len = ft_lst_size(*stack);
	smallest_idx = get_minimum_index_from_pile(stack);
	middle_point = smallest_idx + (len / 2);
	return (middle_point);
}

int	get_middle_point_index_b(t_node **stack, int pile_len)
{
	int smallest_idx;
	int	middle_point;

	smallest_idx = get_minimum_index_from_pile_b(stack, pile_len);
	middle_point = smallest_idx + (pile_len / 2);
	return (middle_point);
}

int get_pile_b_len(int max_len, int i_a_to_b)
{
	int i;
	int res;

	i = 0;
	res = max_len;
	while (i < i_a_to_b)
	{
		res /= 2;
		i++;
	}
	return (res);
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int		max_len;
	int		pile_len;
	int		pile_b;
	int		middle_point_a;
	int		minimun_idx;
	int 	middle_point_b;
	int		i_a_to_b;
	int		i_b_to_a;
	int		i_b_to_a_intern;
	t_node 	*last;

	i_a_to_b = 0;
	i_b_to_a = 0;
	i_b_to_a_intern = 0;
	max_len = ft_lst_size(*stack_a);
	while (ft_lst_size(*stack_a) > 3)
	{
		pile_len = ft_lst_size(*stack_a);
		middle_point_a = get_middle_point_index(stack_a);
		minimun_idx = get_minimum_index_from_pile(stack_a);
		// ft_printf("middle_point_a: %i\n", middle_point_a);
		while (ft_lst_size(*stack_a) > (pile_len - (middle_point_a - minimun_idx)))
		{
			// print_ab(*stack_a, *stack_b);
			if ((*stack_a)->index < middle_point_a)
				push_b(stack_a, stack_b);
			else
			{
				last = ft_last_node(*stack_a);
				if (last->index < middle_point_a)
					reverse_rotate_a(stack_a);
				else
					rotate_a(stack_a);
			}
		}
		i_a_to_b++;
	}
	if (ft_lst_size(*stack_a) == 2)
		sort_2(stack_a);
	else if (ft_lst_size(*stack_a) == 3)
		sort_3(stack_a);
	print_ab(*stack_a, *stack_b);
	ft_printf("i_a_to_b: %i\n", i_a_to_b);
	while (i_b_to_a < i_a_to_b)
	{
		print_ab(*stack_a, *stack_b);
		pile_b = get_pile_b_len(max_len, i_a_to_b - i_b_to_a);
		middle_point_b = get_middle_point_index_b(stack_b, pile_b);
		ft_printf("pile_b: %i\n", pile_b);
		ft_printf("middle_point_b: %i\n", middle_point_b);
		if (pile_b == 1)
		{
			push_a(stack_a, stack_b);
		}
		if (pile_b == 2)
		{
			if ((*stack_b)->index < (*stack_b)->next->index)
				swap_b(stack_b);
			push_a(stack_a, stack_b);
			push_a(stack_a, stack_b);
		}
		else
		{
			// while (i_b_to_a_intern < pile_len)
			// {
			// 	return ;
			// }

		}
		i_b_to_a++;
	}

	// max_len = ft_lst_size(*stack_b);
	// middle_point = (max_len / 2) + 1;
	// while (ft_lst_size(*stack_b) > (max_len - middle_point + 1))
	// {
	// 	if ((*stack_b)->index > middle_point)
	// 		push_a(stack_a, stack_b);
	// 	else
	// 	{
	// 		last = ft_last_node(*stack_b);
	// 		if (last->index > middle_point)
	// 			reverse_rotate_b(stack_b);
	// 		else
	// 			rotate_b(stack_b);
	// 	}
	// }
	// if ((*stack_b)->index < (*stack_b)->next->index)
	// 	swap_b(stack_b);
	// print_ab(*stack_a, *stack_b);
	// push_a(stack_a, stack_b);
	// push_a(stack_a, stack_b);
}