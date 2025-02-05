NAME		= so_long
CFLAGS		= -Wextra -Wall -Werror -g -Wunreachable-code -Ofast -fPIE
LIBMLX		= ./lib/MLX42
CC			= gcc

HEADERS		= -I ./include -I $(LIBMLX)/include
LIBFT_DIR	= ./lib/libft
PRINTF_DIR 	= ./lib/printf
MLX_PATH	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT_PATH	= ./lib/libft/libft.a
PRINTF_PATH	= ./lib/printf/libftprintf.a
LIBS_PATH	= $(LIBFT_PATH) $(PRINTF_PATH) $(MLX_PATH)
SRCS		= ./src/so_long.c \
				./src/init_map.c \
				./src/init_game.c \
				./src/error.c \
				./src/validation.c \
				./src/flood_fill.c \
				./src/handle_moves.c \
				./src/utils.c \
				./src/finish.c \
				./src/texture.c

SRCS_BONUS	= ./src_bonus/error_bonus.c \
				./src_bonus/finish_bonus.c \
				./src_bonus/flood_fill_bonus.c \
				./src_bonus/handle_moves_bonus.c \
				./src_bonus/init_game_bonus.c \
				./src_bonus/init_map_bonus.c \
				./src_bonus/so_long_bonus.c \
				./src_bonus/texture_bonus.c \
				./src_bonus/utils_bonus.c \
				./src_bonus/validation_bonus.c \
				./src_bonus/utils2_bonus.c \
				./src_bonus/free_bonus.c

OBJ_DIR		= ./obj
OBJ_BONUS_DIR	= ./obj_bonus


OBJS		= ${SRCS:./src/%.c=$(OBJ_DIR)/%.o}
OBJS_BONUS 	= ${SRCS_BONUS:./src_bonus/%.c=$(OBJ_BONUS_DIR)/%.o}

GREEN = \033[1;32m

GIT_MLX = git clone https://github.com/42-Fundacion-Telefonica/MLX42.git $(LIBMLX)

all: check_mlx $(NAME)

$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	
$(OBJ_BONUS_DIR)/%.o: ./src_bonus/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(OBJS) $(LIBS_PATH) $(HEADERS) -o $(NAME)
	@echo "${GREEN}type: ./so_long maps/map1.ber"

bonus: $(OBJS_BONUS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(OBJS_BONUS) $(LIBS_PATH) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

re: fclean all

check_mlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		echo "MLX42 not found. Downloading..."; \
		make download_mlx; \
	fi

download_mlx:
		$(GIT_MLX)
		cd $(LIBMLX) && cmake -B build
		cd $(LIBMLX) && cmake --build build -j4
		clear

undownload_mlx:
		rm -rf $(LIBMLX)

.PHONY: all, clean, fclean, re, libmlx
