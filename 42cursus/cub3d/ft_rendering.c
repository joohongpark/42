/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:20:14 by joopark           #+#    #+#             */
/*   Updated: 2021/01/05 00:02:27 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_rendering(t_canvas *canvas)
{
	t_vector		cam;
	t_vector		plane;
	t_vector		ray;
	int				width;
	t_vector		target;
	char			wall;
	double			beam;
	double			x_ratio;
	double			plane_scale;


	cam = ft_vspin(canvas->p.cam, canvas->p.deg);
	plane = ft_vspin(canvas->p.plane, canvas->p.deg);
	width = 0;
	while (width < canvas->render.width)
	{
		ft_draw_clear_xline(&canvas->render, width);
		ft_draw_clear_xline(&canvas->sprite_rander, width);
		plane_scale = (width - (canvas->render.width / 2)) / (canvas->render.width / 2.0);
		ray = ft_vadd(cam, ft_vscala(plane, plane_scale));
		target = ft_raycasting(canvas->p.pos, ray, canvas->map);
		beam = ft_vsize(ft_vsub(target, canvas->p.pos));
		beam = ft_resolution(beam, cam, ray);
		x_ratio = ft_getxratio(target);
		wall = ft_isnwse(canvas->p.pos, target);
		if (wall == 'n')
			ft_draw_yline(&canvas->render, canvas->tmp[2], ft_vinit(x_ratio, beam), width);
		else if (wall == 'w')
			ft_draw_yline(&canvas->render, canvas->tmp[3], ft_vinit(x_ratio, beam), width);
		else if (wall == 's')
			ft_draw_yline(&canvas->render, canvas->tmp[4], ft_vinit(x_ratio, beam), width);
		else if (wall == 'e')
			ft_draw_yline(&canvas->render, canvas->tmp[5], ft_vinit(x_ratio, beam), width);
		ft_rendering_sprite(canvas, width, target, ray);
		width++;
	}
}

void				ft_rendering_sprite(t_canvas *canvas, int x, t_vector target, t_vector ray)
{
	t_list			*sprites;
	t_vector		sprite;
	t_vector		scale;
	double			beam;
	double			visible;

	sprites = ft_raycasting_sprite(canvas->p.pos, target, ray, canvas->map);
	while (sprites != NULL)
	{
		sprite = ft_pop(&sprites);
		sprite = ft_vinit(sprite.x + 0.5, sprite.y + 0.5);
		visible = ft_gettheta(ft_vsub(sprite, canvas->p.pos), ray);
		visible = tan(visible);
		beam = ft_vsize(ft_vsub(sprite, canvas->p.pos));
		visible = visible * beam;
		if (visible <= 0.5 && -0.5 <= visible)
		{
			beam = 1 / beam;
			scale = ft_vinit((0.5 - visible), beam);
			ft_draw_yline(&canvas->sprite_rander, canvas->tmp[6], scale, x);
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

char				ft_decay(double raw)
{
	return (raw < 0.7 ? (((0.7 - raw)) * 255) : 0);
}
