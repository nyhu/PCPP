NAME = pony
CC = clang++
FLAGS = -Wall -Wextra -Werror
SRC = main.cpp Pony.cpp
OBJ	= $(SRC:.cpp=.o)

all: $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ)

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAGS)

re: fclean all

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

.PHONY: re clean fclean all