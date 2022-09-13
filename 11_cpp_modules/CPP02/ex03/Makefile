# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mservais <mservais@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 16:28:00 by mservais          #+#    #+#              #
#    Updated: 2022/02/16 17:01:10 by mservais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC_FILES	=	main.cpp		\
				Fixed.cpp		\
				Point.cpp		\
				bsp.cpp

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)

%.cpp: %.c
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
