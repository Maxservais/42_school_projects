# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mservais <mservais@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 16:34:46 by mservais          #+#    #+#              #
#    Updated: 2022/02/10 15:23:53 by mservais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	megaphone

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC_FILES	=	megaphone.cpp

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

.PHONY: all fclean re