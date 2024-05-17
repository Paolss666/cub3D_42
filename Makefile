# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 16:22:18 by npaolett          #+#    #+#              #
#    Updated: 2024/05/16 14:48:13 by elcesped         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
BONUS = cub3D_bonus

CC = cc

RM = rm -fr

CFLAGS = -g3 -Wall -Wextra -Werror 

INCL = -I ./libft 

MLXFLAGS = -lX11 -lXext -lm
INCL = -I -I./libft -I./mlx_linux

SRC = 	src/get_map.c \
		src/get_maps_utils.c \
		src/parse_type.c \
		src/parse_types2.c \
		src/parse_type_err.c \
		src/parse_type_utils.c \
		src/ft_split_grb.c \
		src/parse_type_err_check.c \
		src/get_pos.c  \
		src/get_pos2.c  \
		src/event.c  \
		src/algo.c  \
		src/get_pixel.c  \
		src/draw.c  \
		src/move_algo.c  \
		src/move_algo_rot.c  \
		src/door.c  \
		src/mouse_move.c  \
		check_map/map.c \
		check_map/ft_check_char.c \
		check_map/ft_check_map.c \
		main.c  \

SRC_BONUS = src_bonus/get_map.c \
			src_bonus/get_maps_utils.c \
			src_bonus/parse_type.c \
			src_bonus/parse_types2.c \
			src_bonus/parse_type_err.c \
			src_bonus/parse_type_utils.c \
			src_bonus/ft_split_grb.c \
			src_bonus/parse_type_err_check.c \
			src_bonus/get_pos.c  \
			src_bonus/get_pos2.c  \
			src_bonus/event.c  \
			src_bonus/algo.c  \
			src_bonus/get_pixel.c  \
			src_bonus/draw.c  \
			src_bonus/move_algo.c  \
			src_bonus/move_algo_rot.c  \
			src_bonus/door.c  \
			src_bonus/mouse_move.c  \
			check_map/map.c \
			check_map/ft_check_char_bonus.c \
			check_map/ft_check_map_bonus.c \
			minimap/minimap.c \
			minimap/minimap2.c \
			sprite/sprite.c \
			sprite/algo_sprite.c \
			sprite/init_sprite.c \
			main_bonus.c  \
 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

DEPS = $(OBJS:.o=.d)

LIBFT = ./libft/libft.a
LIBMLX = ./mlx_linux/libmlx.a

$(NAME): $(OBJ)
		make lib
		make mlx
		cc -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(MLXFLAGS)

$(BONUS): $(OBJ_BONUS)
		make lib
		make mlx
		cc -o $(BONUS) $(OBJ_BONUS) $(LIBFT) $(LIBMLX) $(MLXFLAGS)

all : $(NAME)

bonus : $(BONUS)

-include $(DEPS)

%.o: %.c
	cc $(INCL) $(CFLAGS) -o $@ -c $<

mlx:
	make -C ./mlx_linux/ all

lib:
	make -C ./libft/ all
	
clean:
	@make -C libft/ clean
	@make -C mlx_linux/ clean
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)  $(LIBMLX) $(BONUS)

re: fclean 
	make all

rebonus: fclean
		make bonus 

.PHONY: all clean fclean 