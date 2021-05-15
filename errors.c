/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:04:47 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 18:04:52 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	error_exit(int code)
{
	if (code == 1)
		write(STDERR_FILENO, \
		"Error\nNon-valid scene in fd\n", 28);
	if (code == -1)
		write(STDERR_FILENO, "Error\nNo allocated memory\n", 26);
	if (code == 2)
		write(STDERR_FILENO, "Error\nError reading file\n", 25);
	if (code == 3)
		write(STDERR_FILENO, "Error\nNon-valid struct data\n", 28);
	if (code == 4)
		write(STDERR_FILENO, "Error\nUndefined argv[2]\n", 24);
	exit(code);
}
