# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 16:33:08 by hmokhtar          #+#    #+#              #
#    Updated: 2023/03/12 16:39:32 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = src/main.c

INC = inc/cub.h

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

MLX_API = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX_API) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all