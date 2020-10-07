FILES = ft_memset.c	ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c
FILES += ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
FILES += ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c
FILES += ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
FILES += ft_substr.c ft_strjoin.c ft_strtrim.c
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