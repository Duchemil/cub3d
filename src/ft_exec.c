/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:22:58 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/10 14:52:55 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	cub3d_exec(t_data *data)
{
	double	x;

	x = 0;
	data->info.perpWallDist = 0;
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
		cub3d_exec2(data, x);
		x++;
	}
	print_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

void	cub3d_exec2(t_data *data, int x)
{
	if (data->info.raydir.y == 0)
		data->info.deltaDist.y = 1e30;
	else
		data->info.deltaDist.y = abs_val(1.0f / data->info.raydir.y);
	data->info.hit = 0;
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
	cub3d_exec3(data, x);
}

void	cub3d_exec3(t_data *data, int x)
{
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
	while (data->info.hit == 0)
	{
		ft_info_hit(data);
	}
	cub3d_exec4(data, x);
}

void	cub3d_exec4(t_data *data, int x)
{
	int		lineheight;
	double	drawstart;

	if (data->info.side == 0)
		data->info.perpWallDist = (data->info.sideDist.x
				- data->info.deltaDist.x);
	else
		data->info.perpWallDist = (data->info.sideDist.y
				- data->info.deltaDist.y);
	lineheight = (int)(data->info.screen.y / data->info.perpWallDist);
	drawstart = (double)(-lineheight) / 2 + data->info.screen.y / 2;
	if (drawstart < 0)
		drawstart = 0;
	data->info.step.x = data->info.player.x + (data->info.raydir.x
			* data->info.perpWallDist);
	data->info.step.y = data->info.player.y + (data->info.raydir.y
			* data->info.perpWallDist);
	cub3d_exec5(data, x, lineheight, drawstart);
}

void	cub3d_exec5(t_data *data, int x, int line_h, double dr_s)
{
	double	drawend;

	drawend = (double)line_h / 2 + data->info.screen.y / 2;
	if (drawend >= data->info.screen.y)
		drawend = data->info.screen.y - 1;
	if (data->info.side == 0)
		data->coord_texture = ((data->info.step.y - (int)data->info.step.y)
				* 64);
	if (data->info.side == 1)
		data->coord_texture = ((data->info.step.x - (int)data->info.step.x)
				* 64);
	data->info.wall_dir.x = data->info.step.x - data->info.player.x;
	data->info.wall_dir.y = data->info.step.y - data->info.player.y;
	choose_texture(data);
	data->info.line_step = 1.0 * 64 / line_h;
	data->info.text_pos = (dr_s - data->info.screen.y / 2 + (double)line_h / 2)
		* data->info.line_step;
	vertical_line(data, x, dr_s, drawend);
}
