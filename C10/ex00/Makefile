CC = cc
FLAGS = -Wall -Werror -Wextra
SRC =	main.c    \
		ft_putstr.c\
		ft_putchar.c\

OBJ = $(SRC:.c=.o)
NAME = ./ft_display_file

all : BANNER $(NAME)

define banner

███████╗████████╗     ██████╗ ██╗███████╗██████╗ ██╗      █████╗ ██╗   ██╗     ███████╗██╗██╗     ███████╗
██╔════╝╚══██╔══╝     ██╔══██╗██║██╔════╝██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝     ██╔════╝██║██║     ██╔════╝
█████╗     ██║        ██║  ██║██║███████╗██████╔╝██║     ███████║ ╚████╔╝      █████╗  ██║██║     █████╗
██╔══╝     ██║        ██║  ██║██║╚════██║██╔═══╝ ██║     ██╔══██║  ╚██╔╝       ██╔══╝  ██║██║     ██╔══╝
██║        ██║███████╗██████╔╝██║███████║██║     ███████╗██║  ██║   ██║███████╗██║     ██║███████╗███████╗
╚═╝        ╚═╝╚══════╝╚═════╝ ╚═╝╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝

endef
export banner

BANNER:
	@printf "\033[1;32m$$banner\033[1;00m"
	@printf "\n"

$(NAME): $(OBJ)
	@echo "\033[1;31m[ Compiling... ]\033[1;00m"
	@$(CC) -o $(NAME) $(OBJ)
	@echo "\033[1;31m[ Compilation Complete ! ]\033[1;00m"

%.o : %.c
	@echo "\033[1;31m[ Transforming .c's into .o's... ]\033[1;00m"
	@$(CC) -o $@ -c $< $(FLAGS)
	@echo "\033[1;31m[ Transformation Complete ! ]\033[1;00m"

clean: BANNER
	@echo "\033[1;31m[ Cleaning .o's... ]\033[1;00m"
	@rm -f $(OBJ)
	@echo "\033[1;31m[ .o's Cleaned ! ]\033[1;00m"

fclean: BANNER clean
	@echo "\033[1;31m[ Cleaning Binaries... ]\033[1;00m"
	@rm -f $(NAME)
	@echo "\033[1;31m[ Binaries Cleaned ! ]\033[1;00m"

re: BANNER fclean all