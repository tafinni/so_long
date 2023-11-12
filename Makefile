# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfinni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 12:59:24 by tfinni            #+#    #+#              #
#    Updated: 2023/06/09 16:22:54 by tfinni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
SRC		=	so_long.c movements.c put_img.c render.c validatemap.c helpers.c exit_error.c validate_helpers.c
OBJ		=	$(SRC:.c=.o)
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
INCLUDE	=	-I include
LIBFT	=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) $(OBJ) $(INCLUDE) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
