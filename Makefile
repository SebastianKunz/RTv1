##################################### GENERAL ##################################

NAME = RTv1

FLAGS = -Wall -Wextra #-Werror #-fsanitize=address -g

SRC_DIR = ./src/

SRC = main.c rgba.c ray.c sphere.c screen.c camera.c

###################################### OBJECTS #################################

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

################################ LIBRARIES - FRAMEWORK #########################

SDL_PATH = ~/homebrew/Cellar/sdl2/2.0.9_1/lib

SDL_LIB = -L $(SDL_PATH)/ -l SDL2

LIB_DIR = ./libraries

VECTOR_PATH = $(LIB_DIR)/vector3

VECTOR_LIB = -L $(VECTOR_PATH) -l vector3

VECTOR_INC = -I $(VECTOR_PATH)/includes

###################################### HEADERS #################################

INC_DIR = ./includes/

INC = -I $(INC_DIR)

###############################  COLORS AND TEXT  ##############################

#COLORS
COM_COLOR   = \033[0;33m
NO_COLOR    = \033[m

#TEXT
COM_STRING  = "$(NAME) Compilation Successful"
CLEAN_OBJ	= "Cleaned $(NAME) Objects"
CLEAN_NAME	= "Cleaned $(NAME) Binary"

######################################## RULES #################################

all: lib obj $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $^ -lSDL2 -lSDL2main $(VECTOR_LIB) -lm -o $@
	@echo "$(COM_COLOR)$(COM_STRING)$(NO_COLOR)"

#OBJECTS

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAGS) $(INC) $(VECTOR_INC) -g -c $< -o $@

obj:
	@mkdir $(OBJ_DIR)

lib:
	@make -C $(VECTOR_PATH) all

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(COM_COLOR)$(CLEAN_OBJ)$(NO_COLOR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(COM_COLOR)$(CLEAN_NAME)$(NO_COLOR)"

re: fclean all