/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 02:17:10 by joopark           #+#    #+#             */
/*   Updated: 2021/01/08 01:41:02 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <libft.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

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
	int				is_save;
	int				width;
	int				height;
	int				draw;
	int				floor_color;
	int				ceilling_color;
	t_map			map;
	t_img			render;
	t_img			sprite_rander;
	t_img			wallpaper;
	t_img			north_texture;
	t_img			south_texture;
	t_img			west_texture;
	t_img			east_texture;
	t_img			sprite_texture;
	t_player		p;
}					t_canvas;

t_img				ft_get_img_from_xpm(void *window, char *uri);

t_vector			ft_vinit(double x, double y);
t_vector			ft_vadd(t_vector v, t_vector w);
t_vector			ft_vsub(t_vector v, t_vector w);
t_vector			ft_vscala(t_vector v, double s);
double				ft_vsize(t_vector v);

t_vector			ft_vspin(t_vector v, int degree);
double				ft_gettheta(t_vector v1, t_vector v2);

void				ft_event_register(void *window, t_canvas *obj);
int					ft_key_press(int code, t_canvas *obj);
int					ft_key_press_test(int code, t_canvas *obj);
int					ft_mouse_press(int code, int x, int y, char *str);
int					ft_draw(t_canvas *obj);

t_vector			ft_gotoxy(t_vector start, t_vector delta, t_map map);
t_vector			ft_getdelta(int look, double delta);

t_vector			ft_raycasting(t_vector p, t_vector r, t_map m);
t_list				*ft_find_sprite(t_vector s, t_vector e, t_vector b, t_map m);

t_vector			ft_xstart(t_vector player, t_vector ray);
t_vector			ft_ystart(t_vector player, t_vector ray);
t_vector			ft_xinc(t_vector xgo, t_vector r);
t_vector			ft_yinc(t_vector ygo, t_vector r);

int					ft_checkspace(t_vector v, t_map map);
t_vector			ft_checksprite(t_vector v, t_map map);

double				ft_getxratio(t_vector w);
char				ft_isnwse(t_vector start, t_vector end);
t_img				*ft_ctoi(char wall, t_canvas *c);
void				ft_draw_clear_xline(t_img *img, int x);
void				ft_draw_yline(t_img *to, t_img from, t_vector scale, int x);

void				ft_rendering(t_canvas *canvas);
void				ft_draw_wall(t_canvas *c, int x, t_vector t, t_vector ray);
void				ft_draw_sprite(t_canvas *c, int x, t_vector t, t_vector ray);
double				ft_resolution(double raw, t_vector cam, t_vector ray);

int					ft_rgba(char r, char g, char b, char a);
t_img				ft_new_img(void *window, int width, int height);
t_img				ft_get_img_from_xpm(void *window, char *uri);
t_img				ft_get_img_from_png(void *window, char *uri);

t_vector			ft_push(t_list **list, t_vector v);
t_vector			ft_pop(t_list **list);

int					ft_arg(t_canvas *canvas, int argc, char *argv[]);
int					ft_ishavesaveflag(int argc, char *argv[]);
char				*ft_isfile(int argc, char *argv[]);
int					ft_canvas_isvaild(t_canvas *canvas);

int					ft_parser(char *dir, t_canvas *canvas);
int					ft_line_paraer(char *line, t_canvas *canvas);
int					ft_open_texture(char *uri, t_img *img, void *window);

char				*ft_strnstack(char *stack, char *str, size_t n);
char				*ft_getbuf(ssize_t clr, char **bp);
int					ft_prechk(int fd, char **line, char **bufrtn, char **bp);
int					ft_get_next_line(int fd, char **line, char **bp);

#endif
