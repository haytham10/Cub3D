NAME = Cub3D

SRC = src/controls.c	\
	src/exit.c 			\
	src/getColor.c		\
	src/getRes.c		\
	src/getTexture.c	\
	src/init.c 			\
	src/loadMap.c 		\
	src/loadMapUtils.c	\
	src/loadAssets.c 	\
	src/loadPlayer.c 	\
	src/main.c 			\
	src/mapChecks.c 	\
	src/render.c 		\
	src/movement.c 		\
	src/raycast.c 		\
	src/gnl.c 			\

INC = -I /inc/cub.h

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_API = -lmlx -framework OpenGL -framework AppKit

LIBFT = lib/libft.a

LIBFT_INC = -I lib/libft.h

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

GNL_INC = -I gnl/get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_API) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) $(LIBFT_INC)-c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
