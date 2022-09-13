# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mservais <mservais@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 16:47:24 by mservais          #+#    #+#              #
#    Updated: 2022/02/10 17:38:59 by mservais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	zombie

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC_FILES	=	main.cpp		\
				Zombie.cpp		\
				ZombieHorde.cpp

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