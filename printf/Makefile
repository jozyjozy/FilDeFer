# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 10:47:05 by jlarue            #+#    #+#              #
#    Updated: 2022/12/16 11:25:20 by jlarue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc -Wall -Werror -Wextra

RM = rm -f

SRC = ft_printf.c              \
      ft_putchar_count.c       \
      ft_putnbr_count.c        \
      ft_putstr_count.c        \
      ft_putunsnbr_count.c 	   \
	  ft_putnbrhex_count.c 	   \
	  ft_putadress_hex_count.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C ../libft
	cp ../libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)
	make clean -C ../libft

fclean:    clean
	$(RM) $(NAME)
	make fclean -C ../libft

re: fclean all

.PHONY: all bonus clean fclean re
