/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:19:00 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/28 21:30:56 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "minilibx_mms/mlx.h"
# include "libft/libft.h"
# include "parser/parser.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

# define PI 3.14159265
# define EPS 0.00001
# define BMP_HEADER_SIZE 14
# define BMP_INFOHEADER_SIZE 40
# define BACKGROUND_COLOR 0x00AAAAAA

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_ray
{
	t_vect	orig;
	t_vect	dir;
}				t_ray;

typedef struct	s_inter
{
	double	close_t;
	double	dist1;
	double	dist2;
	t_vect	vec_n;
	t_vect	xyz;
	t_shape	*close_shape;
}				t_inter;

typedef struct	s_trgl
{
	t_vect	a;
	t_vect	b;
	t_vect	c;
	t_vect	ab;
	t_vect	ac;
	t_vect	bc;
	double	s_abc;
}				t_trgl;

typedef struct	s_sqr
{
	t_vect	centr;
	t_vect	vr;
	t_vect	vup;
	double	half_side;
}				t_sqr;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_scene	*scene;
	t_base	*cur_cam;
	t_data	*img;
}				t_vars;

typedef struct	s_surface
{
	t_vect	color;
	t_vect	vec_n;
	t_vect	point;
}				t_surface;

void			error_exit(int code);

double			len_vec(t_vect v);
t_vect			norm_vec(t_vect v);
double			dot_vec(t_vect v1, t_vect v2);
t_vect			cross_vec(t_vect v1, t_vect v2);
t_vect			add_vec(t_vect v1, t_vect v2);
t_vect			sub_vec(t_vect v1, t_vect v2);
t_vect			mult_vec(t_vect v, double num);
t_vect			mult_vec_vec(t_vect v1, t_vect v2);
double			**mat_alloc(int n, int m);
void			mat_free(double **mat);
double			**unit_matrix(int n, int m);
t_vect			mult_mat_vec3(double **mat, t_vect v);
t_vect			mult_mat_vec4(double **mat, t_vect v);
void			transform_mat(t_base *cam);
double			geron_square(t_vect ab, t_vect ac, t_vect bc);

void			get_trasing(t_scene *scene, t_data *img, t_base *cur_cam);
int				trase_ray(t_scene *scene, t_ray *ray);
void			intersect_ray(t_ray *ray, t_inter *inter, t_shape *shape, \
				int (f)(t_ray*, t_shape*, t_inter*));
int				intersect_ray_sp(t_ray *ray, t_shape *sp, t_inter *inter_sp);
int				intersect_ray_pl(t_ray *ray, t_shape *pl, t_inter *inter_pl);
int				intersect_ray_tr(t_ray *ray, t_shape *tr, t_inter *inter_tr);
int				intersect_ray_sq(t_ray *ray, t_shape *sq, t_inter *inter_sq);
int				intersect_ray_cy(t_ray *ray, t_shape *cy, t_inter *inter_cy);
void			def_close_point(t_inter *inter, t_shape *shape);
t_inter			init_intersec();
t_ray			def_ray(t_scene *scene, t_base *cam, double x, double y);
t_vect			dir_vnorm(t_vect vec_n, t_ray *ray);

t_vect			get_vec_color(t_vect color);
int				get_int_color(t_vect color);
t_vect			vec_n_shape(t_inter *inter, t_ray *ray);
t_vect			total_light(t_scene *scene, t_ray *ray, t_inter *inter);
t_vect			diff_light(t_base *light, t_vect n, t_vect l);
t_vect			amb_light(t_base *alight, t_vect n, t_vect v);
t_vect			spec_light(t_base *light, t_vect n, t_vect l, t_vect v);
int				def_shadow(t_scene *scene, t_base *light, t_inter *inter);

t_ray			def_shadray(t_base *light, t_inter *shad_int);
t_inter			init_shadinter(t_inter *inter, t_base *light, t_ray *shadray);
int				inter_shadray(t_ray *ray, t_inter *shad_int, t_shape *shape, \
				int (f)(t_ray*, t_shape*, t_inter*));
int				trase_shadray(t_scene *scene, t_ray *ray, t_inter *close_shad);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				key_hook(int keycode, t_vars *param);

t_scene			*init_scene(void);
int				pars_data(t_vars *param, char *filename);
void			render(t_vars *param, int argc);
int				ft_close(int keycode, t_vars *param);

void			img_to_bmp(t_vars *param, char *filename);
void			input_info_header(t_vars *param, int fd);
void			input_header(t_vars *param, int fd);
void			save_img(int argc, t_vars *param);

#endif
