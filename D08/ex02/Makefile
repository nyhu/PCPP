NAME = Mutantstack

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Mutantstack.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	c++ $(CPPFLAGS) -I. -o $@ $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
