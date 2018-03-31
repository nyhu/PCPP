NAME = spaceMarines

CPPFLAGS = -Wall -Wextra -Werror -g

SRC = main.cpp AssaultTerminator.cpp Squad.cpp \
	TacticalMarine.cpp

OBJ = $(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ}
	c++ ${CPPFLAGS} -I. -o $@ ${OBJ}

clean:
	@/bin/rm -f ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all
