/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:09:11 by joopark           #+#    #+#             */
/*   Updated: 2021/01/09 17:53:28 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	else if (ft_strncmp((const char *)line, "R ", 2) == 0)
		return (ft_set_screen(line + 2, canvas));
	else if (ft_strncmp((const char *)line, "F ", 2) == 0)
		return (ft_set_color(line + 2, canvas, 'F'));
	else if (ft_strncmp((const char *)line, "C ", 2) == 0)
		return (ft_set_color(line + 2, canvas, 'C'));
	else if (*line != '\0')
		return (ft_map(line, &canvas->map));
	return (1);
}

int					ft_open_texture(char *uri, t_img *img, void *window)
{
	int				fd;

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

int					ft_set_screen(char *line, t_canvas *canvas)
{
	if (line == NULL)
		return (-1);
	canvas->width = ft_atoi(line);
	line = ft_strnstr(line, " ", ft_strlen(line)) + 1;
	if (line == NULL)
		return (-1);
	canvas->height = ft_atoi(line);
	return (1);
}

int					ft_set_color(char *line, t_canvas *canvas, char c)
{
	int				r;
	int				g;
	int				b;

	if (line == NULL)
		return (-1);
	r = ft_atoi(line);
	line = ft_strnstr(line, ",", ft_strlen(line)) + 1;
	if (line == NULL)
		return (-1);
	g = ft_atoi(line);
	line = ft_strnstr(line, ",", ft_strlen(line)) + 1;
	if (line == NULL)
		return (-1);
	b = ft_atoi(line);
	if (c == 'F')
		canvas->floor_color = ft_rgba(r, g, b, 0x00);
	if (c == 'C')
		canvas->ceilling_color = ft_rgba(r, g, b, 0x00);
	return (1);
}