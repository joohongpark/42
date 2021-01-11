# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 19:03:14 by joopark           #+#    #+#              #
#    Updated: 2021/01/11 14:54:52 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = cub3d.c
FILES += ft_wall.c ft_rendering.c ft_imgutil.c ft_lifo.c ft_events.c ft_move.c
FILES += ft_vector.c ft_vector_trigonometry.c
FILES += ft_raycasting.c ft_checkroom.c ft_dda_modules.c
FILES += ft_arg.c ft_parser.c ft_get_next_line.c ft_map.c ft_map_vaild_check.c
FILES += ft_bmp.c
FILES += ft_keys.c
OBJS = ${FILES:%.c=%.o}
NAME = cub3d
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
CLFLAGS = -lft -lmlx
HEADERPATH = ./
MMSPATH = ./libs/minilibx_mms_20200219
LIBFTPATH = ./libs/libft

$(NAME): $(OBJS)
	make all -C ${MMSPATH}
	make bonus -C ${LIBFTPATH}
	$(COMPILER) $(CFLAGS) $(OBJS) -I$(HEADERPATH) -L$(MMSPATH) -L$(LIBFTPATH) $(CLFLAGS) -o $(NAME)
	cp $(MMSPATH)/libmlx.dylib $(HEADERPATH)

%.o: %.c
	$(COMPILER) ${CFLAGS} -I${HEADERPATH} -I${MMSPATH} -I${LIBFTPATH} -c -o $@ $<

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	make clean -C ${MMSPATH}
	make fclean -C ${LIBFTPATH}
	rm -f $(NAME)
	rm -f libmlx.dylib

re: fclean all

.PHONY: clean fclean
