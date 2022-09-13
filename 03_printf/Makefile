# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mservais <mservais@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 11:23:17 by mservais          #+#    #+#              #
#    Updated: 2021/09/03 12:17:37 by mservais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	printf/ft_format_cspm.c \
					printf/ft_format_diuxx.c \
					printf/ft_parse.c \
					printf/ft_printf.c

OBJ_FILES		= $(SRC_FILES:.c=.o)

NAME			= libftprintf.a

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror -Iinclude/


all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(MAKE) -s -C libft
	cp libft/libft.a $(NAME)
	ar -rcs $@ $^

bonus: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(OBJ_FILES_BONUS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
