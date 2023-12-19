SRC = src/main.c
OBJ = ${SRC:.c=.o}
GCC = gcc -Wall -Wextra -Werror
NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) 
	$(GCC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractol.h
	$(GCC) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all