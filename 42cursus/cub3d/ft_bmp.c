/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 07:45:58 by joopark           #+#    #+#             */
/*   Updated: 2021/01/11 14:09:42 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bmp				ft_bmp_init(int width, int height)
{
	t_bmp			rtn;
	int				img_size;

	rtn.width = width;
	rtn.height = height;
	img_size = height * width * 4;
	rtn.filesize = img_size + 54;
	height = -1 * height;
	if (!(rtn.data = malloc(sizeof(char) * rtn.filesize)))
		return (rtn);
	ft_memset(rtn.data, 0, rtn.filesize);
	ft_memcpy(rtn.data, "BM", 2);
	ft_memcpy(rtn.data + 2, (void *)&rtn.filesize, 4);
	ft_memcpy(rtn.data + 10, "\x36", 1);
	ft_memcpy(rtn.data + 14, "\x28", 1);
	ft_memcpy(rtn.data + 18, (void *)&width, 4);
	ft_memcpy(rtn.data + 22, (void *)&height, 4);
	ft_memcpy(rtn.data + 26, "\x1", 1);
	ft_memcpy(rtn.data + 28, "\x20", 1);
	ft_memcpy(rtn.data + 34, (void *)&img_size, 4);
	return (rtn);
}

void				ft_bmp_write(t_bmp *bmp, t_img img)
{
	char			*dw;
	int				i;
	int				j;
	int				iw;
	int				bw;

	dw = bmp->data + 0x36;
	iw = img.size_line / 4;
	bw = bmp->width * 4;
	i = 0;
	while (i < bmp->height)
	{
		j = 0;
		while (j < bmp->width)
		{
			if ((img.data[i * iw + j] & (int)0xff000000) != (int)0xff000000)
				*((int *)&dw[(i * bw + j * 4)]) = img.data[i * iw + j];
			else if (*((int *)&dw[(i * bw + j * 4)]) == 0)
				*((int *)&dw[(i * bw + j * 4)]) = (int)0xff000000;
			j++;
		}
		i++;
	}
}

int					ft_bmp_save(char *filename, t_bmp bmp)
{
	int				fd;
	int				write_len;

	if ((fd = open(filename, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG)) < 0)
		return (-1);
	write_len = write(fd, bmp.data, bmp.filesize);
	if (write_len != bmp.filesize)
		return (-1);
	free(bmp.data);
	return (1);
}

int					ft_save_image(char *filename, t_canvas *canvas)
{
	t_bmp		b;

	ft_rendering(canvas);
	b = ft_bmp_init(canvas->width, canvas->height);
	ft_bmp_write(&b, canvas->wallpaper);
	ft_bmp_write(&b, canvas->render);
	ft_bmp_write(&b, canvas->sprite_rander);
	if (ft_bmp_save(filename, b) < 0)
	{
		write(1, "Error\n", ft_strlen("Error\n"));
		exit(-1);
	}
	return (1);
}
