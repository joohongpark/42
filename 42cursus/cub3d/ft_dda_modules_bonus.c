/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda_modules_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:09:38 by joopark           #+#    #+#             */
/*   Updated: 2021/01/12 01:57:34 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vector			ft_xstart(t_vector player, t_vector ray)
{
	t_vector		rtn;

	rtn.x = (int)player.x + (ray.x > 0 ? 1 : 0);
	rtn.y = (rtn.x - player.x) * (ray.y / ray.x) + player.y;
	return (rtn);
}

t_vector			ft_ystart(t_vector player, t_vector ray)
{
	t_vector		rtn;

	rtn.y = (int)player.y + (ray.y > 0 ? 1 : 0);
	rtn.x = (rtn.y - player.y) * (ray.x / ray.y) + player.x;
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

t_vector			ft_yinc(t_vector ygo, t_vector r)
{
	double			delta;

	delta = r.x / r.y;
	if (r.y > 0)
	{
		ygo.y += 1;
		ygo.x += delta;
	}
	else
	{
		ygo.y -= 1;
		ygo.x -= delta;
	}
	return (ygo);
}
