/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:22:58 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/21 18:02:15 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	cub3d_exec(t_data *data)
{
	double	x;

	x = 0;
	while (x < data->info.screen.x)
	{
		data->info.camera.x = 2 * x / (data->info.screen.x) - 1;
		data->info.raydir.x = data->info.dir.x + data->info.plane.x
			* data->info.camera.x;
		data->info.raydir.y = data->info.dir.y + data->info.plane.y
			* data->info.camera.y;
		data->info.box.x = (int)data->info.player.x;
		data->info.box.y = (int)data->info.player.y;
		if (data->info.raydir.x == 0)
			data->info.deltaDis.x = 1e30;
		else
			data->info.deltaDis.x = fabs(1 / data->info.raydir.x);
		if (data->info.raydir.y == 0)
			data->info.deltaDis.y = 1e30;
		else
			data->info.deltaDis.y = fabs(1 / data->info.raydir.y);
		cub3d_exec2(data, x);
		x++;
		printf("X : %f, screen.x : %f\n", x , data->info.screen.x);
	}
	// printf("X : %f, data->info.screen.x : %f\n", x, data->info.screen.x);
	return (0);
}

void	cub3d_exec2(t_data *data, int x)
{
	if (data->info.raydir.x < 0)
	{
		data->info.step.x = -1;
		data->info.sideDis.x = (data->info.player.x - data->info.box.x)
			* data->info.deltaDis.x;
	}
	else
	{
		data->info.step.x = 1;
		data->info.sideDis.x = (data->info.box.x + 1.0 - data->info.player.x)
			* data->info.deltaDis.x;
	}
	if (data->info.raydir.y < 0)
	{
		data->info.step.y = -1;
		data->info.sideDis.y = (data->info.player.y - data->info.box.y)
			* data->info.deltaDis.y;
	}
	else
	{
		data->info.step.y = 1;
		data->info.sideDis.y = (data->info.box.y + 1.0 - data->info.player.y)
			* data->info.deltaDis.y;
	}
	cub3d_exec3(data, x);
}

void	cub3d_exec3(t_data *data, int x)
{
	while (data->info.hit == 0)
	{
		if (data->info.sideDis.x < data->info.sideDis.y)
		{
			data->info.sideDis.x += data->info.deltaDis.x;
			data->info.box.x += data->info.step.x;
			data->info.side = 0;
		}
		else
		{
			data->info.sideDis.y += data->info.deltaDis.y;
			data->info.box.y += data->info.step.y;
			data->info.side = 1;
		}
		if (data->info.map[(int)data->info.box.x][(int)data->info.box.y] > 0)
			data->info.hit = 1;
	}
	if (data->info.side == 1)
		data->info.perpWallDist = (data->info.sideDis.x
				- data->info.deltaDis.x);
	else
		data->info.perpWallDist = (data->info.sideDis.y
				- data->info.deltaDis.y);
	cub3d_exec4(data, x);
}

void	cub3d_exec4(t_data *data, int x)
{
	int			lineHeight;
	int			drawStart;
	int			drawEnd;

	lineHeight = (int)(data->info.screen.y / data->info.perpWallDist);
	drawStart = -lineHeight / 2 + (int)data->info.screen.y / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + (int)data->info.screen.y / 2;
	if (drawEnd >= data->info.screen.y)
		drawEnd = (int)data->info.screen.y - 1;
	verticalLine(data, x, drawStart, drawEnd, 0xFF0000);
}