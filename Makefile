NAME     := cub3D
CC       := cc
RM       := rm -f

MLX_DIR  := /opt/minilibx-linux
MLX_INC  := -I$(MLX_DIR)
MLX_LIB  := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

CFLAGS := -Wall -Wextra -Werror -Iinclude -Ilibft/includes $(MLX_INC)

SRCS     := $(wildcard src/*.c)
OBJS     := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

