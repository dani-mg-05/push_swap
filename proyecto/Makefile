# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damedina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 17:05:36 by damedina          #+#    #+#              #
#    Updated: 2024/07/24 06:36:31 by damedina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = src
OBJ_DIR = obj

BONUS_SRC_DIR = bonus
BONUS_OBJ_DIR = bonus_obj

SRC =	$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/sort.c \
		$(SRC_DIR)/count_moves.c \
		$(SRC_DIR)/push.c \
		$(SRC_DIR)/swap.c \
		$(SRC_DIR)/rotate.c \
		$(SRC_DIR)/reverse_rotate.c \
		$(SRC_DIR)/push_aux.c \
		$(SRC_DIR)/sort_aux.c \
		$(SRC_DIR)/parse_args.c \
		$(SRC_DIR)/free_malloc.c \
		$(SRC_DIR)/print_stacks.c

BONUS_SRC =	$(BONUS_SRC_DIR)/checker_bonus.c \
			$(BONUS_SRC_DIR)/get_next_line_bonus.c \
			$(BONUS_SRC_DIR)/check_instructions_bonus.c \
			$(BONUS_SRC_DIR)/push_bonus.c \
			$(BONUS_SRC_DIR)/swap_bonus.c \
			$(BONUS_SRC_DIR)/rotate_bonus.c \
			$(BONUS_SRC_DIR)/reverse_rotate_bonus.c \
			$(BONUS_SRC_DIR)/push_aux_bonus.c \
			$(BONUS_SRC_DIR)/parse_args_bonus.c \
			$(BONUS_SRC_DIR)/free_malloc_bonus.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(BONUS_OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
