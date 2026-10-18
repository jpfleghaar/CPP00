# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 04:17:19 by jpflegha          #+#    #+#              #
#    Updated: 2025/11/27 04:17:21 by jpflegha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++17
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean

	rm -f $(NAME)
re: fclean all

