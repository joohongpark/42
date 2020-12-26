# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 19:03:14 by joopark           #+#    #+#              #
#    Updated: 2020/12/26 16:50:22 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = cub3d.c ft_vector.c ft_raycasting.c ft_wall.c
#OBJS = $(FILES:.c=.o)
OBJS = ${FILES:%.c=%.o}
NAME = cub3d
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
CLFLAGS = -lmlx -framework OpenGL -framework AppKit -lz
HEADERPATH = ./
MMSPATH = ./libs/minilibx_mms_20200219
#MMSPATH = ./libs/minilibx

$(NAME): $(OBJS)
	make all -C ${MMSPATH}
	$(COMPILER) $(CFLAGS) $(OBJS) -I$(HEADERPATH) -L$(MMSPATH) $(CLFLAGS) -g -o $(NAME)
	#install_name_tool -add_rpath $(MMSPATH)/libmlx.dylib  $(NAME)
	cp $(MMSPATH)/libmlx.dylib $(HEADERPATH)

%.o: %.c
	$(COMPILER) ${CFLAGS} -I${HEADERPATH} -I${MMSPATH} -g -c -o $@ $<

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	make clean -C ${MMSPATH}
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
