CC = gcc
NAME = do-op
SRC = ft_calc.c ft_utils.c
CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

fclean:
	rm -f $(NAME)

clean:
	rm $(NAME)

re: fclean all
