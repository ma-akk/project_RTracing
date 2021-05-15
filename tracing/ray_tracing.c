/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trasing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:38:26 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/28 15:47:33 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		trase_ray(t_scene *scene, t_ray *ray)
{
	t_inter	inter;
	t_vect	color;

	inter = init_intersec();
	intersect_ray(ray, &inter, scene->sp, intersect_ray_sp);
	intersect_ray(ray, &inter, scene->pl, intersect_ray_pl);
	intersect_ray(ray, &inter, scene->tr, intersect_ray_tr);
	intersect_ray(ray, &inter, scene->sq, intersect_ray_sq);
	intersect_ray(ray, &inter, scene->cy, intersect_ray_cy);
	if (inter.close_shape == NULL)
		return (BACKGROUND_COLOR);
	inter.xyz = add_vec(ray->orig, mult_vec(ray->dir, inter.close_t));
	inter.vec_n = vec_n_shape(&inter, ray);
	color = total_light(scene, ray, &inter);
	color = mult_vec_vec(inter.close_shape->vec_rgb, color);
	return (get_int_color(color));
}

void	get_trasing(t_scene *scene, t_data *img, t_base *cur_cam)
{
	double	x;
	double	y;
	double	x_screen;
	double	y_screen;
	t_ray	ray;

	y = scene->height / 2;
	while (y > -(scene->height / 2))
	{
		x = -scene->width / 2;
		while (x < (scene->width / 2))
		{
			x_screen = (scene->width / 2) + x;
			y_screen = (scene->height / 2) - y;
			ray = def_ray(scene, cur_cam, x_screen, y_screen);
			my_mlx_pixel_put(img, x_screen, y_screen, trase_ray(scene, &ray));
			x++;
		}
		y--;
	}
}
