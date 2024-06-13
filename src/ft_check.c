/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:03:19 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/13 16:40:36 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_cub(char *filename)
{
	int		len;
	int		fd;
	char	c;
	int		x;

	len = 0;
	x = 0;
	while (filename[len])
		len++;
	if (len < 4)
		return (0);
	if (filename[len - 4] == '.' && filename[len - 3] == 'c' && filename[len
		- 2] == 'u' && filename[len - 1] == 'b')
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (0);
		while (read(fd, &c, 1) > 0)
		{
			if (c != '\n')
				x++;
		}
		return (x);
	}
	return (0);
}

int	ft_check_comps(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->info.rows)
	{
		y = 0;
		while (data->info.map[x][y] != '\n')
		{
			if (data->info.map[x][y] == '0' || data->info.map[x][y] == '1'
				|| data->info.map[x][y] == 'N' || data->info.map[x][y] == 'E'
				|| data->info.map[x][y] == 'W' || data->info.map[x][y] == 'S'
				|| data->info.map[x][y] == 'A' || data->info.map[x][y] == 'D')
				y++;
			else
				return (0);
		}
		x++;
	}
	return (1);
}

int	ft_check_closed(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->info.rows)
	{
		y = 0;
		while (data->info.map[x][y])
		{
			if (((x == 0) || (x == data->info.rows))
				&& data->info.map[x][y] != '1' && data->info.map[x][y] != '\n')
				return (0);
			if (data->info.map[x][y] == '\n' && y != 0)
			{
				if (data->info.map[x][y - 1] != '1')
					return (0);
			}
			if (x == data->info.rows - 1)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	init_img(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, 720, 480);
	if (!data->img_ptr)
		return (on_destroy(data), 1);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		return (on_destroy(data), 1);
	return (0);
}
