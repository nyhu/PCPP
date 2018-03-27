NAME = megaphonebook
CC = clang++
CFLAGS = -Wall -Wextra -Werror
SRC = Contact.cpp main.cpp

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

all: $(NAME)

re: fclean all

clean:

fclean: clean
	@rm -rf $(NAME)

.PHONY: re clean fclean all