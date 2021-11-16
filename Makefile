NAME = push_swap

SRCS = $(wildcard *.c)

OBJ = $(SRCS:.c=.o)

INCLUDE = push_swap.h

FLAGS = -Wall -Werror -Wextra

CC = gcc

.c.o:
	$(CC) -I $(INCLUDE) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
