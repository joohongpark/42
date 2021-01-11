/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:59:03 by joopark           #+#    #+#             */
/*   Updated: 2021/01/11 14:11:14 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector			ft_gotoxy(t_vector start, t_vector delta, t_map map)
{
	t_vector		rtn;

	rtn = ft_vadd(start, delta);
	if (rtn.x < 0)
		rtn.x = 0;
	if (rtn.y < 0)
		rtn.y = 0;
	if (rtn.x > map.x)
		rtn.x = map.x;
	if (rtn.y > map.y)
		rtn.y = map.y;
	if (map.map[(int)rtn.y][(int)rtn.x] != SPACE)
	{
		if (map.map[(int)start.y][(int)rtn.x] == SPACE)
			rtn.y = start.y;
		else if (map.map[(int)rtn.y][(int)start.x] == SPACE)
			rtn.x = start.x;
		else
			rtn = start;
	}
	return (rtn);
}

t_vector			ft_getdelta(int look, double delta)
{
	t_vector		rtn;

	if (look < 0)
		look = 360 + look;
	else if (look > 360)
		look = look - 360;
	rtn = ft_vinit(delta, 0);
	rtn = ft_vspin(rtn, look);
	return (rtn);
}

int					ft_okgo(t_canvas *o)
{
	double			d;

	d = 0.05;
	if (o->keys.esc == 1)
		exit(0);
	if (o->keys.d == 1)
		o->p.pos = ft_gotoxy(o->p.pos, ft_getdelta(o->p.deg + 90, d), o->map);
	if (o->keys.s == 1)
		o->p.pos = ft_gotoxy(o->p.pos, ft_getdelta(o->p.deg - 180, d), o->map);
	if (o->keys.a == 1)
		o->p.pos = ft_gotoxy(o->p.pos, ft_getdelta(o->p.deg - 90, d), o->map);
	if (o->keys.w == 1)
		o->p.pos = ft_gotoxy(o->p.pos, ft_getdelta(o->p.deg, d), o->map);
	if (o->keys.l == 1)
		o->p.deg -= (0 < o->p.deg) ? 1 : -360;
	if (o->keys.r == 1)
		o->p.deg += (360 > o->p.deg) ? 1 : -360;
	return (0);
}
