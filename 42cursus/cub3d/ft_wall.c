/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:49:08 by joopark           #+#    #+#             */
/*   Updated: 2020/12/27 17:15:56 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void			ft_draw_wall_proto(t_img *img, int x, double y, int color)
{
	int			h;

	h = (int)(y * (img->height / 2));
	for (int iy = 0; iy < img->height; iy++)
	{
		if (iy > ((img->height / 2) - h) && iy < ((img->height / 2) + h))
			img->data[iy * (img->size_line / 4) + x] = color;
		else
			img->data[iy * (img->size_line / 4) + x] = ft_rgba(0, 0, 0, 0xff);
	}
}