# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 15:01:40 by aoutumur          #+#    #+#              #
#    Updated: 2025/03/10 17:00:17 by aoutumur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = ./srcs
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/fill_stack.c \
       $(SRC_DIR)/input_check.c \
       $(SRC_DIR)/push.c \
       $(SRC_DIR)/swap.c \
       $(SRC_DIR)/rotate.c \
       $(SRC_DIR)/reverse_rotate.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/sort_tiny.c \
       $(SRC_DIR)/sort.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I . -I includes -I ft_printf/libft
LIBFTPRINTF_DIR= ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFTPRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
