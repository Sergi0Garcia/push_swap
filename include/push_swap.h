/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:18:27 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/19 09:52:47 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

# include "../libft/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include <signal.h>

void	exit_error(void);
int		ft_atoi_checker(const char *str);
void	save_into_stack(t_node **stack, int value);
void	parse_input(char **argv, t_node **stack_a);
t_node	*ft_new_node(int value);
void	ft_print_list(t_node *lst);
t_node	*ft_last_node(t_node *lst);

#endif