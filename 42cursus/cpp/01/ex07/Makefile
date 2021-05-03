# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 12:03:14 by joopark           #+#    #+#              #
#    Updated: 2021/05/03 16:32:36 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = replace
FILES = main.cpp Replace.cpp
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