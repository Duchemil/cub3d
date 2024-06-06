/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:26:55 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/06 17:18:06 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verticalLine(t_data *data, int x, double drawStart, double drawEnd, int color)
{
	double	height;

	height = 0;
	while (height < drawStart)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, (int)height, 0x0000FF);
		height++;
	}
	while(height <= drawEnd)
	{
		data->info.text.y = (int)data->info.text_pos & (64 - 1);
		data->info.text_pos += data->info.line_step;
		print_texture(data, x, height, 1);
		// if (data->info.side == 1)
		// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, (int)height, 0x7F0000);
		// else
		// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, (int)height, color);
		height++;
	}
	while (height < data->info.screen.y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, (int)height, 0x808080);
		height++;
	}
}

void	print_texture(t_data *data, int x, int y, int color)
{
	char	*dst;

	mlx_get_data_addr(data->textures[data->info.ttp])
}

void	choose_texture(t_data *data)
{
	if (data->info.side == 0 && data->info.dir.x < 0)
		data->info.ttp = 0;
	else if (data->info.side == 0 && data->info.dir.x > 0)
		data->info.ttp = 1;
	else if (data->info.side == 1 && data->info.dir.x < 0)
		data->info.ttp = 2;
	else if (data->info.side == 1 && data->info.dir.x >= 0)
		data->info.ttp = 3;
}
