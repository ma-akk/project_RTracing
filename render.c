/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 17:47:57 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/28 17:48:33 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_scene	*init_scene(void)
{
	t_scene *on_scene;

	if ((on_scene = (t_scene*)malloc(sizeof(t_scene))))
	{
		on_scene->width = 0;
		on_scene->height = 0;
		on_scene->alight = NULL;
		on_scene->light = NULL;
		on_scene->cam = NULL;
		on_scene->sp = NULL;
		on_scene->pl = NULL;
		on_scene->sq = NULL;
		on_scene->cy = NULL;
		on_scene->tr = NULL;
	}
	else
		error_exit(-1);
	return (on_scene);
}

int		pars_data(t_vars *param, char *filename)
{
	int parsing;
	int fd;

	if (ft_strnstr(filename, ".rt", ft_strlen(filename)))
		if (filename[0] != '.')
		{
			fd = open(filename, O_RDWR);
			parsing = parser_scene(param->scene, fd);
			close(fd);
			if (!(parsing))
			{
				if (valid_base(param->scene) || valid_shape(param->scene))
					return (3);
			}
			else
				return (parsing);
			return (0);
		}
	return (2);
}

void	render(t_vars *param, int argc)
{
	int x_screen;
	int y_screen;

	mlx_get_screen_size(param->mlx, &x_screen, &y_screen);
	if (param->scene->width > x_screen)
		param->scene->width = x_screen;
	if (param->scene->height > y_screen)
		param->scene->height = y_screen;
	param->scene->img_rat = (double)param->scene->width / (double)\
	param->scene->height;
	param->cur_cam = param->scene->cam;
	transform_mat(param->cur_cam);
	get_trasing(param->scene, param->img, param->cur_cam);
	save_img(argc, param);
	param->win = mlx_new_window(param->mlx, param->scene->width, \
	param->scene->height, "miniRT");
	mlx_put_image_to_window(param->mlx, param->win, param->img->img, 0, 0);
}
