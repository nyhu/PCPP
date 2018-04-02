NAME = bureau
CC = clang++
FLAGS = -Wall -Wextra -Werror
SRC = main.cpp Bureaucrat.cpp Form.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp
OBJ	= $(SRC:.cpp=.o)

OS = $(shell uname -s)

ifeq ($(OS), Linux)
	FLAGS += -D LINUX
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

.PHONY: re clean fclean all%