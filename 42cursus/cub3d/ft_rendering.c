/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:20:14 by joopark           #+#    #+#             */
/*   Updated: 2021/01/03 14:37:14 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list				*ft_findsprite(t_vector s, t_vector e, t_vector b, t_map m)
{
	t_list			*rtn;
	t_vector		tmp;
	t_vector		tmp1;
	double			delta;
	double			len;
	double			len2;

	len = ft_vsize(ft_vadd(e, ft_vscala(s, -1)));
	rtn = NULL;
	tmp1 = s;
	delta = fabs(e.y - s.y) / fabs(e.x - s.x);
	delta = isfinite(delta) ? delta : 2;
	b = (delta > 1) ? ft_vinit(b.y, b.x) : b;
	s = (delta > 1) ? ft_vinit(s.y, s.x) : s;
	s = ft_xstart(s, b);
	while (ft_checkspace((delta > 1) ? ft_vinit(s.y, s.x) : s, m) == 1)
	{
		tmp = ft_checksprite((delta > 1) ? ft_vinit(s.y, s.x) : s, m);
		if (tmp.x != -1)
			ft_push(&rtn, tmp);
		s = ft_xinc(s, b);
	}
	tmp = ft_checksprite((delta > 1) ? ft_vinit(s.y, s.x) : s, m);
	len2 = ft_vsize(ft_vadd(ft_vinit(tmp.x + 0.5, tmp.y + 0.5), ft_vscala(tmp1, -1)));
	if ((tmp.x != -1) && (len2 < len))
		ft_push(&rtn, tmp);
	return (rtn);
}

void				ft_rendering(t_canvas *canvas)
{
	t_vector		cam;
	t_vector		plane;
	t_vector		ray;
	t_vector		target;
	t_list			*lst;
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
		lst = ft_findsprite(canvas->p.pos, target, ray, canvas->map);
		ft_draw_sprite_proto(&canvas->tmp[7], width, &lst, canvas->p.pos, canvas->tmp[6]);
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