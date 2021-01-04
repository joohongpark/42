/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:20:14 by joopark           #+#    #+#             */
/*   Updated: 2021/01/04 22:04:33 by joopark          ###   ########.fr       */
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
		beam = ft_vsize(ft_vadd(target, ft_vscala(canvas->p.pos, -1)));
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
	t_vector		sprite_target;

	sprites = ft_raycasting_sprite(canvas->p.pos, target, ray, canvas->map);
	while (sprites != NULL)
	{
		sprite_target = ft_pop(&sprites);
		ft_draw_sprite_proto(canvas, x, sprite_target, canvas->p.pos, ray);
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