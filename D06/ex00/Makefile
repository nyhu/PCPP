NAME = Scalar

CPPFLAGS = -Wall -Wextra -Werror 

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

OS = $(shell uname -s)

ifeq ($(OS), Linux)
	CPPFLAGS += -std=c++11
else
	CPPFLAGS += -std=c++98
endif


all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	c++ $(CPPFLAGS) -I. -o $@ $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
