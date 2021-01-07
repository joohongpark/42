/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:09:11 by joopark           #+#    #+#             */
/*   Updated: 2021/01/07 20:56:47 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int					ft_parser(char *dir, t_canvas *canvas)
{
	int				fd;
	char			*line;
	char			*bp;
	int				r;

	(void) canvas;
	if((fd = open(dir, O_RDONLY)) < 0)
		return (-1);
	
	line = NULL;
	bp = NULL;
	while ((r = ft_get_next_line(fd, &line, &bp)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	free(line);
	return (fd);
}
