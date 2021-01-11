/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:49:08 by joopark           #+#    #+#             */
/*   Updated: 2021/01/11 02:14:27 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_img				*ft_ctoi(char wall, t_canvas *c)
{
	if (wall == 'n')
		return (&c->north_texture);
	else if (wall == 'w')
		return (&c->west_texture);
	else if (wall == 's')
		return (&c->south_texture);
	else if (wall == 'e')
		return (&c->east_texture);
	else
		return (&c->east_texture);
}

void				ft_draw_clear_xline(t_img *img, int x)
{
	int				y;

	y = 0;
	while (y < img->height)
	{
		img->data[y * (img->size_line / 4) + x] = (int)0xff000000;
		y++;
	}
}

void				ft_draw_yline(t_img *to, t_img from, t_vector scale, int x)
{
	int				width;
	int				h;
	int				px;
	int				py;
	int				offset;

	h = (int)(((scale.y > 1) ? 1 : scale.y) * (to->height / 2));
	width = (to->height / 2) - h;
	px = from.width * scale.x;
	offset = (scale.y > 1) ? (from.height * (scale.y - 1) / (scale.y * 2)) : 0;
	while (width < ((to->height / 2) + h))
	{
		py = from.height * (width - ((to->height / 2) - h));
		py /= to->height * scale.y;
		py += offset;
		if (from.data[py * (from.size_line / 4) + px] != (int)0xff000000)
		{
			to->data[width * (to->size_line / 4) + x] =
				from.data[py * (from.size_line / 4) + px];
		}
		width++;
	}
}
