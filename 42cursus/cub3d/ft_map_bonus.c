/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:56:47 by joopark           #+#    #+#             */
/*   Updated: 2021/01/12 01:57:55 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int					ft_map(char *line, t_map *map)
{
	char			**m;
	int				x;

	x = ft_strlen(line);
	map->y++;
	if (!(m = ft_map_xadd(line, map, x)))
		return (-1);
	map->x = (map->x < x) ? x : map->x;
	map->map = m;
	return (1);
}

char				**ft_map_xadd(char *line, t_map *map, int x)
{
	int				i;
	char			**m;

	i = -1;
	if (!(m = (char **)malloc(sizeof(char *) * (map->y))))
		return (NULL);
	while (++i < map->y)
	{
		if (!(m[i] = (char *)malloc((map->x < x) ? x : map->x)))
			return (NULL);
		if (i < (map->y - 1))
		{
			ft_memcpy(m[i], map->map[i], map->x);
			ft_memset(m[i] + map->x, 0, (map->x < x) ? (x - map->x) : 0);
			free(map->map[i]);
		}
		else
		{
			ft_memcpy(m[i], line, x);
			ft_memset(m[i] + x, 0, (x < map->x) ? (map->x - x) : 0);
			if (map->map != NULL)
				free(map->map);
		}
	}
	return (m);
}
