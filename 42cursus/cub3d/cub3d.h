/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 02:17:10 by joopark           #+#    #+#             */
/*   Updated: 2020/12/07 20:52:22 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CUB3D_H
# define FT_CUB3D_H

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				x;
	int				y;
	int				deg;
}					t_img;

typedef struct		s_canvas
{
	void			*window;
	void			*canvas;
	int				width;
	int				height;
	int				draw;
	t_img			img;
	t_img			player;
}					t_canvas;

typedef struct		s_map
{
	char			**map;
	int				x;
	int				y;
	int				scale;
}					t_map;

typedef	struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

t_vector		ft_vinit(double x, double y);
t_vector		ft_vadd(t_vector v, t_vector w);
t_vector		ft_vsub(t_vector v, t_vector w);
t_vector		ft_vscala(t_vector v, double s);



#endif
