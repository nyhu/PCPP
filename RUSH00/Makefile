NAME = ft_retro
CC = clang++
FLAGS = -Wall -Wextra -Werror 
SRC = main.cpp game/Game.cpp display/Display.cpp
OBJ	= $(SRC:.cpp=.o)

all: $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) -lncurses

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAGS)

re: fclean all

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

.PHONY: re clean fclean all