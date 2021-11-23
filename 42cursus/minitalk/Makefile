# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 09:21:36 by joopark           #+#    #+#              #
#    Updated: 2021/11/23 11:55:26 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
FILES_COM = ./utils.c
FILES_SERVER = server.c
FILES_CLIENT = client.c
OBJS_COM = ${FILES_COM:%.c=%.o}
OBJS_SERVER = ${FILES_SERVER:%.c=%.o}
OBJS_CLIENT = ${FILES_CLIENT:%.c=%.o}
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER_COM = ./

all: $(NAME_SERVER) $(NAME_CLIENT)

clean:
	rm -f $(OBJS_COM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

%.o: %.c
	$(COMPILER) ${CFLAGS} -I${HEADER_COM} -c -o $@ $<

$(NAME_SERVER): $(OBJS_COM) $(OBJS_SERVER)
	$(COMPILER) $(CFLAGS) $(OBJS_SERVER) $(OBJS_COM) -I$(HEADER_COM) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_COM) $(OBJS_CLIENT)
	$(COMPILER) $(CFLAGS) $(OBJS_CLIENT) $(OBJS_COM) -I$(HEADER_COM) -o $(NAME_CLIENT)

re: fclean all