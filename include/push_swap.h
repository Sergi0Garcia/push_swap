/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:18:27 by segarcia          #+#    #+#             */
/*   Updated: 2022/11/17 10:18:11 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include <signal.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

// ---------- init ---------- //
int		save_into_stack(t_node **stack, int value);
void	parse_input(char **argv, t_node **stack_a);
void	free_stacks(t_node **stack_a, t_node **stack_b);
void	free_parsing_exit(char ***split, t_node **stack_a, int i);
// ---------- utils ---------- //
int		ft_atoi_checker(char ***split, t_node **stack_a, int j);
void	exit_error(void);
void	exit_error_free_stacks(t_node **stack_a, t_node **stack_b);
void	exit_success(t_node **stack_a, t_node **stack_b);
int		is_stack_ordered(t_node *stack);
int		find_smallest_idx(t_node **stack);
void	set_index_to_list(t_node **stack_a);
int		ft_lst_size(t_node *lst);
t_node	*ft_new_node(int value);
t_node	*ft_last_node(t_node *lst);
// ---------- instructions ---------- //
void	swap(t_node **stack);
void	push(t_node **origin, t_node **destination);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_ab(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_a(t_node **stack_a);
void	reverse_rotate_b(t_node **stack_b);
void	reverse_rotate_ab(t_node **stack_a, t_node **stack_b);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ab(t_node **stack_a, t_node **stack_b);
// ---------- sorting ---------- //
void	sort_2(t_node **stack_a);
void	sort_3(t_node **stack_a);
void	sort_4(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **stack_a, t_node **stack_b);
void	sort_big(t_node **stack_a, t_node **stack_b);
// ----- sort_big_utils ------ //
void	init_dispersion(t_node **stack_a, t_node **stack_b, int mp);
int		init_piles(t_node **stack_a, t_node **stack_b);
int		init_piles_a(t_node **stack_a, t_node **stack_b, int max_len);
int		init_piles_b(t_node **stack_a, t_node **stack_b, int max_len);
int		get_minimum_index_from_pile(t_node **stack, int pile_len);
int		get_middle_point_index(t_node **stack, int pile_len);
int		is_strict_sorted_ascending(t_node **stack, int len);
int		pile_len(int max_size, int max_piles, int iterations);

#endif