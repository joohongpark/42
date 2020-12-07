/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:29:11 by joopark           #+#    #+#             */
/*   Updated: 2020/12/07 13:09:12 by joopark          ###   ########.fr       */
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
	// a s d f : 0 1 2 3
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
	return (0);
}

int				ft_mouse_press(int code, int x, int y, char *str)
{
	printf("code : %02x(%d, %d) at %s\n", code, x, y, str);
	return (0);
}

int				ft_draw(t_canvas *obj)
{
	mlx_clear_window(obj->window, obj->canvas);
	mlx_put_image_to_window(obj->window, obj->canvas, obj->img.img, obj->img.x, obj->img.y);
	mlx_put_image_to_window(obj->window, obj->canvas, obj->player.img, obj->player.x, obj->player.y);
	return (0);
}

void			ft_event_register(void *window, t_canvas *obj)
{
	//mlx_key_hook(window, &ft_key_press, &obj->img);
	mlx_hook(window, 2, 0, &ft_key_press, obj);
	mlx_mouse_hook(window, &ft_mouse_press, "mouse");
	//mlx_expose_hook(window, &ft_test, "expose");
}

int				main(void)
{
	t_canvas	w;

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
	for (int i = 0; i < w.img.height; i++)
		for (int j = 0; j < (w.img.size_line / 4); j++)
			w.img.data[i * (w.img.size_line / 4) + j] = 0x000000FF;

	w.player.width = 20;
	w.player.height = 20;
	w.player.x = 0;
	w.player.y = 0;
	w.player.img = mlx_new_image(w.window, w.player.width, w.player.height);
	w.player.data = (int *)mlx_get_data_addr(w.player.img, &w.player.bits_per_pixel, &w.player.size_line, &w.player.endian);
	for (int i = 0; i < w.player.height; i++)
		for (int j = 0; j < (w.player.size_line / 4); j++)
			w.player.data[i * (w.player.size_line / 4) + j] = 0x0000FFFF;
	
	mlx_put_image_to_window(w.window, w.canvas, w.img.img, w.img.x, w.img.y);
	mlx_put_image_to_window(w.window, w.canvas, w.player.img, w.player.x, w.player.y);
	ft_event_register(w.canvas, &w);
	mlx_loop_hook(w.window, &ft_draw, &w);
	mlx_loop(w.window);
	return (0);
}