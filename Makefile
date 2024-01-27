# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skuznets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 16:27:36 by skuznets          #+#    #+#              #
#    Updated: 2024/01/27 17:16:27 by skuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar rc
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT		= libft

SRC = ft_printf.c ft_utils.c



OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re