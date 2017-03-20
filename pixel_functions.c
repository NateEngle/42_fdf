/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:49:19 by nengle-           #+#    #+#             */
/*   Updated: 2017/03/20 14:49:22 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(void *mlx, void *win, int x, int y, int x1, int y1)
{
	int sx;
	int sy;
	int m;
	int b;

	sx = ((x1 - x) < 0) ? -1 : 1;
	sy = ((y1 - y) < 0) ? -1 : 1;
	m = (abs(y1 - y) < abs(x1 - x) ? (y1 - y)/(x1 - x) : (x1 - x)/(y1 - y));
	b = (abs(y1 - y) < abs(x1 - x) ? y - (m * x) : x - (m * y));
	if (abs(y1 - y) < abs(x1 - x))
	{
		while (x <= x1)
		{
			mlx_pixel_put(mlx, win, x, ceil(m*x + b), 0x00FFFFFF);
			x = x + sx;
		}
	}
	else
	{
		while (y <= y1)
		{
			mlx_pixel_put(mlx, win, ceil(m*y + b), y, 0x00FFFFFF);
			y = y + sy;
		}
	}
}
