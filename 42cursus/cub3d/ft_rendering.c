/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:20:14 by joopark           #+#    #+#             */
/*   Updated: 2020/12/28 16:27:37 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int				ft_rgba(char r, char g, char b, char a)
{
	int			rtn;

	rtn = a & 0x000000ff;
	rtn = (rtn << 8) | (r & 0x000000ff);
	rtn = (rtn << 8) | (g & 0x000000ff);
	rtn = (rtn << 8) | (b & 0x000000ff);
	return (rtn);
}

void				ft_rendering(t_player p, t_img *c, t_map m)
{
	t_vector		cam;
	t_vector		plane;
	t_vector		ray;
	t_vector		target;
	int				w;
	char			wall;
	int				color;
	double			b;


	cam = ft_vspin(p.cam, p.deg);
	plane = ft_vspin(p.plane, p.deg);
	w = 0;
	while (w < c->width)
	{
		ray = ft_vadd(cam, ft_vscala(plane, (w - (c->width / 2)) / (c->width / 2.0)));
		target = ft_raycasting(p.pos, ray, m);
		b = ft_vsize(ft_vadd(target, ft_vinit(p.pos.x * -1, p.pos.y * -1)));
		b = ft_resolution(b, cam, ray);
		wall = ft_isnwse(p.pos, target);
		if (wall == 'n')
			color = ft_makewall(target, 0xff, 0xff , 0xff);
		else if (wall == 'w')
			color = ft_makewall(target, 0xff, 0x00 , 0xff);
		else if (wall == 's')
			color = ft_makewall(target, 0xff, 0xff , 0x00);
		else if (wall == 'e')
			color = ft_makewall(target, 0xff, 0x00 , 0x00);
		ft_draw_wall_proto(c, w, b, color);
		w++;
	}
}

double				ft_resolution(double raw, t_vector cam, t_vector ray)
{
	double			rtn;
	double			eye;

	eye = ft_vsize(cam) / ft_vsize(ray);
	rtn = raw * eye;
	rtn = 1 / rtn;
	return ((rtn > 1) ? 1 : rtn);
}

char				ft_decay(double raw)
{
	return (raw < 0.7 ? (((0.7 - raw)) * 255) : 0);
}