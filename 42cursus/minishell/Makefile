# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 01:43:43 by joopark           #+#    #+#              #
#    Updated: 2021/02/09 01:45:18 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = minishell.c
OBJS = ${FILES:%.c=%.o}
NAME = minishell
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
CLFLAGS = -lft
HEADERPATH = ./
LIBFTPATH = ./libs/libft

$(NAME): $(OBJS)
	make bonus -C ${LIBFTPATH}
	$(COMPILER) $(CFLAGS) $(OBJS) -I$(HEADERPATH) -I${LIBFTPATH} -L$(LIBFTPATH) $(CLFLAGS) -o $(NAME)

%.o: %.c
	$(COMPILER) ${CFLAGS} -I${HEADERPATH} -I${LIBFTPATH} -c -o $@ $<

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C ${LIBFTPATH}
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
