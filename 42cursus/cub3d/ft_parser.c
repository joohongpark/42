/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:09:11 by joopark           #+#    #+#             */
/*   Updated: 2021/01/08 01:33:14 by joopark          ###   ########.fr       */
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

	bp = NULL;
	line = NULL;
	if((fd = open(dir, O_RDONLY)) < 0)
		return (-1);
	while ((r = ft_get_next_line(fd, &line, &bp)) > 0)
	{
		if (ft_line_paraer(line, canvas) < 0)
			return (-1);
		free(line);
		line = NULL;
	}
	if (ft_line_paraer(line, canvas) < 0)
		return (-1);
	free(line);
	close(fd);
	return (1);
}

int					ft_line_paraer(char *line, t_canvas *canvas)
{
	(void) canvas;
	(void) line;

	if (ft_strncmp((const char *)line, "NO ", 3) == 0)
		return (ft_open_texture(line + 3, &canvas->north_texture, canvas->window));
	else if (ft_strncmp((const char *)line, "SO ", 3) == 0)
		return (ft_open_texture(line + 3, &canvas->south_texture, canvas->window));
	else if (ft_strncmp((const char *)line, "WE ", 3) == 0)
		return (ft_open_texture(line + 3, &canvas->west_texture, canvas->window));
	else if (ft_strncmp((const char *)line, "EA ", 3) == 0)
		return (ft_open_texture(line + 3, &canvas->east_texture, canvas->window));
	else if (ft_strncmp((const char *)line, "S ", 2) == 0)
		return (ft_open_texture(line + 2, &canvas->sprite_texture, canvas->window));

	return (1);
}

int					ft_open_texture(char *uri, t_img *img, void *window)
{
	int				fd;

	(void) window;
	(void) img;
	printf("%s\n", uri);
	if((fd = open(uri, O_RDONLY)) < 0)
		return (-1);
	close(fd);

	if (ft_strncmp((const char *)uri + (ft_strlen(uri) - 3), "png", 3) == 0)
		*img = ft_get_img_from_png(window, uri);
	else if (ft_strncmp((const char *)uri + (ft_strlen(uri) - 3), "xpm", 3) == 0)
		*img = ft_get_img_from_xpm(window, uri);
	else
		return (-1);

	return (1);
}