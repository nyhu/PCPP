NAME = megaphone
CC = clang++
CFLAGS = -Wall -Wextra -Werror
SRC = megaphone.cpp

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

all: $(NAME)

re: fclean all

clean:

fclean: clean
	@rm -rf $(NAME)

.PHONY: re clean fclean all