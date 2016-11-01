NAME=fractol
SRC=main.c \
	test_args.c \
	mlx_img_assign.c \
	complex.c \
	fractals_mandelbrot.c \
	fractals_julia.c
OBJ=$(SRC:.c=.o)
LIBX=/usr/local/lib
LIBFT=../libft
FLAGS=#-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT) re
	gcc $^ -L$(LIBX) -lmlx -L$(LIBFT) -lft -framework OpenGL -framework AppKit -o $(NAME) $(FLAGS)
	@echo "\033[0;31mFractol-senpai noticed me\033[0m"

%.o:%.c
	gcc -I $(LIBFT)/includes -c $< $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
