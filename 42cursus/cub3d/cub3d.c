/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:29:11 by joopark           #+#    #+#             */
/*   Updated: 2021/01/11 15:21:57 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	canvas->p.cam = ft_vinit(1, 0);
	canvas->p.deg = 0;
}

void			ft_canvas_set(t_canvas *canvas)
{
	int			w;
	int			h;

	w = canvas->width;
	h = canvas->height;
	canvas->p.plane = ft_vinit(0, (w / (h * 2.0)));
	canvas->canvas = mlx_new_window(canvas->window, w, h, "joopark's cub3d");
	canvas->render = ft_new_img(canvas->window, w, h);
	canvas->wallpaper = ft_new_img(canvas->window, w, h);
	canvas->sprite_rander = ft_new_img(canvas->window, w, h);
	ft_set_background(canvas);
	ft_init_key(&canvas->keys);
	ft_rendering(canvas);
	ft_draw(canvas);
}

void			ft_exit(void)
{
	write(1, "Error\n", ft_strlen("Error\n"));
	exit(-1);
}

int				main(int argc, char *argv[])
{
	t_canvas	canvas;

	ft_canvas_init(&canvas);
	if (ft_arg(&canvas, argc, argv) < 0 || ft_canvas_isvaild(&canvas) < 0)
		ft_exit();
	ft_canvas_set(&canvas);
	if (canvas.is_save == 1)
	{
		if (ft_save_image("./capture.bmp", &canvas) < 0)
			ft_exit();
		exit(0);
	}
	ft_event_register(canvas.canvas, &canvas);
	mlx_loop_hook(canvas.window, &ft_frame_gen, &canvas);
	mlx_loop(canvas.window);
	return (0);
}
