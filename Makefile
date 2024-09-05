# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 10:47:05 by jlarue            #+#    #+#              #
#    Updated: 2023/02/06 12:11:06 by jlarue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf


MLX_FLAG        = -lX11 -lXext
MLX_FILE        = libmlx.a
MLX_PATH        = minilibx-linux/
MLX_LIB            = $(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX            = $(MLX_LIB) $(MLX_FLAG)

CC = cc -Wall -Werror -Wextra -g

RM = rm -f

SRC = main.c \
	  check_utils01.c \
	  map_size.c \
	  drawing.c \
	  malloc_tabtab.c \
	  ft_utils.c \
	  ft_brensenham.c \
	  main_ph.c \
	  center.c \
	  drawing_utils.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: mlx $(OBJ)
	make -C libft
	cp libft/libft.a .
	$(CC) $(OBJ) libft.a $(MLX_EX) -o $(NAME)

mlx:
	make -C $(MLX_PATH)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C $(MLX_PATH)
	make -C libft
	cp libft/libft.a .
	$(CC) $(OBJ) libft.a $(MLX_EX) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C libft
	make clean -C minilibx-linux

fclean:    clean
	$(RM) $(NAME)
	rm -f libft.a
	rm -f libmlx.a

re: fclean all

.PHONY: all bonus clean fclean re
