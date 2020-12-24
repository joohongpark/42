/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:39:08 by joopark           #+#    #+#             */
/*   Updated: 2020/12/23 21:39:24 by joopark          ###   ########.fr       */
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

t_vector		ft_vscala(t_vector v, double s)
{
	v.x *= s;
	v.y *= s;
	return (v);
}


t_vector		ft_vspin(t_vector v, int degree)
{
	double		sine;
	double		cosine;
	t_vector	rtn;

	sine = sin((degree / 360.0) * 2 * M_PI);
	cosine = cos((degree / 360.0) * 2 * M_PI);
	rtn.x = cosine * v.x - sine * v.y;
	rtn.y = sine * v.x + cosine * v.y;
	return (rtn);
}

double			ft_vsize(t_vector v)
{
	double		rtn;

	rtn = sqrt((v.x * v.x) + (v.y * v.y));
	return (rtn);
}