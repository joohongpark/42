/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:49:08 by joopark           #+#    #+#             */
/*   Updated: 2021/01/03 23:08:21 by joopark          ###   ########.fr       */
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

void			ft_draw_wall_proto(t_img *img, int x, double yr, double xratio, t_img from)
{
	int			h;
	int			y;
	int			cy;
	int			px;
	int			py;
	int			offset;

	h = (int)(((yr > 1) ? 1 : yr) * (img->height / 2));
	y = 0;
	cy = 0;
	while (y < img->height)
	{
		if (y > ((img->height / 2) - h) && y < ((img->height / 2) + h))
		{
			offset = (yr > 1) ? (from.height * (yr - 1) / (yr * 2)) : 0;
			px = from.width * xratio;
			py = from.height * cy / (img->height * yr) + offset;
			img->data[y * (img->size_line / 4) + x] = from.data[py * (from.size_line / 4) + px];
			cy++;
		}
		else
		{
			img->data[y * (img->size_line / 4) + x] = ft_rgba(0, 0, 0, 0xff);
		}
		y++;
	}
}

void				ft_draw_sprite_proto(t_canvas *canvas, int x, t_list **sprites, t_vector p, t_vector b)
{
	double			beam;
	double			visible;
	t_vector		target;
	int				y;
	int				h;
	int				px;
	int				py;
	int				offset;
	int				dy;

	ft_draw_clear_xline(&canvas->tmp[7], x);
	while (*sprites != NULL)
	{
		target = ft_pop(sprites);
		target = ft_vinit(target.x + 0.5, target.y + 0.5);
		visible = ft_gettheta(ft_vadd(target, ft_vscala(p, -1)), b);
		visible = tan(visible);
		beam = ft_vsize(ft_vadd(target, ft_vscala(p, -1)));
		visible = visible * beam;
		beam = 1 / beam;
		h = (int)(((beam > 1) ? 1 : beam) * (canvas->tmp[7].height / 2));
		y = (canvas->tmp[7].height / 2) - h;
		dy = 0;
		while (y < ((canvas->tmp[7].height / 2) + h))
		{
			if (visible < 0.5 && -0.5 < visible)
			{
				offset = (beam > 1) ? (canvas->tmp[6].height * (beam - 1) / (beam * 2)) : 0;
				px = canvas->tmp[6].width * (0.5-visible);
				py = canvas->tmp[6].height * dy / (canvas->tmp[7].height * beam) + offset;
				if (ft_rgba(0, 0, 0, 0xff) != canvas->tmp[6].data[py * (canvas->tmp[6].size_line / 4) + px])
					canvas->tmp[7].data[y * (canvas->tmp[7].size_line / 4) + x] = canvas->tmp[6].data[py * (canvas->tmp[6].size_line / 4) + px];
				dy++;
			}
			y++;
		}
	}
}