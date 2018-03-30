NAME = wastland

CPPFLAGS = -Wall -Wextra -Werror -g

SRC = main.cpp AWeapon.cpp Character.cpp \
	Enemy.cpp PlasmaRifle.cpp PowerFist.cpp RadScorpion.cpp \
	SuperMutant.cpp

OBJ = $(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ}
	c++ ${CPPFLAGS} -I. -o $@ ${OBJ}

clean:
	@/bin/rm -f ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all
