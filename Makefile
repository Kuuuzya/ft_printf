# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skuznets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 16:27:36 by skuznets          #+#    #+#              #
#    Updated: 2024/03/20 19:45:05 by skuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar rc
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT	= libft

SRC = ft_printf.c ft_utils/ft_printnumber.c ft_utils/ft_printpercent.c \
	ft_utils/ft_printstring.c ft_utils/ft_putchar.c \
	ft_utils/ft_printunsignint.c ft_utils/ft_printhex.c ft_utils/ft_printupperhex.c \
	ft_utils/ft_printpointer.c

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
	rm -f libft/*.o
	rm -f libft/libft.a

fclean: clean
	rm -f $(NAME) $(OBJ) libft/*.o

re: fclean all

.PHONY: all clean fclean re