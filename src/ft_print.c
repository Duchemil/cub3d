/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:26:55 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/21 18:06:52 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verticalLine(t_data *data, int x, int drawStart, int drawEnd, int color)
{
	int	height;

	height = 0;
	// printf("drawstart : %d, end : %d\n", drawStart, drawEnd);
	while (height < drawEnd)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, height, 0x0000FF);
		height++;
	}
	while(height <= drawStart)
	{
		// printf("Height : %d\n", height);
		if (data->info.side == 1)
		{
			color = 0x7F0000;
			printf("Dimmer\n");
		}
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, height, color);
		height++;
	}
	while (height < data->info.screen.y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, height, 0xA52A2A);
		height++;
	}
}
