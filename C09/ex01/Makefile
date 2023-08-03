CCFLAGS = -Wall -Werror -Wextra
CC = gcc
SRC = srcs/ft_putchar.c   \
			srcs/ft_swap.c \
			srcs/ft_putstr.c\
			srcs/ft_strlen.c \
			srcs/ft_strcmp.c  \

INCLUDES = ./includes/ft.h
OBJ = $(SRC:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -I ./includes/ -c $< -o $@

clean:
	rm -f$(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all