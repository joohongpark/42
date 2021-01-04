/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:29:11 by joopark           #+#    #+#             */
/*   Updated: 2021/01/04 15:13:46 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_draw_map_proto(t_canvas *area, t_map map)
{
	for (int i = 0; i < area->img.height; i++)
	{
		for (int j = 0; j < (area->img.size_line / 4); j++)
		{
			if (map.map[((map.y * i) / area->img.height)][((map.x * j) / area->img.width)] == 0)
				area->img.data[i * (area->img.size_line / 4) + j] = ft_rgba(0xff, 0, 0, 0);
			else if (map.map[((map.y * i) / area->img.height)][((map.x * j) / area->img.width)] == 1)
				area->img.data[i * (area->img.size_line / 4) + j] = ft_rgba(0, 0xff, 0, 0);
			else
				area->img.data[i * (area->img.size_line / 4) + j] = ft_rgba(0, 0, 0xff, 0);
		}
	}
}

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

int				main(void)
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
	int			cx, cy;

	ft_map_gen_proto(&(w.map), 20, 20);
	for (int i = 0; i < w.map.y; i++)
		for (int j = 0; j < w.map.x; j++)
			w.map.map[i][j] = map[i][j];

	w.p.cam = ft_vinit(1, 0);
	w.p.plane = ft_vinit(0, 0.56);
	w.p.pos = ft_vinit(1.1, 1.1);

	w.width = 800;
	w.height = 800;
	w.window = mlx_init();
	w.canvas = mlx_new_window(w.window, w.width * 2, w.height, "hello😂");

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
	w.img = ft_new_img(w.window, w.width, w.height);
	ft_draw_map_proto(&w, w.map);

	w.p.deg = 0;
	//w.player = ft_get_img_form_png(w.window, "./sprite/p.png");

	w.tmp[0] = ft_get_img_from_png(w.window, "./sprite/p.png");
	w.tmp[1] = ft_new_img(w.window, w.tmp[0].width * 0.02, w.tmp[0].height * 0.02);
	w.tmp[2] = ft_get_img_from_png(w.window, "./sprite/n.png");
	w.tmp[3] = ft_get_img_from_png(w.window, "./sprite/w.png");
	w.tmp[4] = ft_get_img_from_png(w.window, "./sprite/s.png");
	w.tmp[5] = ft_get_img_from_png(w.window, "./sprite/e.png");
	w.tmp[6] = ft_get_img_from_png(w.window, "./sprite/d.png");
	
	for (int i = 0; i < w.tmp[1].height; i++)
	{
		for (int j = 0; j < (w.tmp[1].size_line / 4); j++)
		{
			cx = j * w.tmp[0].width / w.tmp[1].width;
			cy = i * w.tmp[0].height / w.tmp[1].height;
			w.tmp[1].data[i * (w.tmp[1].size_line / 4) + j] = w.tmp[0].data[cy * (w.tmp[0].size_line / 4) + cx];
		}
	}
	w.player = w.tmp[1];

	w.sprite_rander = ft_new_img(w.window, w.width, w.height);
	
	w.draw = 1;
	mlx_put_image_to_window(w.window, w.canvas, w.img.img, w.img.x, w.img.y);
	mlx_put_image_to_window(w.window, w.canvas, w.player.img, w.player.x, w.player.y);
	ft_event_register(w.canvas, &w);
	mlx_loop_hook(w.window, &ft_draw, &w);
	mlx_loop(w.window);
	return (0);
}