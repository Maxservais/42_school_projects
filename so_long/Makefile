# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mservais <mservais@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 17:24:30 by mservais          #+#    #+#              #
#    Updated: 2021/09/17 17:56:39 by mservais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	check.c \
					controls.c \
					draw.c \
					free.c \
					init.c \
					main.c \
					parse.c \
					utils.c

OBJ_FILES		=	$(SRC_FILES:.c=.o)

NAME			= 	so_long

SO_LONG_LIB		=	libsolong.a

MLX_LIB			=	libmlx.dylib

CC				=	gcc

INCLUDE			=	-Lmlx -lmlx -framework OpenGL -framework AppKit

CFLAGS			=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(MAKE) -s -C mlx
	cp mlx/$(MLX_LIB) $(MLX_LIB)
	@$(MAKE) -s -C get_next_line
	cp get_next_line/libgnl.a $(SO_LONG_LIB)
	ar -rcs $(SO_LONG_LIB) $^
	$(CC) $(CFLAGS) main.c $(SO_LONG_LIB) $(INCLUDE) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ_FILES)
	$(MAKE) clean -C get_next_line
	$(MAKE) clean -C mlx

fclean: clean
	rm -rf $(NAME)
	rm -rf $(SO_LONG_LIB)
	rm -rf $(MLX_LIB)
	$(MAKE) fclean -C get_next_line

re: fclean all

.PHONY: all clean fclean re
