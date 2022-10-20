/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:18:27 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/20 10:30:29 by segarcia         ###   ########.fr       */
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
	struct s_node	*next;
}					t_node;

void	exit_error(void);
int		ft_atoi_checker(const char *str);
void	save_into_stack(t_node **stack, int value);
void	parse_input(char **argv, t_node **stack_a);
int		ft_lst_size(t_node *lst);
t_node	*ft_new_node(int value);
void	ft_print_list(t_node *lst);
t_node	*ft_last_node(t_node *lst);
void	swap(t_node **stack);
void	push(t_node **origin, t_node **destination);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	otate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_ab(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_a(t_node **stack_a);
void	reverse_rotate_b(t_node **stack_b);
void	reverse_rotate_ab(t_node **stack_a, t_node **stack_b);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ab(t_node **stack_a, t_node **stack_b);

#endif