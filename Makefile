# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 14:39:22 by plamusse          #+#    #+#              #
#    Updated: 2017/12/07 23:04:22 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

#directories
SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./lib/libft
MLX_DIR = ./lib/mlx

# src / obj files

FILES =	main.c \
		draw_tools.c \
		draw.c \
		parser.c \
		bind.c \
		process_coords.c \
		utl.c

SRC =	$(addprefix $(SRC_DIR)/, $(FILES)))
OBJ = 	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))


# compiler and flags
CC =		gcc

# frameworks
FRM =		-framework AppKit -framework OpenGL

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./includes/fdf.h ./lib/libft/includes/libft.h
	$(CC) -o $@ -I./includes -c $<

# mlx and ft are dependencies, so when compiling fractol, make checks for changes in the libraries
# and rebuilds them if necessary
$(NAME): mlx ft $(OBJ_DIR) $(OBJ)
	$(CC) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(FRM)


.PHONY: clean
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


# .PHONY indicates that we are not actually constructing a target, 
# we just just the terms mlx, ft to call the underlying commands
.PHONY: mlx
mlx:
	$(MAKE) -C $(MLX_DIR)

.PHONY: ft
ft:
	$(MAKE) -C $(LIBFT_DIR)

