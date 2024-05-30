NAME = cub3d
SRC = *.c
OBJ = $(SRC:.c=.o)
GNL = libft/get_next_line
FLGS = -Wall -Wextra -Werror
MLX = -l mlx -lGL

$(NAME):
	make -C mlx
	make -C libft
	gcc $(SRC) $(FLGS) -c $(MLX)
	gcc $(OBJ) -o $(NAME) libft/libft.a mlx/libmlx.a -lXext -lX11 -lm

all : $(NAME)

clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all
