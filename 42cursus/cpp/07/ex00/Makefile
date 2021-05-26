# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 16:10:50 by joopark           #+#    #+#              #
#    Updated: 2021/05/25 16:11:39 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = whatever
FILES = main.cpp
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