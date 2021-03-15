# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 19:03:14 by joopark           #+#    #+#              #
#    Updated: 2021/03/15 15:32:45 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSH_SWAP = push_swap
FILES_COM = ./common/ft_linked_list.c
FILES_COM += ./common/ft_strncmp.c
FILES_COM += ./common/ft_atoi.c
FILES_COM += ./common/ft_mem.c
FILES_COM += ./common/ft_string.c
FILES_COM += ./common/ft_get_next_line.c
FILES_COM += ./common/ft_lst_tools.c
FILES_COM += ./common/ft_deque_front.c
FILES_COM += ./common/ft_deque_back.c
FILES_COM += ./common/ft_stack_opration.c
FILES_COM += ./common/ft_stack_util.c
FILES_CHECKER = checker.c
FILES_PUSH_SWAP = push_swap.c
OBJS_COM = ${FILES_COM:%.c=%.o}
OBJS_CHECKER = ${FILES_CHECKER:%.c=%.o}
OBJS_PUSH_SWAP = ${FILES_PUSH_SWAP:%.c=%.o}
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER_COM = ./common

%.o: %.c
	$(COMPILER) ${CFLAGS} -I${HEADER_COM} -c -o $@ $<

$(NAME_CHECKER): $(OBJS_COM) $(OBJS_CHECKER)
	$(COMPILER) $(CFLAGS) $(OBJS_CHECKER) $(OBJS_COM) -I$(HEADER_COM) -o $(NAME_CHECKER)

$(NAME_PUSH_SWAP): $(OBJS_COM) $(OBJS_PUSH_SWAP)
	$(COMPILER) $(CFLAGS) $(OBJS_PUSH_SWAP) $(OBJS_COM) -I$(HEADER_COM) -o $(NAME_PUSH_SWAP)

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)

clean:
	rm -f $(OBJS_COM) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)

fclean: clean
	rm -f $(NAME_CHECKER) $(NAME_PUSH_SWAP)

re: fclean all