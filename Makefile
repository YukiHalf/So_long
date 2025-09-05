# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 17:39:17 by sdarius-          #+#    #+#              #
#    Updated: 2025/09/05 21:37:16 by sdarius-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS	:=  -Wunreachable-code -O3 -ffast-math
MLX_DIR		:= ./lib/MLX42
MLX		:= $(MLX_DIR)/build/libmlx42.a
LIBFT_DIR	:= ./lib/libft
LIBFT 	:= $(LIBFT_DIR)/libft.a
HEADERS	:= -I ./inc -I $(MLX_DIR)/include/MLX42 -I $(LIBFT_DIR)/inc
UNAME_S	:= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS	:= -L$(LIBFT_DIR) -lft $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
endif
GLFW := $(shell brew --prefix glfw)
ifeq ($(UNAME_S),Darwin)
	LIBS := -L$(LIBFT_DIR) -lft $(MLX_DIR)/build/libmlx42.a \
	-Iinclude -lglfw -L$(GLFW)/lib -pthread -lm
endif
SRC_DIR	:= src
SRC		:= so_long_main.c \
		  	 so_long_parse.c \
		   	so_long_utils.c \
		   	so_long_game_check.c \
		   	so_long_pathfinding.c
SRCS	:= $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR	:= obj
OBJ		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME	:= so_long

all: $(NAME)

$(MLX): $(MLX_DIR)
	cmake $(MLX_DIR) -B $(MLX_DIR)/build;
	make -C$(MLX_DIR)/build -j4;

$(LIBFT): $(LIBFT_DIR)
	make -C$(LIBFT_DIR);

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $@;

$(LIBFT_DIR):
	./lib/libft

$(OBJ_DIR):
	mkdir obj

$(NAME): $(MLX) $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/fdf.h
	$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS)

clean:
	rm -rf $(OBJ)
	make clean -C$(LIBFT_DIR)

fclean: clean
	rm $(NAME)
	rmdir $(OBJ_DIR)
	rm -rf $(LIBFT_DIR)
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all, clean, fclean, re
