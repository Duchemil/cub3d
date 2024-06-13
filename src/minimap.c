/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:03:41 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/13 15:48:01 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_minimap(t_data *data)
{
	int	map_x;
	int	map_y;

	map_y = 0;
	while (map_y < data->info.rows)
	{
		map_x = 0;
		while (map_x < data->info.cols)
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

	if ((int)(data->info.player.y) == map_x && (int)(data->info.player.x) == map_y)
	{
		color = 0xFF0000;
	}
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
			print_texture(data, (map_x * data->info.rows / 2) + x + 30, (map_y
						* data->info.cols / 2) + y + 30, color);
			x++;
		}
		y++;
	}
}

// void	draw_cub(t_data *data, int i, int j, int color)
// {

// 	print_texture(data, i, j++, color);
// }
