FILES = ft_memset.c	ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c
FILES += ft_substr.c
OBJS = $(FILES:.c=.o)
TARGET = libft.a
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror -O3
LDFLAGS=-L.
LDLIBS=-lft
HEADERPATH = includes


$(TARGET): includes/libft.h
	$(COMPILER) $(CFLAGS) -c $(FILES) -I${HEADERPATH}
	ar rc $(TARGET) $(OBJS)
	ranlib $(TARGET)

all: $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: clean fclean