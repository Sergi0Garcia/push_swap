# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 13:08:18 by segarcia          #+#    #+#              #
#    Updated: 2022/10/19 09:58:05 by segarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
SRC			= 	./src/main.c			\
				./src/list_utils.c  	\
				./src/atoi_checker.c 	\
				./src/init.c			\
				./src/instructions.c	\
				./src/error.c

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