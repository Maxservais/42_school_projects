# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mservais <mservais@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 11:47:14 by mservais          #+#    #+#              #
#    Updated: 2021/10/05 11:29:08 by mservais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	pipex.c \
					error.c \
					utils.c
					

SRC_FILES_BONUS	=	pipex_bonus.c \
					error_bonus.c \
					utils_bonus.c

OBJ_FILES		=	$(SRC_FILES:.c=.o)

OBJ_FILES_BONUS	=	$(SRC_FILES_BONUS:.c=.o)

NAME			=	pipex

PIPEX_LIB		=	libpipex.a

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(MAKE) -s -C libft
	cp libft/libft.a $(PIPEX_LIB)
	ar -rcs $(PIPEX_LIB) $^
	$(CC) $(CFLAGS) $(PIPEX_LIB) -o $(NAME)

bonus: $(OBJ_FILES_BONUS)
	@$(MAKE) -s -C libft
	cp libft/libft.a $(PIPEX_LIB)
	ar -rcs $(PIPEX_LIB) $^
	$(CC) $(CFLAGS) $(PIPEX_LIB) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(OBJ_FILES_BONUS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(PIPEX_LIB)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus