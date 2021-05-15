/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:52:15 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/28 15:54:33 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		key_hook(int keycode, t_vars *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	if (keycode == 49)
	{
		if (param->cur_cam->next != NULL)
			param->cur_cam = param->cur_cam->next;
		else
			param->cur_cam = param->scene->cam;
		transform_mat(param->cur_cam);
		get_trasing(param->scene, param->img, param->cur_cam);
		mlx_put_image_to_window(param->mlx, param->win, param->img->img, 0, 0);
	}
	return (0);
}
