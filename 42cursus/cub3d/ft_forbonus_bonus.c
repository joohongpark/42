/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forbonus_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 02:10:35 by joopark           #+#    #+#             */
/*   Updated: 2021/01/12 19:28:33 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_img				ft_bonus_img_resize(void *window, t_img img, int w, int h)
{
	t_img			rtn;
	int				cx;
	int				cy;
	int				i;
	int				j;

	rtn = ft_new_img(window, w, h);
	i = 0;
	while (i < rtn.height)
	{
		j = 0;
		while (j < (rtn.size_line / 4))
		{
			cx = j * img.width / rtn.width;
			cy = i * img.height / rtn.height;
			rtn.data[i * (rtn.size_line / 4) + j] =
				img.data[cy * (img.size_line / 4) + cx];
			j++;
		}
		i++;
	}
	mlx_destroy_image(window, img.img);
	return (rtn);
}

int					ft_decay(int pixel, double raw)
{
	int				rtn;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	d;

	r = (((unsigned int)pixel & 0xff0000) >> 16) & 0xff;
	g = (((unsigned int)pixel & 0xff00) >> 8) & 0xff;
	b = ((unsigned int)pixel & 0xff) & 0xff;
	d = (raw < 0.7 ? (((0.7 - raw)) * 255) : 0);
	r = (r > d) ? r - d : 0;
	g = (g > d) ? g - d : 0;
	b = (b > d) ? b - d : 0;
	rtn = ft_rgba(r, g, b, 0);
	return (rtn);
}

void				ft_decay_yline(t_img *img, int x, double dist)
{
	int				y;

	y = 0;
	while (y < img->height)
	{
		if (img->data[y * (img->size_line / 4) + x] != (int)0xff000000)
			img->data[y * (img->size_line / 4) + x] =
				ft_decay(img->data[y * (img->size_line / 4) + x], dist);
		y++;
	}
}
