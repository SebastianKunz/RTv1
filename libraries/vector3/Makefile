INC = -I ./includes/

V_SRC = new_vector3.c add_vector3.c sub_vector3.c scale_vector3.c dot_vector3.c

V_DIR = ./src/

OBJ_DIR = ./.obj/

FLAGS = -Wall -Wextra -Werror

NAME = libvector3.a

V_OBJ = $(addprefix $(OBJ_DIR), $(V_SRC:.c=.o))

#TEST

TEST_NAME = test-vector3

TEST_DIR = ./tests/

TEST_SRC_DIR = $(TEST_DIR)src/

TEST_INC = -I $(TEST_DIR)includes

TEST_SRC = test_main.c test_new_vector3.c test_sub_vector3.c test_add_vector3.c \
			test_scale_vector3.c test_dot_vector3.c

TEST_OBJ = $(addprefix $(OBJ_DIR), $(TEST_SRC:.c=.o))

###

#COLORS

COM_COLOR   = \033[0;32m
NO_COLOR    = \033[m

#TEXT
COM_STRING  = "$(NAME) Compilation Successful"
CLEAN_OBJ	= "Cleaned $(NAME) Objects"
CLEAN_NAME	= "Cleaned $(NAME)"

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(V_OBJ)
	ar rc $@ $^
	@ranlib $@
	@echo "$(COM_COLOR)$(COM_STRING)$(NO_COLOR)"

$(OBJ_DIR)%.o: $(V_DIR)%.c
	gcc $(FLAGS) $(INC) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(COM_COLOR)$(CLEAN_OBJ)$(NO_COLOR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(Q_NAME)
	@echo "$(COM_COLOR)$(CLEAN_NAME)$(NO_COLOR)"

test: all $(TEST_OBJ)
	@gcc $(FLAGS) $(TEST_OBJ) libvector3.a -o $(TEST_NAME)
	./$(TEST_NAME)

$(OBJ_DIR)%.o: $(TEST_SRC_DIR)%.c
	@gcc $(FLAGS) $(TEST_INC) $(INC) -c $< -o $@

re: fclean all
