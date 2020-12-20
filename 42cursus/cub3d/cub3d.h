/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 02:17:10 by joopark           #+#    #+#             */
/*   Updated: 2020/12/20 17:02:32 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CUB3D_H
# define FT_CUB3D_H

typedef	struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

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
	t_vector		pos;
}					t_img;

typedef struct		s_player
{
	t_vector		pos;
	t_vector		cam;
	t_vector		plane;
}					t_player;

typedef struct		s_canvas
{
	void			*window;
	void			*canvas;
	int				width;
	int				height;
	int				draw;
	t_img			img;
	t_img			player;
	t_img			c;
	t_player		cam;
}					t_canvas;

typedef struct		s_map
{
	char			**map;
	int				x;
	int				y;
	int				scale;
}					t_map;

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

void			ft_draw_wall_proto(t_img *img, int x, double y);

t_vector		ft_vinit(double x, double y);
t_vector		ft_vadd(t_vector v, t_vector w);
t_vector		ft_vsub(t_vector v, t_vector w);
t_vector		ft_vscala(t_vector v, double s);
t_vector		ft_vspin(t_vector v, int degree);

double				ft_raycasting(t_vector p, t_vector r, t_map m);
t_vector			ft_xstart(t_vector player, t_vector ray);
t_vector			ft_xinc(t_vector xgo, t_vector r);
int					ft_checkspace(t_vector v, t_map map);

#endif
