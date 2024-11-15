# -*- Makefile -*-

NAME = cub3d
SRC = *.c
OBJ = $(SRC:.c=.o)
GNL = libft/get_next_line
FLGS = -Wall -Wextra -Werror
MLX = -l mlx -lGL

all : $(NAME)

$(NAME): $(OBJ)
	make -C mlx
	make -C libft
	gcc $(OBJ) -o $(NAME) libft/libft.a mlx/libmlx.a -lXext -lX11 -lm

%.o: %.c
    gcc $(FLGS) -c $< -o $@

clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all
