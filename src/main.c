/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:46:01 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/11 10:08:56 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	argc_validation(int argc)
{
	if (argc < 2)
	{
		ft_printf("Usage: ./push_swap int[] \n");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	argc_validation(argc);
	ft_printf("Hello\n");
	ft_printf("%s", argv[1]);
	return (0);
}