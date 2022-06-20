# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 18:22:43 by bbraga            #+#    #+#              #
#    Updated: 2022/06/20 00:23:42 by bbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_hex_format.c ft_printf.c ft_unsigned.c \
	   ft_ptr.c ft_utils.c ft_utils2.c ft_itoa_printf.c \

NAME = libftprintf.a

OBJS_DIR = ./
OBJS = $(SRCS:.c=.o)

CC = cc
CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c ft_printf.h
	cc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
