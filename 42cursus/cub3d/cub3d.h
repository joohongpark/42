/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 02:17:10 by joopark           #+#    #+#             */
/*   Updated: 2020/12/28 16:26:30 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

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
	t_vector		pos;
}					t_img;

typedef struct		s_player
{
	int				deg;
	t_vector		pos;
	t_vector		cam;
	t_vector		plane;
}					t_player;

typedef struct		s_map
{
	char			**map;
	int				x;
	int				y;
}					t_map;

typedef struct		s_canvas
{
	void			*window;
	void			*canvas;
	int				width;
	int				height;
	int				draw;
	t_map			map;
	t_img			img;
	t_img			player;
	t_img			render;
	t_img			wallpaper;
	t_img			tmp[10];
	t_player		p;
}					t_canvas;

t_img				ft_get_img_form_xpm(void *window, char *uri);

void				ft_draw_wall_proto(t_img *img, int x, double y, int color);

t_vector			ft_vinit(double x, double y);
t_vector			ft_vadd(t_vector v, t_vector w);
t_vector			ft_vscala(t_vector v, double s);
t_vector			ft_vspin(t_vector v, int degree);
double				ft_vsize(t_vector v);

t_vector			ft_raycasting(t_vector p, t_vector r, t_map m);
t_vector			ft_xstart(t_vector player, t_vector ray);
t_vector			ft_xinc(t_vector xgo, t_vector r);
int					ft_checkspace(t_vector v, t_map map);

int					ft_makewall(t_vector w, unsigned char r, unsigned char g, unsigned char b);
char				ft_isnwse(t_vector start, t_vector end);
void				ft_draw_wall_proto(t_img *img, int x, double y, int color);

int					ft_rgba(char r, char g, char b, char a);
void				ft_rendering(t_player p, t_img *c, t_map m);
double				ft_resolution(double raw, t_vector cam, t_vector ray);
char				ft_decay(double raw);

#endif
