# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 19:03:14 by joopark           #+#    #+#              #
#    Updated: 2021/03/09 23:18:43 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET_CHECKER = checker
TARGET_PUSH_SWAP = push_swap
FILES_COM = ./common/ft_queue.c
FILES_CHECKER = checker.c
FILES_PUSH_SWAP = push_swap.c
OBJS_COM = ${FILES_COM:%.c=%.o}
OBJS_CHECKER = ${FILES_CHECKER:%.c=%.o}
OBJS_PUSH_SWAP = ${FILES_PUSH_SWAP:%.c=%.o}
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
CLFLAGS = -lft
HEADER_COM = ./common
LIBFTPATH = ./libft

%.o: %.c
	$(COMPILER) ${CFLAGS} -I${HEADER_COM} -I${LIBFTPATH} -c -o $@ $<

all: $(OBJS_COM) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)
	make bonus -C ${LIBFTPATH}
	$(COMPILER) $(CFLAGS) $(CLFLAGS) $(OBJS_CHECKER) $(OBJS_COM) -I$(HEADER_COM) -I${LIBFTPATH} -L$(LIBFTPATH) -o $(TARGET_CHECKER)
	$(COMPILER) $(CFLAGS) $(CLFLAGS) $(OBJS_PUSH_SWAP) $(OBJS_COM) -I$(HEADER_COM) -I${LIBFTPATH} -L$(LIBFTPATH) -o $(TARGET_PUSH_SWAP)

clean:
	make clean -C ${LIBFTPATH}
	rm -f $(OBJS_COM) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)

fclean: clean
	make fclean -C ${LIBFTPATH}
	rm -f $(TARGET_CHECKER) $(TARGET_PUSH_SWAP)

re: fclean all