FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCPATH = srcs
HEADERPATH = includes
SRCFILES = $(addprefix $(SRCPATH)/, $(FILES))
CFLAGS = -Wall -Wextra -Werror
COMPILER = gcc
OBJS = $(SRCFILES:.c=.o)
TARGET = libft.a

all: $(TARGET)

$(TARGET): $(OBJS)
	ar -crsv ${TARGET} $(OBJS)

%.o: %.c
	$(COMPILER) ${CFLAGS} -I${HEADERPATH} ${HEADERFILES} -c -o $@ $<

clean:
	rm $(OBJS) ${TARGET}

fclean:
	rm -f $(OBJS) ${TARGET}

re: fclean all