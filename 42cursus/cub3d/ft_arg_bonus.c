/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:24:22 by joopark           #+#    #+#             */
/*   Updated: 2021/01/12 19:27:21 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int					ft_arg(t_canvas *canvas, int argc, char *argv[])
{
	char			*path;
	int				i;

	if (argc < 2 || argc > 3)
		return (-1);
	i = 0;
	path = ft_isfile(argc, argv, &i);
	canvas->is_save = ft_ishavesaveflag(argc, argv, i);
	if (path != NULL && canvas->is_save >= 0)
		return (ft_parser(path, canvas));
	else
		return (-1);
}

int					ft_ishavesaveflag(int argc, char *argv[], int c)
{
	int				i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp("--save", (const char *)argv[i], 6) == 0)
			return (1);
		i++;
	}
	if (i == 3 || (c == 2 && i == 2))
		return (-1);
	return (0);
}

char				*ft_isfile(int argc, char *argv[], int *c)
{
	int				i;

	i = 1;
	while (i < argc)
	{
		if (ft_strnstr((const char *)argv[i], ".cub",
			ft_strlen(argv[i])) != NULL)
		{
			*c = i;
			return (argv[i]);
		}
		i++;
	}
	return (NULL);
}

int					ft_canvas_isvaild(t_canvas *canvas)
{
	int				width;
	int				height;

	if (
		(canvas->width <= 0) ||
		(canvas->height <= 0) ||
		(canvas->map.map == NULL) ||
		(canvas->north_texture.img == NULL) ||
		(canvas->south_texture.img == NULL) ||
		(canvas->west_texture.img == NULL) ||
		(canvas->east_texture.img == NULL) ||
		(canvas->sprite_texture[0].img == NULL))
		return (-1);
	mlx_get_screen_size(canvas->window, &width, &height);
	canvas->width = (canvas->width > width) ? width : canvas->width;
	canvas->height = (canvas->height > height) ? height : canvas->height;
	if (ft_map_parser(canvas) < 0)
		return (-1);
	return (1);
}
