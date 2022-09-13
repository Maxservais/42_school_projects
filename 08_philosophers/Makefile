# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mservais <mservais@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 12:15:38 by mservais          #+#    #+#              #
#    Updated: 2021/12/07 12:03:53 by mservais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	main.c		\
					init.c		\
					actions.c	\
					time.c		\
					free.c		\
					utils.c		\

OBJ_FILES		=	$(SRC_FILES:.c=.o)

NAME			=	philo

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) ${SRC_FILES} -lpthread -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJ_FILES)
	@rm -rf *.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
