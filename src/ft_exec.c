/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:22:58 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/27 13:43:50 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	cub3d_exec(t_data *data)
{
	double	x;

	x = 0;
	while (x < data->info.screen.x)
	{
		data->info.camera.x = 2.0f * x / data->info.screen.x - 1.0f;
		data->info.raydir.x = data->info.dir.x + data->info.plane.x
			* data->info.camera.x;
		data->info.raydir.y = data->info.dir.y + data->info.plane.y
			* data->info.camera.x;
		data->info.box.x = (int)data->info.player.x;
		data->info.box.y = (int)data->info.player.y;
		if (data->info.raydir.x == 0)
			data->info.deltaDist.x = 1e30;
		else
			data->info.deltaDist.x = abs_val(1.0f / data->info.raydir.x);
		if (data->info.raydir.y == 0)
			data->info.deltaDist.y = 1e30;
		else
			data->info.deltaDist.y = abs_val(1.0f / data->info.raydir.y);
		data->info.hit = 0;
		cub3d_exec2(data, x);
		x++;
	}
	return (0);
}

void	cub3d_exec2(t_data *data, int x)
{
	if (data->info.raydir.x < 0)
	{
		data->info.step.x = -1;
		data->info.sideDist.x = (data->info.player.x - data->info.box.x)
			* data->info.deltaDist.x;
	}
	else
	{
		data->info.step.x = 1;
		data->info.sideDist.x = (data->info.box.x + 1.0 - data->info.player.x)
			* data->info.deltaDist.x;
	}
	if (data->info.raydir.y < 0)
	{
		data->info.step.y = -1;
		data->info.sideDist.y = (data->info.player.y - data->info.box.y)
			* data->info.deltaDist.y;
	}
	else
	{
		data->info.step.y = 1;
		data->info.sideDist.y = (data->info.box.y + 1.0 - data->info.player.y)
			* data->info.deltaDist.y;
	}
	cub3d_exec3(data, x);
}

void	cub3d_exec3(t_data *data, int x)
{
	while (data->info.hit == 0)
	{
		if (data->info.sideDist.x < data->info.sideDist.y)
		{
			data->info.sideDist.x += data->info.deltaDist.x;
			data->info.box.x += data->info.step.x;
			data->info.side = 0;
		}
		else
		{
			data->info.sideDist.y += data->info.deltaDist.y;
			data->info.box.y += data->info.step.y;
			data->info.side = 1;
		}
		if (data->info.map[(int)data->info.box.x][(int)data->info.box.y] == '1')
			data->info.hit = 1;
	}
	if (data->info.side == 0)
		data->info.perpWallDist = (data->info.sideDist.x
				- data->info.deltaDist.x);
	else
		data->info.perpWallDist = (data->info.sideDist.y
				- data->info.deltaDist.y);
	cub3d_exec4(data, x);
}

void	cub3d_exec4(t_data *data, int x)
{
	int	lineHeight;
	double	drawStart;
	double	drawEnd;

	lineHeight = (int)(data->info.screen.y / data->info.perpWallDist);
	drawStart = (double)(-lineHeight) / 2 + data->info.screen.y / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = (double)lineHeight / 2 + data->info.screen.y / 2;
	if (drawEnd >= data->info.screen.y)
		drawEnd = data->info.screen.y - 1;
	verticalLine(data, x, drawStart, drawEnd, 0xFF0000);
}
