NAME = push_swap

NAME_B = checker

DIR_C = checkers/

SRCS = $(wildcard *.c)

SRCS_B = push_swap.c \
		 ft_atoi.c \
		 ft_error.c \
		 ft_error_utils.c \
		 $(DIR_C)rr.c \
		 $(DIR_C)r.c \
		 $(DIR_C)sp.c \
		 $(DIR_C)get_next_line.c \
		 $(DIR_C)get_next_line_utils.c \
		 $(DIR_C)main.c

OBJ = $(SRCS:.c=.o)

OBJ_B = $(SRCS_B:.c=.o)

INCLUDE = push_swap.h

FLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

CC = gcc

.c.o:
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(NAME_B):	$(OBJ_B)
	$(CC) $(FLAGS) $(OBJ_B) -o $(NAME_B)

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all
