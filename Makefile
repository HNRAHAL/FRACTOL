NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRCS = fractol.c \
	calculate.c \
	color.c \
	display.c \
	draw.c \
	error.c \
	event_handler.c \
	events.c \
	free.c \
	setup.c \
	utils.c \
	var_init.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re