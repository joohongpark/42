/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:49:08 by joopark           #+#    #+#             */
/*   Updated: 2021/01/03 22:26:24 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double				ft_gettheta(t_vector v1, t_vector v2)
{
	//t_vector		a;
	//t_vector		b;
	double			denom;
	double			nom;
	double			rtn;

	//a = ft_vadd(v1, ft_vscala(o, -1));
	//b = ft_vadd(v2, ft_vscala(o, -1));
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

void				ft_draw_sprite_proto(t_img *img, int x, t_list **sprites, t_vector p, t_vector b)
{
	double			beam;
	double			visible;
	t_vector		target;
	int				y;
	int				h;

	ft_draw_clear_xline(img, x);
	while (*sprites != NULL)
	{
		target = ft_pop(sprites);
		target = ft_vinit(target.x + 0.5, target.y + 0.5);
		visible = ft_gettheta(ft_vadd(target, ft_vscala(p, -1)), b);
		//printf("(x : %f)", 180 * (visible / M_PI));
		visible = tan(visible);
		beam = ft_vsize(ft_vadd(target, ft_vscala(p, -1)));
		visible = visible * beam;
		beam = 1 / beam;
		h = (int)(((beam > 1) ? 1 : beam) * (img->height / 2));
		y = (img->height / 2) - h;
		while (y < ((img->height / 2) + h))
		{
			if (visible < 0.5 && -0.5 < visible)
				img->data[y * (img->size_line / 4) + x] = ft_rgba(0, 0, 255 * (0.5-visible), 0x00);
			else
				img->data[y * (img->size_line / 4) + x] = ft_rgba(0, 0xff, 0xff, 0x00);
			y++;
		}
	}
}