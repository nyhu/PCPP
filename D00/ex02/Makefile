NAME = account
CC = clang++
FLAGS = -Wall -Wextra -Werror
SRC = tests.cpp	\
			Account.class.cpp
OBJ	=	$(SRC:.cpp=.o)
OS = $(shell uname -s)

ifeq ($(OS), Linux)
	FLAGS += -std=c++11
endif

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