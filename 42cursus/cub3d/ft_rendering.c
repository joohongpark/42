/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:20:14 by joopark           #+#    #+#             */
/*   Updated: 2020/12/29 17:21:10 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_rendering(t_canvas *canvas)
{
	t_vector		cam;
	t_vector		plane;
	t_vector		ray;
	t_vector		target;
	int				width;
	char			wall;
	double			beam;
	double			x_ratio;


	cam = ft_vspin(canvas->p.cam, canvas->p.deg);
	plane = ft_vspin(canvas->p.plane, canvas->p.deg);
	width = 0;
	while (width < canvas->render.width)
	{
		ray = ft_vadd(cam, ft_vscala(plane, (width - (canvas->render.width / 2)) / (canvas->render.width / 2.0)));
		target = ft_raycasting(canvas->p.pos, ray, canvas->map);
		beam = ft_vsize(ft_vadd(target, ft_vscala(canvas->p.pos, -1)));
		beam = ft_resolution(beam, cam, ray);
		x_ratio = ft_getxratio(target);
		wall = ft_isnwse(canvas->p.pos, target);
		if (wall == 'n')
			ft_draw_wall_proto(&canvas->render, width, beam, x_ratio, canvas->tmp[2]);
		else if (wall == 'w')
			ft_draw_wall_proto(&canvas->render, width, beam, x_ratio, canvas->tmp[3]);
		else if (wall == 's')
			ft_draw_wall_proto(&canvas->render, width, beam, x_ratio, canvas->tmp[4]);
		else if (wall == 'e')
			ft_draw_wall_proto(&canvas->render, width, beam, x_ratio, canvas->tmp[5]);
		width++;
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