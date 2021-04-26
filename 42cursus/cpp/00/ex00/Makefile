# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 12:03:14 by joopark           #+#    #+#              #
#    Updated: 2021/04/26 00:02:11 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = megaphone
FILES = megaphone.cpp
OBJS = ${FILES:%.cpp=%.o}
COMPILER = clang++
CFLAGS = -Wall -Wextra -Werror
HEADER = ./

all: $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -I$(HEADER) -o $(TARGET)

re: fclean all