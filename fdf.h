/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:55:11 by nengle-           #+#    #+#             */
/*   Updated: 2017/03/05 14:55:15 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

void draw_line(void *mlx, void *win, int x, int y, int x1, int y1);
int row_num(int fd);
int column_num(int fd);
int **map_of_stuff(char *av, int row, int col);


typedef struct
{
	short	x;
	short	y;
}			_2D;

typedef struct
{
	float	x;
	float	y;
	float	z;
}			_3D;

typedef struct
{
	_3D			local;
	_3D			world;
	_3D			aligned;
}				vertex_t;

#endif
