# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damedina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 17:05:36 by damedina          #+#    #+#              #
#    Updated: 2023/12/30 17:05:39 by damedina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = src/push_swap.c src/sort.c src/count_moves.c src/push.c src/swap.c src/rotate.c src/reverse_rotate.c src/push_aux.c src/sort_aux.c src/parse_args.c src/free_malloc.c src/print_stacks.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = libft/libft.a

all:		$(NAME)

$(NAME):
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re:			fclean	all

.PHONY:
	all clean fclean re
