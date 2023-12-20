# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 23:32:58 by zelhajou          #+#    #+#              #
#    Updated: 2023/12/20 00:00:05 by zelhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE_FILES = src/main.c
OBJECT_FILES = $(SOURCE_FILES:src/%.c=obj/%.o)
COMPILER_FLAGS = cc -fsanitize=address -Wall -Wextra -Werror -I include -I lib/ft_printf 
LINKER_FLAGS = -L lib/ft_printf -lftprintf -lmlx -framework OpenGL -framework AppKit
EXECUTABLE_NAME = fractol
PRINTF_LIB = lib/ft_printf/libftprintf.a

all: $(PRINTF_LIB) $(EXECUTABLE_NAME)

$(PRINTF_LIB):
	make -C lib/ft_printf

$(EXECUTABLE_NAME): $(OBJECT_FILES)
	$(COMPILER_FLAGS) $(OBJECT_FILES) $(LINKER_FLAGS) -o $(EXECUTABLE_NAME)

obj/%.o: src/%.c
	mkdir -p obj
	$(COMPILER_FLAGS) -c $< -o $@

bonus: all

clean:
	rm -rf obj
	make -C lib/ft_printf clean

fclean: clean
	rm -rf $(EXECUTABLE_NAME)
	make -C lib/ft_printf fclean

re: fclean all