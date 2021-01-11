/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:15:54 by joopark           #+#    #+#             */
/*   Updated: 2021/01/11 14:44:25 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_init_key(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->r = 0;
	keys->l = 0;
	keys->esc = 0;
}

int					ft_push_key(int key, t_keys *keys)
{
	if (key == 0x35)
		keys->esc = 1;
	else if (key == 0x02)
		keys->d = 1;
	else if (key == 0x01)
		keys->s = 1;
	else if (key == 0x00)
		keys->a = 1;
	else if (key == 0x0d)
		keys->w = 1;
	else if (key == 0x7b)
		keys->l = 1;
	else if (key == 0x7c)
		keys->r = 1;
	return (0);
}

int					ft_pull_key(int key, t_keys *keys)
{
	if (key == 0x35)
		keys->esc = 0;
	else if (key == 0x02)
		keys->d = 0;
	else if (key == 0x01)
		keys->s = 0;
	else if (key == 0x00)
		keys->a = 0;
	else if (key == 0x0d)
		keys->w = 0;
	else if (key == 0x7b)
		keys->l = 0;
	else if (key == 0x7c)
		keys->r = 0;
	return (0);
}

int					ft_key_ispressed(t_keys *keys)
{
	if (keys->esc == 1)
		return (1);
	else if (keys->w == 1)
		return (1);
	else if (keys->a == 1)
		return (1);
	else if (keys->s == 1)
		return (1);
	else if (keys->d == 1)
		return (1);
	else if (keys->r == 1)
		return (1);
	else if (keys->l == 1)
		return (1);
	return (0);
}
