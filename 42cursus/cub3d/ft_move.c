/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:59:03 by joopark           #+#    #+#             */
/*   Updated: 2021/01/04 15:07:34 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector		ft_gotoxy(t_vector start, t_vector delta, t_map map)
{
	t_vector	rtn;

	rtn = ft_vadd(start, delta);
	if (rtn.x < 0)
		rtn.x = 0;
	if (rtn.y < 0)
		rtn.y = 0;
	if (rtn.x > map.x)
		rtn.x = map.x;
	if (rtn.y > map.y)
		rtn.y = map.y;
	if (map.map[(int)rtn.y][(int)rtn.x] != 0)
	{
		if (map.map[(int)start.y][(int)rtn.x] == 0)
			rtn.y = start.y;
		else if (map.map[(int)rtn.y][(int)start.x] == 0)
			rtn.x = start.x;
		else
			rtn = start;
	}
	return (rtn);
}

t_vector		ft_getdelta(int look, double delta)
{
	t_vector	rtn;

	if (look < 0)
		look = 360 + look;
	else if (look > 360)
		look = look - 360;
	rtn = ft_vinit(delta, 0);
	rtn = ft_vspin(rtn, look);
	return (rtn);
}
