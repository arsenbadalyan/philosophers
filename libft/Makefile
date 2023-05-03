# Variables
NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rc
RUN = ranlib
LIBS   = -I ../philo/includes

# Source Files
SRC = $(wildcard *.c)

# Object Files
OBJ = $(patsubst %.c, %.o, $(SRC))

# Colors
RESET  = \033[0m
GREEN  = \033[32m
BLUE   = \033[34m

# Rules
all: $(NAME)
	@echo > /dev/null

$(NAME): Makefile $(OBJ)
	@$(AR) $@ $(OBJ)
	@$(RUN) $@

%.o: %.c ../philo/includes/libft.h
	@echo "${BLUE}Compiling $<${RESET}"
	@$(CC) $(FLAGS) $(LIBS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re