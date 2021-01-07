/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:24:22 by joopark           #+#    #+#             */
/*   Updated: 2021/01/07 20:23:24 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int					ft_arg(t_canvas *canvas, int argc, char *argv[])
{
	char			*path;

	if (argc < 2 || argc > 3)
		return (-1);
	canvas->is_save = ft_ishavesaveflag(argc, argv);
	path = ft_isfile(argc, argv);
	if (path != NULL)
		return (ft_parser(path, canvas));
	else
		return (-1);
}

int					ft_ishavesaveflag(int argc, char *argv[])
{
	int				i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp("--save", (const char *)argv[i], 6) == 0)
			return (1);
		i++;
	}
	return (0);
}

char				*ft_isfile(int argc, char *argv[])
{
	int				i;

	i = 1;
	while (i < argc)
	{
		if (ft_strnstr((const char *)argv[i], ".cub", ft_strlen(argv[i])) != NULL)
			return (argv[i]);
		i++;
	}
	return (NULL);
}
