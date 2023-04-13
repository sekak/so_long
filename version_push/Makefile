NAME = push_swap
Header = push_swap.h

FILE = push_swap.c utils.c  
libft = libft/libft.a

OBJ = $(FILE:.c=.o)

CC = cc

CFLAGS = -Wall 

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(libft):
	make bonus -C libft

$(NAME): $(OBJ) $(libft)
	$(CC) $(CFLAGS) $(OBJ) $(libft) -o $(NAME)


clean:
	rm -rf $(OBJ) libft/*.o

fclean: clean 
	rm -rf $(NAME) libft/libft.a

re: fclean $(NAME)

.PHONY: re fclean clean all