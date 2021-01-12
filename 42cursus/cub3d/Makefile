# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 19:03:14 by joopark           #+#    #+#              #
#    Updated: 2021/01/12 02:16:52 by joopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = cub3d.c
FILES += ft_wall.c ft_rendering.c ft_imgutil.c ft_lifo.c ft_events.c ft_move.c
FILES += ft_vector.c ft_vector_trigonometry.c
FILES += ft_raycasting.c ft_checkroom.c ft_dda_modules.c
FILES += ft_arg.c ft_parser.c ft_get_next_line.c ft_map.c ft_map_vaild_check.c
FILES += ft_bmp.c
FILES += ft_keys.c
FILES_BONUS = cub3d_bonus.c
FILES_BONUS += ft_wall_bonus.c ft_rendering_bonus.c ft_imgutil_bonus.c ft_lifo_bonus.c ft_events_bonus.c ft_move_bonus.c
FILES_BONUS += ft_vector_bonus.c ft_vector_trigonometry_bonus.c
FILES_BONUS += ft_raycasting_bonus.c ft_checkroom_bonus.c ft_dda_modules_bonus.c
FILES_BONUS += ft_arg_bonus.c ft_parser_bonus.c ft_get_next_line_bonus.c ft_map_bonus.c ft_map_vaild_check_bonus.c
FILES_BONUS += ft_bmp_bonus.c
FILES_BONUS += ft_keys_bonus.c
FILES_BONUS += ft_forbonus_bonus.c
OBJS = ${FILES:%.c=%.o}
OBJS_BONUS = ${FILES_BONUS:%.c=%.o}
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
	$(COMPILER) $(CFLAGS) $(OBJS) -I$(HEADERPATH) -I${MMSPATH} -I${LIBFTPATH} -L$(MMSPATH) -L$(LIBFTPATH) $(CLFLAGS) -o $(NAME)
	cp $(MMSPATH)/libmlx.dylib $(HEADERPATH)

%.o: %.c
	$(COMPILER) ${CFLAGS} -I${HEADERPATH} -I${MMSPATH} -I${LIBFTPATH} -c -o $@ $<

all: $(NAME)

bonus: $(OBJS_BONUS)
	make all -C ${MMSPATH}
	make bonus -C ${LIBFTPATH}
	$(COMPILER) $(CFLAGS) $(FILES_BONUS) -I$(HEADERPATH) -I${MMSPATH} -I${LIBFTPATH} -L$(MMSPATH) -L$(LIBFTPATH) $(CLFLAGS) -o $(NAME)
	cp $(MMSPATH)/libmlx.dylib $(HEADERPATH)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	make clean -C ${MMSPATH}
	make fclean -C ${LIBFTPATH}
	rm -f $(NAME)
	rm -f libmlx.dylib

re: fclean all

.PHONY: clean fclean
