# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 22:19:38 by zelhajou          #+#    #+#              #
#    Updated: 2023/12/28 22:19:47 by zelhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = fractol

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Source and Object files
SRC = $(SRC_DIR)/graphics.c $(SRC_DIR)/main.c $(SRC_DIR)/events.c $(SRC_DIR)/drawing.c \
		$(SRC_DIR)/rendering.c $(SRC_DIR)/coloring.c
		
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) 
LIBS = -lmlx -framework OpenGL -framework AppKit

# Compilation rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/fractol.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Targets
all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
