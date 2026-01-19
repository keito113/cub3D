NAME     := cub3D
CC       := cc
RM       := rm -f

MLX_DIR  := ./minilibx-linux
MLX_INC  := -I$(MLX_DIR)
MLX_LIB  := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
MLX_A    := $(MLX_DIR)/libmlx.a

LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

CFLAGS := -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)/includes $(MLX_INC)

OBJ_DIR := obj

SRCS := $(shell find src -name '*.c')
OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re


