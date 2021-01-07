/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:29:11 by joopark           #+#    #+#             */
/*   Updated: 2021/01/08 01:40:58 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_map_gen_proto(t_map *map, int x, int y)
{
	int			i;

	i = 0;
	map->map = (char **) malloc(sizeof(char *) * y);
	while (i < x)
	{
		map->map[i] = (char *) malloc(sizeof(char) * x);
		i++;
	}
	map->x = x;
	map->y = y;
}

void			ft_canvas_init(t_canvas *canvas)
{
	canvas->width = 0;
	canvas->height = 0;
	canvas->map.map = NULL;
	canvas->map.x = 0;
	canvas->map.y = 0;
	canvas->ceilling_color = 0;
	canvas->floor_color = 0;
	canvas->north_texture.img = NULL;
	canvas->south_texture.img = NULL;
	canvas->west_texture.img = NULL;
	canvas->east_texture.img = NULL;
	canvas->sprite_texture.img = NULL;
	canvas->window = mlx_init();
}

int				main(int argc, char *argv[])
{
	char		map[20][20] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	t_canvas	w;

	ft_canvas_init(&w);
	if (ft_arg(&w, argc, argv) < 0)
	{
		write(1, "Error\n", ft_strlen("Error\n"));
		exit(-1);
	}
	ft_map_gen_proto(&(w.map), 20, 20);
	for (int i = 0; i < w.map.y; i++)
		for (int j = 0; j < w.map.x; j++)
			w.map.map[i][j] = map[i][j];

	w.width = 1280;
	w.height = 700;

	w.p.cam = ft_vinit(1, 0);
	w.p.plane = ft_vinit(0, (w.width / (w.height * 2.0)));
	w.p.pos = ft_vinit(1.1, 1.1);

	w.canvas = mlx_new_window(w.window, w.width, w.height, "hello😂");

	w.render = ft_new_img(w.window, w.width, w.height);
	w.wallpaper = ft_new_img(w.window, w.width, w.height);
	
	for (int i = 0; i < w.wallpaper.height; i++)
	{
		for (int j = 0; j < (w.wallpaper.size_line / 4); j++)
		{
			if (i < w.wallpaper.height / 2)
				w.wallpaper.data[i * (w.wallpaper.size_line / 4) + j] = ft_rgba(0x89, 0xde, 0xff, 0);
			else
				w.wallpaper.data[i * (w.wallpaper.size_line / 4) + j] = ft_rgba(0xac, 0x74, 0x30, 0);
		}
	}

	w.p.deg = 0;

	w.sprite_rander = ft_new_img(w.window, w.width, w.height);
	
	w.draw = 1;
	ft_event_register(w.canvas, &w);
	mlx_loop_hook(w.window, &ft_draw, &w);
	mlx_loop(w.window);
	return (0);
}