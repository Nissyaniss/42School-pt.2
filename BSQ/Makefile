# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 13:12:35 by yalasbor          #+#    #+#              #
#    Updated: 2023/08/02 20:41:20 by yalasbor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC = 	main.c           \
		parsing.c         \
		solver.c           \
		map_checker.c       \
		utils/ft_atoi.c      \
		utils/ft_openfile.c   \
		utils/ft_putchar.c     \
		utils/ft_putstr.c       \
		utils/ft_str_char_cat.c  \
		utils/ft_strlen.c         \

INCLUDES = header.h
OBJ = $(SRC:.c=.o)
NAME = ./bsq

define banner

██████╗ ███████╗ ██████╗
██╔══██╗██╔════╝██╔═══██╗
██████╔╝███████╗██║   ██║
██╔══██╗╚════██║██║▄▄ ██║
██████╔╝███████║╚██████╔╝
╚═════╝ ╚══════╝ ╚══▀▀═╝

endef
export banner

all : BANNER $(NAME)

BANNER:
	@printf "\033[1;96m$$banner\033[1;00m"

$(NAME): $(OBJ)
	@echo "\033[1;91m[ Building Files... ]\033[1;00m"
	@$(CC) -o $(NAME) $(OBJ) -I $(INCLUDES)
	@rm *.o
	@rm utils/*.o
	@echo "\033[1;91m[ Build Finished! ]\033[1;00m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[1;91m[ Cleaning Object Files... ]\033[1;00m"
	@rm -f $(OBJ)
	@echo "\033[1;91m[ Object Files Cleaned! ]\033[1;00m"

fclean: clean
	@echo "\033[1;91m[ Cleaning Binaries Files... ]\033[1;00m"
	@rm -f $(NAME)
	@echo "\033[1;91m[ Binaries Files Cleaned! ]\033[1;00m"

re: fclean all
