NAME =	cub3d
S_DIR =	src/
SRC =	bonus.c \
		checks.c \
		find_orien.c \
		loop_utility.c \
		main.c \
		movements.c \
		norm_utility.c \
		parsing.c \
		ray_casting.c \
		spiral.c \
		utility.c

O_DIR =	obj/
OBJ	=	$(addprefix $(O_DIR),$(SRC:%.c=%.o))
FLGS =	-Wall -Wextra -Werror
LIBS =	libs/libft.a \
		libs/libmlx_Linux.a

all : $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(LIBS) -lXext -lX11 -lm

$(O_DIR)%.o: $(S_DIR)%.c
	mkdir -p $(O_DIR)
	gcc $(FLGS) -c $< -o $@

clean :
	rm -rf $(O_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all