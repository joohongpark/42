/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkroom_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:49:09 by joopark           #+#    #+#             */
/*   Updated: 2021/01/12 19:30:47 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int					ft_checkspace(t_vector v, t_map map)
{
	int				x;
	int				y;

	if (isnan(v.x) || isnan(v.y) || isinf(v.x) || isinf(v.y)
		|| v.x < 0 || v.y < 0 || map.x <= v.x || map.y <= v.y)
		return (-1);
	x = (int)v.x;
	y = (int)v.y;
	if ((x > 0) && (x * 1.0 == v.x) && map.map[y][x - 1] == WALL)
		return (0);
	if ((y > 0) && (y * 1.0 == v.y) && map.map[y - 1][x] == WALL)
		return (0);
	if (map.map[y][x] == WALL)
		return (0);
	return (1);
}

t_vector			ft_checksprite(t_vector v, t_map map)
{
	int				x;
	int				y;

	if (isnan(v.x) || isnan(v.y) || isinf(v.x) || isinf(v.y)
		|| v.x < 0 || v.y < 0 || map.x <= v.x || map.y <= v.y)
		return (ft_vinit(-1, -1));
	x = (int)v.x;
	y = (int)v.y;
	if ((x > 0) && (x * 1.0 == v.x) &&
		(map.map[y][x - 1] >= 'b' && map.map[y][x - 1] <= 'd'))
		return (ft_vinit(x - 1, y));
	if ((y > 0) && (y * 1.0 == v.y) &&
		(map.map[y - 1][x] >= 'b' && map.map[y - 1][x] <= 'd'))
		return (ft_vinit(x, y - 1));
	if (map.map[y][x] >= 'b' && map.map[y][x] <= 'd')
		return (ft_vinit(x, y));
	return (ft_vinit(-1, -1));
}
