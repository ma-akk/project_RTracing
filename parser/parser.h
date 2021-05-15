/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:59:23 by gtresa            #+#    #+#             */
/*   Updated: 2021/03/04 13:01:41 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define ID_EMPT 0b00000000
# define ID_SP 0b00000001
# define ID_PL 0b00000010
# define ID_SQ 0b00000100
# define ID_CY 0b00001000
# define ID_TR 0b00010000
# define ID_C 0b00100000
# define ID_L 0b01000000
# define ID_ERR 0b10000000

typedef struct	s_vect
{
	double x;
	double y;
	double z;
}				t_vect;

typedef struct	s_base
{
	unsigned char	id;
	t_vect			xyz;
	double			bright;
	t_vect			color;
	t_vect			vec_rgb;
	t_vect			v_orient;
	double			fov;
	double			**transform_mat;
	struct s_base	*next;
}				t_base;

typedef struct	s_shape
{
	unsigned char	id;
	t_vect			xyz;
	double			dim;
	t_vect			color;
	t_vect			vec_rgb;
	t_vect			v_orient;
	double			height;
	t_vect			pos_xyz1;
	t_vect			pos_xyz2;
	struct s_shape	*next;
}				t_shape;

typedef struct	s_scene
{
	int		width;
	int		height;
	double	img_rat;
	t_base	*alight;
	t_base	*cam;
	t_base	*light;
	t_shape	*sp;
	t_shape	*pl;
	t_shape	*sq;
	t_shape	*cy;
	t_shape	*tr;
}				t_scene;

t_shape			*init_shape(unsigned char id);
t_base			*init_base(unsigned char	id);
t_vect			init_vec(double x, double y, double z);
void			add_base(t_base **base, t_base *newb);
void			add_shape(t_shape **shape, t_shape *news);
int				check_endofline(char *line);
int				skip_space(char *line);
int				skip_digit(char *line);
int				input_vec(char *line, t_vect *vec);
int				check_vec_norm(t_vect vec);
int				check_value(char *line, int fl_vec);
int				check_rgb(char *line, double *color);
int				parser_color(char *line, t_vect *new_color);
int				parser_scene(t_scene *on_scene, int fd);
int				parser_id(char *line, t_scene *on_scene);
int				parser_resol(char *line, t_scene *on_scene);
int				parser_alight(char *line, t_scene *on_scene);
int				parser_camera(char *line, t_scene *on_scene);
int				parser_light(char *line, t_scene *on_scene);
int				parser_sp(char *line, t_scene *on_scene);
int				parser_pl(char *line, t_scene *on_scene);
int				parser_sq(char *line, t_scene *on_scene);
int				parser_cy(char *line, t_scene *on_scene);
int				parser_tr(char *line, t_scene *on_scene);
int				valid_shape(t_scene *on_scene);
int				valid_sp_pl(t_scene *on_scene);
int				valid_base(t_scene *on_scene);
int				valid_cam_light(t_scene *on_scene);
#endif
