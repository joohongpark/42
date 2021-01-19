FILES = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(FILES:.s=.o)
NAME = libasm.a
ASMCOMPILER = /Users/joohongpark/Downloads/nasm-2.15.05/nasm
#ASMCOMPILER = nasm
CFLAGS = -Wall -Wextra -Werror
HEADERPATH = ./
ASMFLAGS = -fmacho64
ASMLIB = asm
ASMLIBPATH = ./

test:
	gcc $(CFLAGS) $(OBJS) -I$(HEADERPATH) -l$(ASMLIB) -L$(ASMLIBPATH) test.c -o test

%.o: %.s
	$(ASMCOMPILER) $(ASMFLAGS) $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

.PHONY: clean fclean
