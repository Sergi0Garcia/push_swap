# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 13:08:18 by segarcia          #+#    #+#              #
#    Updated: 2022/11/12 17:27:20 by segarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap
SRC			= 	./src/main.c						\
				./src/init.c						\
				./src/instructions/movements.c		\
				./src/instructions/push.c			\
				./src/instructions/swap.c			\
				./src/instructions/rotate.c			\
				./src/instructions/rrotate.c		\
				./src/sorting/sort_2.c 				\
				./src/sorting/sort_3.c 				\
				./src/sorting/sort_4.c 				\
				./src/sorting/sort_5.c 				\
				./src/sorting/sort_big_init_a.c 	\
				./src/sorting/sort_big_init_b.c 	\
				./src/sorting/sort_big_init.c 		\
				./src/sorting/sort_big_utils.c 		\
				./src/sorting/sort_big.c 			\
				./src/utils/atoi_checker.c			\
				./src/utils/error.c					\
				./src/utils/list_utils_2.c			\
				./src/utils/list_utils.c

OBJS		= $(SRC:.c=.o)

LIBFT		= ./libft/libft.a
LIBFT_PATH	= ./libft
PRINTF		= ./libft/ft_printf/libftprintf.a
PRINTF_PATH	= ./libft/ft_printf

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(LIBFT):
	@make bonus -C $(LIBFT_PATH)

$(PRINTF):
	@make -C $(PRINTF_PATH)

$(NAME): $(LIBFT) $(PRINTF) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)
	@$(RM) *.o

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(PRINTF_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re