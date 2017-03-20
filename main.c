/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:46:19 by nengle-           #+#    #+#             */
/*   Updated: 2017/03/05 14:46:20 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*create a 2D array with all the vectors that represent the points. read the file and get a line, this line will go into new[0][n]. So read, gnl, parse individual numbers, set vector values. find num columns,
num rows. 


map of stuff will take in a line and the size of the map and return a 2D int array. this array will befilled with a 3D vector for each point. so each 3d vector will be an array with 3numbers in it x,y,z.
*/

int my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(1);
	return ((int)param);
}
int row_num(int fd)
{
	int count;
	int ret;
	char buf[2];

	ret = 0;
	count = 0;
	while ((ret = read(fd, buf, 1) != 0))
	{
		if (buf[0] == '\n')
			count++;
	}
	return (count);
}

int column_num(int fd)
{
	int i;
	char *line;

	i = 0;
	get_next_line(fd, &line);
	while (line && *line != '\0')
	{
		if (ft_isdigit(*line) && (*(line + 1) == ' ' || *(line + 1) == '\0'))
			i++;
		line++;
	}
	return (i);
}

int **map_of_stuff(char *av, int row, int col)
{
	int **map;
	char *line;
	char **new;
	int i;
	int j;
	
	i = 0;
	int fd = open(av, O_RDONLY);
	if (!(map = (int **)malloc(sizeof(int *) * row)))
		return (NULL);
	while (i < row)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * (col + 1))))
			return (NULL);
		if ((get_next_line(fd, &line)) < 1)
			break;
		new = ft_strsplit(line, ' ');
		j = -1;
		while(++j < col)
			map[i][j] = ft_atoi(new[j]);
		ft_memdel((void **)new);
		ft_memdel((void **)&line);
		i++;
	}
	return (map);
 }

int main(int ac, char **av)
{
	// t_list *list;
	void *mlx;
	void *win;
	
	if (((mlx = mlx_init()) == NULL || ((win = mlx_new_window(mlx, 1000, 1000, "mlx_42")) == NULL)))
		return (1);
	// list = NULL;
	// if (ac != 2)
	// 	return (1);
	// list = reader(open(av[1], O_RDONLY), mlx, win);
	if (ac == 2)
	{
		int row; 
		int col;
		row = row_num(open(av[1], O_RDONLY));
		col = column_num(open(av[1], O_RDONLY));
		// int **map = map_of_stuff(av[1], row, col);
		int x = 0;
		int y;
		while (x < row)
		{
			y = 0;
			while (y + 1 < col)
			{
				draw_line(mlx, win, 500 + (10*x), 500 + (10*y), 500 + (10*x), 500 + (10*(y + 1)));
				y++;
			}
			x++;
		}
		y = 0;
		while (y < col)
		{
			x = 0;
			while (x + 1 < row)
			{
				draw_line(mlx, win, 500 + (10*x), 500 + (10*y), 500 + (10*(x+1)), 500 + (10*y));
				x++;
			}
			y++;
		}
		mlx_key_hook(win, my_key_funct, 0);
		mlx_loop(mlx);
		}
	return (0);
}
