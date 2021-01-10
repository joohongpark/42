/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_vaild_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 22:28:46 by joopark           #+#    #+#             */
/*   Updated: 2021/01/10 23:18:25 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int					ft_map_parser(t_canvas *canvas)
{
	int				x;
	int				y;
	int				is_false;

	is_false = 0;
	if (ft_findplayer(&canvas->map, &x, &y) < 0)
		return (-1);
	canvas->map.map[y][x] = '0';
	canvas->p.pos = ft_vinit(x + 0.5, y + 0.5);
	ft_dfs(&canvas->map, x, y, &is_false);
	if (is_false != 0)
		return (-1);
	if (ft_map_set(&canvas->map) < 0)
		return (-1);
	return (1);
}

void				ft_dfs(t_map *map, int x, int y, int *is_false)
{
	if (0 > x || 0 > y || map->x <= x || map->y <= y || map->map[y][x] == 's'
		|| map->map[y][x] == 'w' || map->map[y][x] == 'b')
		return ;
	if (map->map[y][x] == '0')
	{
		if (0 == x || 0 == y || map->x == x || map->y == y)
			*is_false = *is_false + 1;
		map->map[y][x] = 's';
		ft_dfs(map, x + 1, y, is_false);
		ft_dfs(map, x, y + 1, is_false);
		ft_dfs(map, x - 1, y, is_false);
		ft_dfs(map, x, y - 1, is_false);
	}
	else if (map->map[y][x] == '2')
	{
		if (0 == x || 0 == y || map->x == x || map->y == y)
			*is_false = *is_false + 1;
		map->map[y][x] = 'b';
	}
	else if (map->map[y][x] == '1')
		map->map[y][x] = 'w';
	else
		*is_false = *is_false + 1;
}

int					ft_findplayer(t_map *map, int *x, int *y)
{
	int				rtn;

	rtn = -1;
	*y = 0;
	while (*y < map->y && rtn != 1)
	{
		*x = 0;
		while (*x < map->x && rtn != 1)
		{
			if (map->map[*y][*x] == 'N')
				rtn = 1;
			else
				*x = *x + 1;
		}
		if (rtn != 1)
			*y = *y + 1;
	}
	return (rtn);
}

int					ft_map_set(t_map *map)
{
	int				x;
	int				y;
	char			c;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			c = map->map[y][x];
			if (c == '1')
				map->map[y][x] = 'w';
			else if (c == '0')
				map->map[y][x] = 's';
			else if (c == '2')
				map->map[y][x] = 'b';
			else if (c == '\0' || c == ' ')
				map->map[y][x] = 'w';
			else if (c != 's' && c != 'w' && c != 'b')
				return (-1);
			x = x + 1;
		}
	}
	return (1);
}
