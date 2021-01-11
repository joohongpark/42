/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 23:05:27 by joopark           #+#    #+#             */
/*   Updated: 2021/01/11 14:45:07 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_event_register(void *window, t_canvas *obj)
{
	mlx_hook(window, 2, (1L << 0), &ft_push_key, &obj->keys);
	mlx_hook(window, 3, (1L << 1), &ft_pull_key, &obj->keys);
	mlx_hook(window, 17, (1L << 17), &ft_exit_press, NULL);
}

int					ft_exit_press(int code)
{
	(void)code;
	exit(0);
	return (0);
}

int					ft_frame_gen(t_canvas *obj)
{
	if (ft_key_ispressed(&obj->keys) == 1)
	{
		ft_okgo(obj);
		ft_rendering(obj);
		ft_draw(obj);
	}
	return (0);
}

void				ft_draw(t_canvas *obj)
{
	mlx_clear_window(obj->window, obj->canvas);
	mlx_put_image_to_window(obj->window, obj->canvas, obj->wallpaper.img,
		obj->wallpaper.x, obj->wallpaper.y);
	mlx_put_image_to_window(obj->window, obj->canvas, obj->render.img,
		obj->render.x, obj->render.y);
	mlx_put_image_to_window(obj->window, obj->canvas, obj->sprite_rander.img,
		obj->sprite_rander.x, obj->sprite_rander.y);
}
