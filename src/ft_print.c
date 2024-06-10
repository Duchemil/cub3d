/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:26:55 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/10 15:23:00 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verticalLine(t_data *data, int x, double drawStart, double drawEnd)
{
	double	height;

	height = 0;
	while (height < drawStart)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, (int)height,
				data->ceiling_color);
		height++;
	}
	while (height <= drawEnd)
	{
		data->info.text.y = (int)data->info.text_pos & (64 - 1);
		data->info.text_pos += data->info.line_step;
		print_texture(data, x, height, get_pixel_color(data->info.ttp,
				data->coord_texture, data->tex_y));
		height++;
	}
	while (height < data->info.screen.y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, (int)height,
				data->floor_color);
		height++;
	}
}

void	print_texture(t_data *data, int x, int y, int color)
{
	char	*dst;

	choose_texture(data);
	mlx_get_data_addr(data->info.ttp.img_m, (int *)32, &data->line_length,
			&data->endian);
	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int *)dst = color;
}

void	choose_texture(t_data *data)
{
	if (data->info.side == 0 && data->info.dir.x < 0)
		data->info.ttp = data->SO;
	else if (data->info.side == 0 && data->info.dir.x > 0)
		data->info.ttp = data->NO;
	else if (data->info.side == 1 && data->info.dir.x < 0)
		data->info.ttp = data->EA;
	else if (data->info.side == 1 && data->info.dir.x >= 0)
		data->info.ttp = data->WE;
}

int	get_pixel_color(t_data *data, t_img *img, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = img->addr + (y * data->line_length + x
			* (data->line_length / 8));
	return (*(unsigned int *)pixel_addr);
}
