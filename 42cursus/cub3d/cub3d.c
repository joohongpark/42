/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:29:11 by joopark           #+#    #+#             */
/*   Updated: 2020/12/19 01:06:30 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int				_ux;
int				_uy;
int				_ux1;
int				_uy1;
t_map		m;
t_img		imgx, imgy;
int				ft_key_press(int code, t_canvas *obj)
{
	// 0x7b : <-
	// 0x7e : ^
	// 0x7d : _
	// 0x7c : ->
	// 0x35 : esc
	// w a s d : 0x0d 0 1 2
	t_vector		ray;
	double			d;
	printf("(%d, %d)\n", obj->player.x, obj->player.y);
	printf("code : %02x\n", code);
	if (code == 0x35)
		_Exit(0);
	else if (code == 0x7c)
		obj->player.x += (obj->width > obj->player.x) ? 10 : 0;
	else if (code == 0x7d)
		obj->player.y += (obj->height > obj->player.y) ? 10 : 0;
	else if (code == 0x7b)
		obj->player.x -= (0 < obj->player.x) ? 10 : 0;
	else if (code == 0x7e)
		obj->player.y -= (0 < obj->player.y) ? 10 : 0;
	else if (code == 0x00)
		obj->player.deg -= (0 < obj->player.deg) ? 1 : -360;
	else if (code == 0x02)
		obj->player.deg += (360 > obj->player.deg) ? 1 : -360;
	
	// test
	ray = ft_vinit(1, 0);
	ray = ft_vspin(ray, obj->player.deg);

	obj->player.pos = ft_vinit(((1.0 * obj->player.x) / obj->width) * 10,
						((1.0 * obj->player.y) / obj->height) * 10);
	printf("ray : (%f, %f)\n", ray.x, ray.y);
	printf("player.pos : (%f, %f)\n", obj->player.pos.x, obj->player.pos.y);
	d = ft_raycasting(obj->player.pos, ray, m);
	printf("beam : (%f)\n", d);
	printf("obj->player.deg : %d\n", obj->player.deg);
	printf("uxy : (%d, %d)\n", _ux, _uy);
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
		mlx_clear_window(obj->window, obj->canvas);
		mlx_put_image_to_window(obj->window, obj->canvas, obj->img.img, obj->img.x, obj->img.y);
		mlx_put_image_to_window(obj->window, obj->canvas, obj->player.img, obj->player.x, obj->player.y);
		mlx_put_image_to_window(obj->window, obj->canvas, imgx.img, _ux, _uy);
		mlx_put_image_to_window(obj->window, obj->canvas, imgy.img, _ux1, _uy1);
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
				area->img.data[i * (area->img.size_line / 4) + j] = 0x000000FF;
			else
				area->img.data[i * (area->img.size_line / 4) + j] = 0x0000FF00;
		}
	}
}

void			ft_map_gen_proto(t_map *map)
{
	map->map = (char **) malloc(sizeof(char *) * 10);
	for (size_t i = 0; i < 10; i++)
		map->map[i] = (char *) malloc(sizeof(char) * 10);
}

int				main(void)
{

	char		map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	t_canvas	w;

	ft_map_gen_proto(&m);
	for (size_t i = 0; i < 10; i++)
		for (size_t j = 0; j < 10; j++)
			m.map[i][j] = map[i][j];
	m.scale = 10;
	m.x = 10;
	m.y = 10;

	w.width = 800;
	w.height = 800;
	w.window = mlx_init();
	w.canvas = mlx_new_window(w.window, w.width, w.height, "hello");
	w.img.width = w.width;
	w.img.height = w.height;
	w.img.x = 0;
	w.img.y = 0;
	w.img.img = mlx_new_image(w.window, w.img.width, w.img.height);
	w.img.data = (int *)mlx_get_data_addr(w.img.img, &w.img.bits_per_pixel, &w.img.size_line, &w.img.endian);
	ft_draw_map_proto(&w, m);

	w.player.width = 20;
	w.player.height = 20;
	w.player.x = 0;
	w.player.y = 0;
	w.player.deg = 0;
	w.player.img = mlx_new_image(w.window, w.player.width, w.player.height);
	w.player.data = (int *)mlx_get_data_addr(w.player.img, &w.player.bits_per_pixel, &w.player.size_line, &w.player.endian);
	for (int i = 0; i < w.player.height; i++)
		for (int j = 0; j < (w.player.size_line / 4); j++)
			w.player.data[i * (w.player.size_line / 4) + j] = 0x0000FFFF;
	
	imgx.width = 5;
	imgx.height = 5;
	imgx.x = 0;
	imgx.y = 0;
	imgx.img = mlx_new_image(w.window, imgx.width, imgx.height);
	imgx.data = (int *)mlx_get_data_addr(imgx.img, &imgx.bits_per_pixel, &imgx.size_line, &imgx.endian);
	for (int i = 0; i < imgx.height; i++)
		for (int j = 0; j < (imgx.size_line / 4); j++)
			imgx.data[i * (imgx.size_line / 4) + j] = 0x00FF0000;
	
	imgy.width = 5;
	imgy.height = 5;
	imgy.x = 0;
	imgy.y = 0;
	imgy.img = mlx_new_image(w.window, imgy.width, imgy.height);
	imgy.data = (int *)mlx_get_data_addr(imgy.img, &imgy.bits_per_pixel, &imgy.size_line, &imgy.endian);
	for (int i = 0; i < imgy.height; i++)
		for (int j = 0; j < (imgy.size_line / 4); j++)
			imgy.data[i * (imgy.size_line / 4) + j] = 0x00FF00FF;
	w.draw = 1;
	mlx_put_image_to_window(w.window, w.canvas, w.img.img, w.img.x, w.img.y);
	mlx_put_image_to_window(w.window, w.canvas, w.player.img, w.player.x, w.player.y);
	ft_event_register(w.canvas, &w);
	mlx_loop_hook(w.window, &ft_draw, &w);
	mlx_loop(w.window);
	return (0);
}