/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:26:55 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/22 17:40:10 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verticalLine(t_data *data, int x, double drawStart, double drawEnd, int color)
{
	double	height;

	height = 0;
	// printf("drawstart : %f, end : %f\n", drawStart, drawEnd);
	while (height < drawStart)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, (int)height, 0x0000FF);
		height++;
	}
	while(height <= drawEnd)
	{
		// printf("Height : %f\n", height);
		if (data->info.side == 1)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, (int)height, 0x7F0000);
		else
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, (int)height, color);
		height++;
	}
	while (height < data->info.screen.y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, (int)height, 0x808080);
		height++;
	}
}
