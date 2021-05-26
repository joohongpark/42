# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 12:03:14 by joopark           #+#    #+#              #
#    Updated: 2021/05/25 00:37:44 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = convert
FILES = main.cpp Convert.cpp Print.cpp
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
	$(COMPILER) $(CFLAGS) -I$(HEADER) -c -o $@ $<

$(TARGET): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -I$(HEADER) -o $(TARGET)

re: fclean all