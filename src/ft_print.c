/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:26:55 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/11 15:56:10 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verticalLine(t_data *data, int x, double drawStart, double drawEnd)
{
	double	height;

	height = 0;
	while (height < drawStart)
	{
		print_texture(data, x, height, data->ceiling_color);
		height++;
	}
	while (height <= drawEnd)
	{
		data->info.text.y = (int)data->info.text_pos & (64 - 1);
		data->info.text_pos += data->info.line_step;
		print_texture(data, (double)x, height, get_pixel_color(data->info.ttp,
					data->coord_texture, data->info.text.y));
		height++;
	}
	while (height < data->info.screen.y)
	{
		print_texture(data, x, height, data->floor_color);
		height++;
	}
}

void	print_texture(t_data *data, int x, int y, int color)
{
	char	*dst;

	mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length,
			&data->endian);
	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int *)dst = color;
}

void	choose_texture(t_data *data)
{
	if (data->info.side == 0 && data->info.wall_dir.x < 0)
		data->info.ttp = &data->NO;
	else if (data->info.side == 0 && data->info.wall_dir.x > 0)
		data->info.ttp = &data->SO;
	else if (data->info.side == 1 && data->info.wall_dir.y < 0)
		data->info.ttp = &data->EA;
	else if (data->info.side == 1 && data->info.wall_dir.y >= 0)
		data->info.ttp = &data->WE;
}

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = img->addr + (y * img->line_length + x * (img->bits_per_pixel
				/ 8));
	return (*(unsigned int *)pixel_addr);
}
