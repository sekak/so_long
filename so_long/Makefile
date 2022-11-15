
NAME = so_long
Header = so_long.h

FILES = so_long.c get_next_line.c get_next_line_utils.c ft_copy_str.c ft_calloc.c shortcat.c  printf/printf.c printf/func1.c printf/func2.c check.c keyhook.c ft_ft_strnstr.c

FILES_O = $(FILES:.c=.o)

%.o: %.c
	gcc -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(FILES_O)
		gcc $(FILES_O) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(Files_O)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re 