NAME = so_long
SRC = ./src/main.c ./src/check.c \
      ./src/free.c ./src/path_img.c \
	  ./src/put.c  ./src/read_map1.c \
	  ./src/read_map2.c ./src/get_next_line.c \
	  ./src/get_next_line_utils.c
OBJS = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror
MLX = -L ./includes/minilibx -lmlx
ADD = -framework OpenGL -framework AppKit
INCLM = -I ./includes/minilibx

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./includes/minilibx
	gcc $(FLAGS) -o $(NAME) $(MLX) -o $@ $^ $(ADD)

%.o: %.c ./includes/so_long.h
	gcc $(FLAGS) $(INCLM) -o $@ -c $<

clean: 
	rm -rf $(OBJS)
	make clean -C ./includes/minilibx
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: re clean fclean