/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:45:48 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/28 15:46:03 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_ray	def_ray(t_scene *scene, t_base *cam, double x, double y)
{
	t_ray	ray;
	double	fov;

	ray.orig = cam->xyz;
	fov = tan(0.5 * cam->fov * PI / 180);
	ray.dir.x = (2 * (x + 0.5) / (double)scene->width - 1) * \
				scene->img_rat * fov;
	ray.dir.y = (1 - 2 * (y + 0.5) / (double)scene->height) * fov;
	ray.dir.z = -1;
	ray.dir = norm_vec(ray.dir);
	ray.dir = norm_vec(mult_mat_vec3(cam->transform_mat, ray.dir));
	return (ray);
}

t_inter	init_intersec(void)
{
	t_inter close_point;

	close_point.close_shape = NULL;
	close_point.close_t = INFINITY;
	close_point.dist1 = 0;
	close_point.dist2 = 0;
	return (close_point);
}

void	def_close_point(t_inter *inter, t_shape *shape)
{
	if (inter->dist1 > 0 && inter->dist1 < inter->close_t)
	{
		inter->close_t = inter->dist1;
		inter->close_shape = shape;
	}
}

void	intersect_ray(t_ray *ray, t_inter *inter, t_shape *shape, \
		int (f)(t_ray*, t_shape*, t_inter*))
{
	t_shape *fst_shape;

	fst_shape = shape;
	while (shape != NULL)
	{
		if ((f)(ray, shape, inter))
			def_close_point(inter, shape);
		shape = shape->next;
	}
	shape = fst_shape;
}
