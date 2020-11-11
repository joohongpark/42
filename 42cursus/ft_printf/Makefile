# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 23:17:54 by joopark           #+#    #+#              #
#    Updated: 2020/11/10 18:09:09 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_libft.c ft_parser.c ft_printer.c ft_print_number.c
FILES += ft_printf.c ft_puts.c ft_util.c
OBJS = $(FILES:.c=.o)
NAME = libftprintf.a
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
HEADERPATH = ./


$(NAME):
	$(COMPILER) $(CFLAGS) -c $(FILES) -I${HEADERPATH}
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
