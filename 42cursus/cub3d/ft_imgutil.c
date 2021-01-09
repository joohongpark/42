/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imgutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 22:24:04 by joopark           #+#    #+#             */
/*   Updated: 2021/01/09 22:53:51 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					ft_rgba(char r, char g, char b, char a)
{
	int				rtn;

	rtn = a & 0x000000ff;
	rtn = (rtn << 8) | (r & 0x000000ff);
	rtn = (rtn << 8) | (g & 0x000000ff);
	rtn = (rtn << 8) | (b & 0x000000ff);
	return (rtn);
}

t_img				ft_new_img(void *window, int width, int height)
{
	t_img			rtn;

	rtn.x = 0;
	rtn.y = 0;
	rtn.width = width;
	rtn.height = height;
	rtn.img = mlx_new_image(window, width, height);
	rtn.data = (int *)mlx_get_data_addr(rtn.img,
					&rtn.bits_per_pixel, &rtn.size_line, &rtn.endian);
	return (rtn);
}

t_img				ft_get_img_from_xpm(void *window, char *uri)
{
	t_img			rtn;

	rtn.x = 0;
	rtn.y = 0;
	rtn.img = mlx_xpm_file_to_image(window, uri, &rtn.width, &rtn.height);
	rtn.data = (int *)mlx_get_data_addr(rtn.img,
					&rtn.bits_per_pixel, &rtn.size_line, &rtn.endian);
	return (rtn);
}

t_img				ft_get_img_from_png(void *window, char *uri)
{
	t_img			rtn;

	rtn.x = 0;
	rtn.y = 0;
	rtn.img = mlx_png_file_to_image(window, uri, &rtn.width, &rtn.height);
	rtn.data = (int *)mlx_get_data_addr(rtn.img,
					&rtn.bits_per_pixel, &rtn.size_line, &rtn.endian);
	return (rtn);
}
