/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:49:08 by joopark           #+#    #+#             */
/*   Updated: 2020/12/29 00:27:05 by joopark          ###   ########.fr       */
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

void			ft_draw_wall_proto(t_img *img, int x, double yr, double xratio, t_img from)
{
	int			h;
	int			y;
	int			cy;
	int			px;
	int			py;

	h = (int)(yr * (img->height / 2));
	y = 0;
	cy = 0;
	while (y < img->height)
	{
		if (y > ((img->height / 2) - h) && y < ((img->height / 2) + h))
		{
			px = from.width * xratio;
			py = from.height * cy / (2 * h);
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