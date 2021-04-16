# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 12:03:14 by joopark           #+#    #+#              #
#    Updated: 2021/04/16 23:54:35 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
FILES_COM = ft_arg_parser.c ft_timer.c ft_printer.c
FILES = philo_one.c ft_philospher.c ft_fork.c ft_watchdog.c
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