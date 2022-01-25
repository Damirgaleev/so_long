NAME = so_long
SRC = ./src/main.c ./src/check.c \
      ./src/free.c ./src/path_img.c \
	  ./src/put.c  ./src/read_map1.c \
	  ./src/read_map2.c
OBJS = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror
MLX = -L ./includes/minilibx -lmlx
ADD = -framework OpenGL -framework AppKit
INCLM = -I ./includes/minilibx
LIB = -L ./includes/libft -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./includes/libft
	make -C ./includes/minilibx
	gcc $(FLAGS) -o $(NAME) $(LIB) $(MLX) -o $@ $^ $(ADD)

%.o: %.c ./includes/so_long.h
	gcc $(FLAGS) $(INCLM) -o $@ -c $<

clean: 
	rm -rf $(OBJS)
	make clean -C ./includes/minilibx
	make clean -C ./includes/libft
fclean: clean
	make fclean -C ./includes/libft
	rm -rf $(NAME)
re: fclean all

.PHONY: re clean fclean