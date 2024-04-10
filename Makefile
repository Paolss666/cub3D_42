# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 16:22:18 by npaolett          #+#    #+#              #
#    Updated: 2024/04/10 14:19:04 by npaolett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CC = cc

RM = rm -fr

CFLAGS = -g3 -Wall -Wextra -Werror 

INCL = -I ./libft 

MLXFLAGS = -lX11 -lXext -lm
INCL = -I -I./libft -I./mlx_linux

SRC = 	src/get_map.c \
		src/parse_type.c \
		src/parse_types2.c \
		src/parse_type_err.c \
		src/ft_split_grb.c \
		src/parse_type_err_check.c \
		src/get_pos.c  \
		src/main.c  \
  
OBJ = $(SRC:.c=.o)
# OBJ_BONUS = $(SRC_BONUS:.c=.o)


LIBFT = ./libft/libft.a
LIBMLX = ./mlx_linux/libmlx.a

$(NAME): $(OBJ)
		make lib
		make mlx
		cc -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(MLXFLAGS)

# $(BONUS): $(OBJ_BONUS)
 # make lib
# cc -o $(BONUS) $(OBJ_BONUS) $(LIBFT) 

all : $(NAME)

bonus : $(BONUS)

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