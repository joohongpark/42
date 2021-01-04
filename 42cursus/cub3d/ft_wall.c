/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:49:08 by joopark           #+#    #+#             */
/*   Updated: 2021/01/04 22:24:45 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double				ft_gettheta(t_vector v1, t_vector v2)
{
	double			denom;
	double			nom;
	double			rtn;

	denom = ft_vsize(v1) * ft_vsize(v2);
	nom = v1.x * v2.y - v1.y * v2.x;
	rtn = asin(nom / denom);
	return (rtn);
}

double				ft_getxratio(t_vector w)
{
	double			ratio;

	if (((int)w.x) * 1.0 != w.x)
		ratio = w.x - ((int)w.x) * 1.0;
	else
		ratio = w.y - ((int)w.y) * 1.0;
	return (ratio);
}

char				ft_isnwse(t_vector start, t_vector end)
{
	double			dx;
	double			dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	if (dx < 0 && dy < 0)
		return ((((int)end.x) * 1.0 == end.x) ? 'w' : 'n');
	if (dx >= 0 && dy >= 0)
		return ((((int)end.x) * 1.0 == end.x) ? 'e' : 's');
	if (dx < 0 && dy >= 0)
		return ((((int)end.x) * 1.0 == end.x) ? 'w' : 's');
	if (dx >= 0 && dy < 0)
		return ((((int)end.x) * 1.0 == end.x) ? 'e' : 'n');
	return (0);
}

void			ft_draw_clear_xline(t_img *img, int x)
{
	int			y;

	y = 0;
	while (y < img->height)
	{
		img->data[y * (img->size_line / 4) + x] = ft_rgba(0, 0, 0, 0xff);
		y++;
	}
}

void				ft_draw_yline(t_img *to, t_img from, t_vector scale, int posx)
{
	int				width;
	int				h;
	int				px;
	int				py;
	int				offset;

	h = (int)(((scale.y > 1) ? 1 : scale.y) * (to->height / 2));
	width = (to->height / 2) - h;
	while (width < ((to->height / 2) + h))
	{
		offset = (scale.y > 1) ? (from.height * (scale.y - 1) / (scale.y * 2)) : 0;
		px = from.width * scale.x;
		py = from.height * (width - ((to->height / 2) - h)) / (to->height * scale.y);
		py += offset;
		if (from.data[py * (from.size_line / 4) + px] != ft_rgba(0, 0, 0, 0xff))
			to->data[width * (to->size_line / 4) + posx] = from.data[py * (from.size_line / 4) + px];
		width++;
	}
	
}

void				ft_draw_sprite_proto(t_canvas *canvas, int x, t_vector target, t_vector p, t_vector b)
{
	double			beam;
	double			visible;
	int				y;
	int				h;
	int				dy;

	target = ft_vinit(target.x + 0.5, target.y + 0.5);
	visible = ft_gettheta(ft_vadd(target, ft_vscala(p, -1)), b);
	visible = tan(visible);
	beam = ft_vsize(ft_vadd(target, ft_vscala(p, -1)));
	visible = visible * beam;
	beam = 1 / beam;
	h = (int)(((beam > 1) ? 1 : beam) * (canvas->sprite_rander.height / 2));
	y = (canvas->sprite_rander.height / 2) - h;
	dy = 0;
	if (visible <= 0.5 && -0.5 <= visible)
		ft_draw_yline(&canvas->sprite_rander, canvas->tmp[6], ft_vinit((0.5 - visible), beam), x);
}