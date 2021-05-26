# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 11:32:15 by joopark           #+#    #+#              #
#    Updated: 2021/05/25 12:29:48 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = serialize
FILES = main.cpp Serialization.cpp
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