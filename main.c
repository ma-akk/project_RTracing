/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:28:41 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/28 15:51:29 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_close(int keycode, t_vars *param)
{
	(void)keycode;
	(void)param;
	exit(0);
}

int		main(int argc, char *argv[])
{
	t_vars	param;
	t_data	img;
	int		err;

	param.scene = init_scene();
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		error_exit(4);
	if (argc == 2 || argc == 3)
	{
		if ((err = pars_data(&param, argv[1])))
			error_exit(err);
		param.mlx = mlx_init();
		img.img = mlx_new_image(param.mlx, param.scene->width, \
				param.scene->height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
				&img.line_length, &img.endian);
		param.img = &img;
		render(&param, argc);
		mlx_key_hook(param.win, key_hook, &param);
		mlx_hook(param.win, 17, (1L << 0), ft_close, &param);
		mlx_loop(param.mlx);
	}
	error_exit(2);
	return (0);
}
