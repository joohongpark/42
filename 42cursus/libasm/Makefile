FILES = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
FILES_BONUS = ft_atoi_base.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s
OBJS = $(FILES:.s=.o)
OBJS_BONUS = $(FILES_BONUS:.s=.o)
NAME = libasm.a
#ASMCOMPILER = /Users/joohongpark/Downloads/nasm-2.15.05/nasm
ASMCOMPILER = nasm
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
HEADERPATH = ./
ASMFLAGS = -fmacho64
ASMLIB = asm
ASMLIBPATH = ./

test:
	gcc $(CFLAGS) -I$(HEADERPATH) -l$(ASMLIB) -L$(ASMLIBPATH) test.c -o test

testbonus:
	gcc $(CFLAGS) -I$(HEADERPATH) -l$(ASMLIB) -L$(ASMLIBPATH) test_bonus.c -o test

%.o: %.s
	$(ASMCOMPILER) $(ASMFLAGS) $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

.PHONY: clean fclean
