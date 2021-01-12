/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:09:11 by joopark           #+#    #+#             */
/*   Updated: 2021/01/12 15:05:06 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int					ft_parser(char *dir, t_canvas *canvas)
{
	int				fd;
	char			*line;
	char			*bp;
	int				r;

	bp = NULL;
	line = NULL;
	if ((fd = open(dir, O_RDONLY)) < 0)
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

int					ft_line_paraer(char *line, t_canvas *c)
{
	if (ft_strncmp((const char *)line, "NO ", 3) == 0)
		return (ft_open_texture(line + 3, &c->north_texture, c->window));
	else if (ft_strncmp((const char *)line, "SO ", 3) == 0)
		return (ft_open_texture(line + 3, &c->south_texture, c->window));
	else if (ft_strncmp((const char *)line, "WE ", 3) == 0)
		return (ft_open_texture(line + 3, &c->west_texture, c->window));
	else if (ft_strncmp((const char *)line, "EA ", 3) == 0)
		return (ft_open_texture(line + 3, &c->east_texture, c->window));
	else if (ft_strncmp((const char *)line, "HUD ", 4) == 0)
		return (ft_open_texture(line + 4, &c->hud, c->window));
	else if (ft_strncmp((const char *)line, "S1 ", 3) == 0)
		return (ft_open_texture(line + 3, &c->sprite_texture[0], c->window));
	else if (ft_strncmp((const char *)line, "S2 ", 3) == 0)
		return (ft_open_texture(line + 3, &c->sprite_texture[1], c->window));
	else if (ft_strncmp((const char *)line, "S3 ", 3) == 0)
		return (ft_open_texture(line + 3, &c->sprite_texture[2], c->window));
	else if (ft_strncmp((const char *)line, "R ", 2) == 0)
		return (ft_set_screen(line + 2, c));
	else if (ft_strncmp((const char *)line, "F ", 2) == 0)
		return (ft_set_color(line + 2, c, 'F'));
	else if (ft_strncmp((const char *)line, "C ", 2) == 0)
		return (ft_set_color(line + 2, c, 'C'));
	else if (*line != '\0')
		return (ft_map(line, &c->map));
	return (1);
}

int					ft_open_texture(char *uri, t_img *img, void *window)
{
	int				fd;

	if ((fd = open(uri, O_RDONLY)) < 0)
		return (-1);
	close(fd);
	if (ft_strncmp((const char *)uri + (ft_strlen(uri) - 3), "png", 3) == 0)
		*img = ft_get_img_from_png(window, uri);
	else if (ft_strncmp((const char *)uri + (ft_strlen(uri) - 3),
			"xpm", 3) == 0)
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
