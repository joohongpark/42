/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:20:14 by joopark           #+#    #+#             */
/*   Updated: 2021/01/12 19:41:34 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void				ft_rendering(t_canvas *canvas)
{
	t_vector		cam;
	t_vector		plane;
	t_vector		ray;
	int				width;
	t_vector		target;

	cam = ft_vspin(canvas->p.cam, canvas->p.deg);
	plane = ft_vspin(canvas->p.plane, canvas->p.deg);
	width = 0;
	while (width < canvas->render.width)
	{
		ft_draw_clear_xline(&canvas->render, width);
		ft_draw_clear_xline(&canvas->sprite_rander, width);
		ray = ft_vscala(plane, (2.0 * width / canvas->render.width - 1));
		ray = ft_vadd(cam, ray);
		target = ft_raycasting(canvas->p.pos, ray, canvas->map);
		ft_draw_wall(canvas, width, target, ray);
		ft_draw_sprite(canvas, width, target, ray);
		width++;
	}
}

void				ft_draw_wall(t_canvas *c, int x, t_vector t, t_vector ray)
{
	t_vector		cam;
	t_vector		scale;
	char			wall;
	double			x_ratio;
	double			beam;

	cam = ft_vspin(c->p.cam, c->p.deg);
	beam = ft_vsize(ft_vsub(t, c->p.pos));
	beam = ft_resolution(beam, cam, ray);
	x_ratio = ft_getxratio(t);
	wall = ft_isnwse(c->p.pos, t);
	scale = ft_vinit(x_ratio, beam);
	ft_draw_yline(&c->render, *ft_ctoi(wall, c), scale, x);
	ft_decay_yline(&c->render, x, beam);
}

void				ft_draw_sprite(t_canvas *c, int x, t_vector t, t_vector ray)
{
	t_list			*sprites;
	t_vector		sprite;
	t_vector		scale;
	double			beam;
	double			visible;

	sprites = ft_find_sprite(c->p.pos, t, ray, c->map);
	while (sprites != NULL)
	{
		sprite = ft_pop(&sprites);
		sprite = ft_vinit(sprite.x + 0.5, sprite.y + 0.5);
		visible = ft_gettheta(ft_vsub(sprite, c->p.pos), ray);
		visible = tan(visible);
		beam = ft_vsize(ft_vsub(sprite, c->p.pos));
		visible = visible * beam;
		if (visible <= 0.5 && -0.5 <= visible)
		{
			beam = 1 / beam;
			scale = ft_vinit((0.5 - visible), beam);
			ft_draw_yline(&c->sprite_rander, c->sprite_texture[
					c->map.map[(int)sprite.y][(int)sprite.x] - 'b'], scale, x);
			ft_decay_yline(&c->sprite_rander, x, beam);
		}
	}
}

double				ft_resolution(double raw, t_vector cam, t_vector ray)
{
	double			rtn;
	double			eye;

	eye = ft_vsize(cam) / ft_vsize(ray);
	rtn = raw * eye;
	rtn = 1 / rtn;
	return (rtn);
}

void				ft_set_background(t_canvas *canvas)
{
	int				i;
	int				j;
	int				iw;

	iw = canvas->wallpaper.size_line / 4;
	i = 0;
	while (i < canvas->wallpaper.height)
	{
		j = 0;
		while (j < iw)
		{
			if (i < canvas->wallpaper.height / 2)
				canvas->wallpaper.data[i * iw + j] = ft_decay(
					canvas->floor_color,
					1 - ((i * 1.0) / (canvas->wallpaper.height * 0.5)));
			else
				canvas->wallpaper.data[i * iw + j] = ft_decay(
					canvas->ceilling_color,
					((i * 1.0) / (canvas->wallpaper.height * 2)));
			j++;
		}
		i++;
	}
}
