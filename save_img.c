/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:14:28 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 18:28:05 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	input_header(t_vars *param, int fd)
{
	unsigned char	*header;
	int				size;

	header = ft_calloc(BMP_HEADER_SIZE, sizeof(unsigned char));
	size = BMP_HEADER_SIZE + BMP_INFOHEADER_SIZE + \
	(param->img->bits_per_pixel / 8 * param->scene->width) * \
	param->scene->height;
	if (header)
	{
		header[0] = (unsigned char)'B';
		header[1] = (unsigned char)'M';
		header[2] = (unsigned char)(size);
		header[3] = (unsigned char)(size >> 8);
		header[4] = (unsigned char)(size >> 16);
		header[5] = (unsigned char)(size >> 24);
		header[10] = (unsigned char)(BMP_HEADER_SIZE + BMP_INFOHEADER_SIZE);
		write(fd, header, BMP_HEADER_SIZE);
		free(header);
	}
}

void	input_info_header(t_vars *param, int fd)
{
	unsigned char	*header;
	int				width;
	int				height;

	header = ft_calloc(BMP_INFOHEADER_SIZE, sizeof(unsigned char));
	width = param->scene->width;
	height = param->scene->height;
	if (header)
	{
		header[0] = (unsigned char)(BMP_INFOHEADER_SIZE);
		header[4] = (unsigned char)(width);
		header[5] = (unsigned char)(width >> 8);
		header[6] = (unsigned char)(width >> 16);
		header[7] = (unsigned char)(width >> 24);
		header[8] = (unsigned char)(height);
		header[9] = (unsigned char)(height >> 8);
		header[10] = (unsigned char)(height >> 16);
		header[11] = (unsigned char)(height >> 24);
		header[12] = (unsigned char)(1);
		header[14] = (unsigned char)(param->img->bits_per_pixel);
		write(fd, header, BMP_INFOHEADER_SIZE);
		free(header);
	}
}

void	img_to_bmp(t_vars *param, char *filename)
{
	int				fd;
	int				x;
	int				y;
	unsigned int	*dst;

	if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644)))
	{
		input_header(param, fd);
		input_info_header(param, fd);
		y = param->scene->height - 1;
		while (y >= 0)
		{
			x = 0;
			while (x < param->scene->width)
			{
				dst = (unsigned int*)(param->img->addr + \
						param->img->line_length * y + \
						(param->img->bits_per_pixel / 8) * x);
				write(fd, dst, 4);
				x++;
			}
			y--;
		}
		close(fd);
	}
}

void	save_img(int argc, t_vars *param)
{
	if (argc == 3)
	{
		img_to_bmp(param, "image.bmp");
		exit(0);
	}
}
