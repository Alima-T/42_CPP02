# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 17:09:06 by aokhapki          #+#    #+#              #
#    Updated: 2025/07/25 18:12:39 by aokhapki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
NAME = fixed

# Files listed manually
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/Fixed.cpp
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/Fixed.o

# Compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

# Default target
all: $(NAME)

# Link executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
