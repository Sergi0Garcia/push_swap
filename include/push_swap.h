/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:18:27 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/13 11:27:42 by segarcia         ###   ########.fr       */
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

t_node	*ft_new_node(int value);
void	ft_print_list(t_node *lst);

#endif