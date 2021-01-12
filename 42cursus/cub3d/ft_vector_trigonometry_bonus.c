/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_trigonometry_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:58:33 by joopark           #+#    #+#             */
/*   Updated: 2021/01/12 01:58:18 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vector			ft_vspin(t_vector v, int degree)
{
	double			sine;
	double			cosine;
	t_vector		rtn;

	sine = sin((degree / 360.0) * 2 * M_PI);
	cosine = cos((degree / 360.0) * 2 * M_PI);
	rtn.x = cosine * v.x - sine * v.y;
	rtn.y = sine * v.x + cosine * v.y;
	return (rtn);
}

double				ft_gettheta(t_vector v1, t_vector v2)
{
	double			denom;
	double			nom;
	double			rtn;

	denom = ft_vsize(v1) * ft_vsize(v2);
	nom = v1.x * v2.y - v1.y * v2.x;
	rtn = asin(nom / denom);
	return (rtn);
}
