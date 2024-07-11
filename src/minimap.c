/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:03:41 by lduchemi          #+#    #+#             */
/*   Updated: 2024/07/11 18:41:10 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_minimap(t_data *data)
{
	int map_x;
	int map_y;

	map_y = 0;
	get_max_size(data);
	while (map_y < data->max_size.x)
	{
		map_x = 0;
		while (map_x < data->max_size.y)
		{
			minimap_pixel(data, map_x, map_y, data->info.map[map_y][map_x]);
			map_x++;
		}
		map_y++;
	}
}

void	minimap_pixel(t_data *data, int map_x, int map_y, char type)
{
	int	color;
	int	x;
	int	y;

	if ((int)(data->info.player.y) == map_x
		&& (int)(data->info.player.x) == map_y)
		color = 0xFF0000;
	else if (type == '0')
		color = 0xFFFFFF;
	else if (type == '1')
		color = 0x808080;
	else
		color = 0x000000;
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			print_texture(data, (map_x * 5) + x + 30, (map_y
					* 5 ) + y + 30, color);
			x++;
		}
		y++;
	}
}

void	get_max_size(t_data *data)
{
	int	rows;
	int	cols;
	int	current_cols;

	rows = 0;
	cols = 0;
	while (data->info.map[rows] != NULL)
	{
		current_cols = 0;
		while (data->info.map[rows][current_cols] != '\0')
		{
			current_cols++;
		}
		if (current_cols > cols)
		{
			cols = current_cols;
		}
		rows++;
	}
	data->max_size.x = rows;
	data->max_size.y = cols;
}
