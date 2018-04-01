NAME = ft_retro
CC = clang++
FLAGS = -Wall -Wextra -Werror 
SRC = main.cpp \
	game/Game.cpp \
	display/Display.cpp \
	entity/background.cpp \
	entity/player/Player.cpp \
	entity/ships/AShip.cpp \
	entity/enemy/EnemyFactory.cpp \
	entity/enemy/EnemyList.cpp \
	entity/enemy/units/Fighter.cpp \
	entity/bullets/BulletList.cpp
OBJ	= $(SRC:.cpp=.o)
OS = $(shell uname -s)
LIBS = -lncurses

ifeq ($(OS), Linux)
	FLAGS += -std=c++11
else
	FLAGS += -std=c++98
endif

all: $(NAME)

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(LIBS) $(OBJ)


re: fclean all

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

.PHONY: re clean fclean all
