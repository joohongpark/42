/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:39:08 by joopark           #+#    #+#             */
/*   Updated: 2020/11/25 11:33:29 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector		ft_vinit(double x, double y)
{
	t_vector	rtn;

	rtn.x = x;
	rtn.y = y;
	return (rtn);
}

t_vector		ft_vadd(t_vector v, t_vector w)
{
	v.x += w.x;
	v.y += w.y;
	return (v);
}

t_vector		ft_vsub(t_vector v, t_vector w)
{
	v.x -= w.x;
	v.y -= w.y;
	return (v);
}

t_vector		ft_vscala(t_vector v, double s)
{
	v.x *= s;
	v.y *= s;
	return (v);
}