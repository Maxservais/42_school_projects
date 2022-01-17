# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mservais <mservais@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 16:34:31 by mservais          #+#    #+#              #
#    Updated: 2021/11/08 15:50:34 by mservais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	push_swap.c		\
					operations.c	\
					sort_small.c	\
					sort_large.c	\
					quick_sort.c	\
					init.c			\
					helper_1.c		\
					helper_2.c		\
					error.c			\
					free.c
					
OBJ_FILES		=	$(SRC_FILES:.c=.o)

NAME			=	push_swap

PUSHSWAP_LIB	=	libpushswap.a

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(MAKE) -s -C libft
	cp libft/libft.a $(PUSHSWAP_LIB)
	ar -rcs $(PUSHSWAP_LIB) $^
	$(CC) $(CFLAGS) $(PUSHSWAP_LIB) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) 
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(PUSHSWAP_LIB)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
