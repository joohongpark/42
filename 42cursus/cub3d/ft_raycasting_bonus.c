/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:45:54 by joopark           #+#    #+#             */
/*   Updated: 2021/01/12 01:58:08 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vector			ft_raycasting(t_vector p, t_vector r, t_map m)
{
	t_vector		xgo;
	t_vector		ygo;
	double			xlen;
	double			ylen;

	xgo = ft_xstart(p, r);
	ygo = ft_ystart(p, r);
	while (ft_checkspace(xgo, m) == 1)
		xgo = ft_xinc(xgo, r);
	while (ft_checkspace(ygo, m) == 1)
		ygo = ft_yinc(ygo, r);
	xlen = (xgo.x - p.x) * (xgo.x - p.x) + (xgo.y - p.y) * (xgo.y - p.y);
	ylen = (ygo.x - p.x) * (ygo.x - p.x) + (ygo.y - p.y) * (ygo.y - p.y);
	return ((xlen > ylen) ? ygo : xgo);
}

t_list				*ft_find_sprite(t_vector s, t_vector e, t_vector b, t_map m)
{
	t_list			*rtn;
	t_vector		tmp;
	t_vector		s1;
	double			delta;
	double			len;

	rtn = NULL;
	s1 = s;
	delta = fabs(e.y - s.y) / fabs(e.x - s.x);
	delta = isfinite(delta) ? delta : 2;
	b = (delta > 1) ? ft_vinit(b.y, b.x) : b;
	s = (delta > 1) ? ft_vinit(s.y, s.x) : s;
	s = ft_xstart(s, b);
	while (ft_checkspace((delta > 1) ? ft_vinit(s.y, s.x) : s, m) == 1)
	{
		tmp = ft_checksprite((delta > 1) ? ft_vinit(s.y, s.x) : s, m);
		if (tmp.x != -1)
			ft_push(&rtn, tmp);
		s = ft_xinc(s, b);
	}
	tmp = ft_checksprite((delta > 1) ? ft_vinit(s.y, s.x) : s, m);
	len = ft_vsize(ft_vsub(ft_vinit(tmp.x + 0.5, tmp.y + 0.5), s1));
	if ((tmp.x != -1) && (len < ft_vsize(ft_vsub(e, s1))))
		ft_push(&rtn, tmp);
	return (rtn);
}
