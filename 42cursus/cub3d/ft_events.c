/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 23:05:27 by joopark           #+#    #+#             */
/*   Updated: 2021/01/05 10:44:58 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void			ft_event_register(void *window, t_canvas *obj)
{
	//mlx_key_hook(window, &ft_key_press, &obj->img);
	mlx_hook(window, 2, (1L<<0), &ft_key_press, obj);
	mlx_hook(window, 3, (1L<<1), &ft_key_press, obj);
	mlx_hook(window, 17, (1L<<17), &ft_key_press_test, obj);
	mlx_mouse_hook(window, &ft_mouse_press, "mouse");
	//mlx_expose_hook(window, &ft_test, "expose");
}

int				ft_key_press(int code, t_canvas *obj)
{
	// 0x7b : <-
	// 0x7e : ^
	// 0x7d : _
	// 0x7c : ->
	// 0x35 : esc
	// w a s d : 0x0d 0 1 2
	t_vector		ray;
	printf("code : %d\n", code);
	if (code == 0x35)
		exit(0);
	else if (code == 0x02)
		obj->p.pos = ft_gotoxy(obj->p.pos, ft_getdelta(obj->p.deg + 90, 0.1), obj->map);
	else if (code == 0x01)
		obj->p.pos = ft_gotoxy(obj->p.pos, ft_getdelta(obj->p.deg - 180, 0.1), obj->map);
	else if (code == 0x00)
		obj->p.pos = ft_gotoxy(obj->p.pos, ft_getdelta(obj->p.deg - 90, 0.1), obj->map);
	else if (code == 0x0d)
		obj->p.pos = ft_gotoxy(obj->p.pos, ft_getdelta(obj->p.deg, 0.1), obj->map);
	else if (code == 0x7b)
		obj->p.deg -= (0 < obj->p.deg) ? 1 : -360;
	else if (code == 0x7c)
		obj->p.deg += (360 > obj->p.deg) ? 1 : -360;
	
						
	// test
	
	ray = ft_vinit(1, 0);
	ray = ft_vspin(ray, obj->p.deg);
	printf("obj->player.deg : %d\n", obj->p.deg);
	obj->draw = 1;
	return (0);
}

int				ft_key_press_test(int code, t_canvas *obj)
{
	(void)obj;
	if (code == 0x53)
		exit(0);
	printf("code : %x\n", code);
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
		mlx_put_image_to_window(obj->window, obj->canvas, obj->render.img, obj->render.x, obj->render.y);
		mlx_put_image_to_window(obj->window, obj->canvas, obj->sprite_rander.img, obj->sprite_rander.x, obj->sprite_rander.y);
		obj->draw = 0;
	}
	return (0);
}
