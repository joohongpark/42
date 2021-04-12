# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 12:03:14 by joopark           #+#    #+#              #
#    Updated: 2021/04/11 21:46:25 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
FILES_COM =ft_arg_parser.c
FILES = philo_one.c
OBJS_COM = ${FILES_COM:%.c=%.o}
OBJS = ${FILES:%.c=%.o}
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
CLIBS = -lpthread
HEADER = ./

all: $(NAME)

clean:
	rm -f $(OBJS_COM) $(OBJS)

fclean: clean
	rm -f $(NAME)

%.o: %.c
	$(COMPILER) $(CFLAGS) -I$(HEADER) -c -o $@ $<

$(NAME): $(OBJS) $(OBJS_COM)
	$(COMPILER) $(CFLAGS) $(CLIBS) $(OBJS) $(OBJS_COM) -I$(HEADER) -o $(NAME)

re: fclean all