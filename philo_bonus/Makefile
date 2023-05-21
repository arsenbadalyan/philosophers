# Main Variables
NAME     = philo_bonus
GCC      = clang
CFLAGS   = -Wall -Wextra -Werror
RM       = rm -rf
OUTPUT   = ./$(NAME)
LIBS     = -I./includes/
LIBS_DIR = includes

# Compiled directories
SRC = src
OBJ = obj
SUBDIRS = main utils

# Folder directions
SRC_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(SRC)/, $(dir)))
OBJ_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(OBJ)/, $(dir)))

# File directions
SRCS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJS = $(subst $(SRC), $(OBJ), $(SRCS:.c=.o))
LIB_DIR = $(foreach dir, $(LIBS_DIR), $(wildcard $(dir)/*.h))

# Colors
RESET  = \033[0m
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m

all: $(NAME)
	@echo > /dev/null

$(NAME): $(LIB_DIR) Makefile $(OBJS)
	@make WAIT_COMPILE_MSG
	@$(GCC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIBS)
	@make DONE_MSG

$(OBJ)/%.o: $(SRC)/%.c $(LIB_DIR)
	@mkdir -p $(OBJ) $(OBJ_DIR)
	@echo "${YELLOW}Compiling $<${RESET}"
	@$(GCC) $(CFLAGS) $(LIBS) -c $< -o $@

clean: DELETE_OBJ_MSG
	@$(RM) $(OBJ)
fclean: clean DELETE_PROGRAM_MSG
	@$(RM) $(NAME)
re: fclean all

# Helper messages
WAIT_COMPILE_MSG:
	@echo "${YELLOW}Please wait until program compiling...${RESET}"
DONE_MSG:
	@echo "${GREEN}! run ./${NAME} to start program !${RESET}"
DELETE_OBJ_MSG:
	@echo "${RED}Object files deleting...${RESET}"
DELETE_PROGRAM_MSG:
	@echo "${RED}! ATTENTION !\n${NAME} is deleting...${RESET}"

.PHONY: all clean fclean re