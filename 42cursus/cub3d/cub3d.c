/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:29:11 by joopark           #+#    #+#             */
/*   Updated: 2020/12/29 00:13:13 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int				ft_key_press(int code, t_canvas *obj)
{
	// 0x7b : <-
	// 0x7e : ^
	// 0x7d : _
	// 0x7c : ->
	// 0x35 : esc
	// w a s d : 0x0d 0 1 2
	t_vector		ray;
	printf("(%d, %d)\n", obj->player.x, obj->player.y);
	printf("code : %02x\n", code);
	if (code == 0x35)
		_Exit(0);
	else if (code == 0x7c)
		obj->player.x += (obj->width > obj->player.x) ? 5 : 0;
	else if (code == 0x7d)
		obj->player.y += (obj->height > obj->player.y) ? 5 : 0;
	else if (code == 0x7b)
		obj->player.x -= (0 < obj->player.x) ? 5 : 0;
	else if (code == 0x7e)
		obj->player.y -= (0 < obj->player.y) ? 5 : 0;
	else if (code == 0x00)
		obj->p.deg -= (0 < obj->p.deg) ? 1 : -360;
	else if (code == 0x02)
		obj->p.deg += (360 > obj->p.deg) ? 1 : -360;
	

	obj->p.pos = ft_vinit(((1.0 * obj->player.x) / obj->width) * obj->map.x,
						((1.0 * obj->player.y) / obj->height) * obj->map.y);
						
	// test
	
	ray = ft_vinit(1, 0);
	ray = ft_vspin(ray, obj->p.deg);
	printf("obj->player.deg : %d\n", obj->p.deg);
	obj->draw = 1;
	return (0);
}

int				ft_mouse_press(int code, int x, int y, char *str)
{
	printf("code : %02x(%d, %d) at %s\n", code, x, y, str);
	return (0);
}

int				ft_draw(t_canvas *obj)
{
	if (obj->draw == 1)
	{
		ft_rendering(obj);
		mlx_clear_window(obj->window, obj->canvas);
		mlx_put_image_to_window(obj->window, obj->canvas, obj->wallpaper.img, obj->wallpaper.x, obj->wallpaper.y);
		mlx_put_image_to_window(obj->window, obj->canvas, obj->img.img, obj->img.x + 800, obj->img.y);
		mlx_put_image_to_window(obj->window, obj->canvas, obj->player.img, obj->player.x + 800, obj->player.y);
		mlx_put_image_to_window(obj->window, obj->canvas, obj->render.img, obj->render.x, obj->render.y);
		obj->draw = 0;
	}
	return (0);
}

void			ft_event_register(void *window, t_canvas *obj)
{
	//mlx_key_hook(window, &ft_key_press, &obj->img);
	mlx_hook(window, 2, 0, &ft_key_press, obj);
	mlx_mouse_hook(window, &ft_mouse_press, "mouse");
	//mlx_expose_hook(window, &ft_test, "expose");
}

void			ft_draw_map_proto(t_canvas *area, t_map map)
{
	for (int i = 0; i < area->img.height; i++)
	{
		for (int j = 0; j < (area->img.size_line / 4); j++)
		{
			if (map.map[((map.y * i) / area->img.height)][((map.x * j) / area->img.width)] == 1)
				area->img.data[i * (area->img.size_line / 4) + j] = ft_rgba(0xff, 0, 0, 0);
			else
				area->img.data[i * (area->img.size_line / 4) + j] = 0x0000FF00;
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
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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

	w.width = 800;
	w.height = 800;
	w.window = mlx_init();
	w.canvas = mlx_new_window(w.window, w.width * 2, w.height, "hello😂");

	w.render.width = w.width;
	w.render.height = w.height;
	w.render.x = 0;
	w.render.y = 0;
	w.render.img = mlx_new_image(w.window, w.render.width, w.render.height);
	w.render.data = (int *)mlx_get_data_addr(w.render.img, &w.render.bits_per_pixel, &w.render.size_line, &w.render.endian);

	w.wallpaper.width = w.width;
	w.wallpaper.height = w.height;
	w.wallpaper.x = 0;
	w.wallpaper.y = 0;
	w.wallpaper.img = mlx_new_image(w.window, w.wallpaper.width, w.wallpaper.height);
	w.wallpaper.data = (int *)mlx_get_data_addr(w.wallpaper.img, &w.wallpaper.bits_per_pixel, &w.wallpaper.size_line, &w.wallpaper.endian);
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
	w.img.width = w.width;
	w.img.height = w.height;
	w.img.x = 0;
	w.img.y = 0;
	w.img.img = mlx_new_image(w.window, w.img.width, w.img.height);
	w.img.data = (int *)mlx_get_data_addr(w.img.img, &w.img.bits_per_pixel, &w.img.size_line, &w.img.endian);
	ft_draw_map_proto(&w, w.map);

	w.p.deg = 0;
	//w.player = ft_get_img_form_png(w.window, "./sprite/p.png");

	w.tmp[0] = ft_get_img_form_png(w.window, "./sprite/p.png");
	w.tmp[1] = ft_new_img(w.window, w.tmp[0].width * 0.02, w.tmp[0].height * 0.02);
	w.tmp[2] = ft_get_img_form_png(w.window, "./sprite/n.png");
	w.tmp[3] = ft_get_img_form_png(w.window, "./sprite/w.png");
	w.tmp[4] = ft_get_img_form_png(w.window, "./sprite/s.png");
	w.tmp[5] = ft_get_img_form_png(w.window, "./sprite/e.png");
	
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
	
	w.draw = 1;
	mlx_put_image_to_window(w.window, w.canvas, w.img.img, w.img.x, w.img.y);
	mlx_put_image_to_window(w.window, w.canvas, w.player.img, w.player.x, w.player.y);
	ft_event_register(w.canvas, &w);
	mlx_loop_hook(w.window, &ft_draw, &w);
	mlx_loop(w.window);
	return (0);
}