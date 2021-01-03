/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:45:54 by joopark           #+#    #+#             */
/*   Updated: 2021/01/02 21:54:52 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector			ft_raycasting(t_vector p, t_vector r, t_map m)
{
	t_vector		xgo;
	t_vector		ygo;
	double			xlen;
	double			ylen;

	xgo = ft_xstart(p, r);
	ygo = ft_xstart(ft_vinit(p.y, p.x), ft_vinit(r.y, r.x));
	while (ft_checkspace(xgo, m) == 1)
		xgo = ft_xinc(xgo, r);
	while (ft_checkspace(ft_vinit(ygo.y, ygo.x), m) == 1)
		ygo = ft_xinc(ygo, ft_vinit(r.y, r.x));
	ygo = ft_vinit(ygo.y, ygo.x);
	xlen = (xgo.x - p.x) * (xgo.x - p.x) + (xgo.y - p.y) * (xgo.y - p.y);
	ylen = (ygo.x - p.x) * (ygo.x - p.x) + (ygo.y - p.y) * (ygo.y - p.y);
	return ((xlen > ylen) ? ygo : xgo);
}

t_vector			ft_xstart(t_vector player, t_vector ray)
{
	t_vector		rtn;

	// 광선의 방향에 따라 y 절편에 닿는 방향?이 달라짐. (광선의 x방향 증분에 따라 변하므로)
	rtn.x = (int) player.x + (ray.x > 0 ? 1 : 0);
	// 직선 방정식을 이용해 y 점을 구함.
	rtn.y = (rtn.x - player.x) * (ray.y/ray.x) + player.y;
	return (rtn);
}

t_vector			ft_xinc(t_vector xgo, t_vector r)
{
	double			delta;

	delta = r.y / r.x;
	if (r.x > 0)
	{
		xgo.x += 1;
		xgo.y += delta;
	}
	else
	{
		xgo.x -= 1;
		xgo.y -= delta;
	}
	return (xgo);
}

int					ft_checkspace(t_vector v, t_map map)
{
	int				x;
	int				y;

	if (isnan(v.x) || isnan(v.y) || isinf(v.x) || isinf(v.y)
		|| v.x < 0 || v.y < 0 || map.x <= v.x || map.y <= v.y)
		return (-1);
	x = (int)v.x;
	y = (int)v.y;
	if ((x > 0) && (x * 1.0 == v.x) && map.map[y][x - 1] == 1)
		return (0);
	if ((y > 0) && (y * 1.0 == v.y) && map.map[y - 1][x] == 1)
		return (0);
	if (map.map[y][x] == 1)
		return (0);
	return (1);
}

t_vector				ft_checksprite(t_vector v, t_map map)
{
	int				x;
	int				y;

	x = (int)v.x;
	y = (int)v.y;
	if ((x > 0) && (x * 1.0 == v.x) && map.map[y][x - 1] > 1)
		return (ft_vinit(x - 1, y));
	if ((y > 0) && (y * 1.0 == v.y) && map.map[y - 1][x] > 1)
		return (ft_vinit(x, y - 1));
	if (map.map[y][x] > 1)
		return (ft_vinit(x, y));
	return (ft_vinit(-1, -1));
}