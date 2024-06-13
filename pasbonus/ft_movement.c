/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:23:58 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/11 15:34:17 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_movement(int keysym, t_data *data)
{
	if (keysym == 119)
	{
		if (data->info.map[(int)(data->info.player.x + data->info.dir.x
				* data->info.moveSpeed)][(int)data->info.player.y] == '0')
			data->info.player.x += data->info.dir.x * data->info.moveSpeed;
		if (data->info.map[(int)(data->info.player.x)][(int)(data->info.player.y
				+ data->info.dir.y * data->info.moveSpeed)] == '0')
			data->info.player.y += data->info.dir.y * data->info.moveSpeed;
		cub3d_exec(data);
		return ;
	}
	if (keysym == 115)
	{
		if (data->info.map[(int)(data->info.player.x - data->info.dir.x
				* data->info.moveSpeed)][(int)data->info.player.y] == '0')
			data->info.player.x -= data->info.dir.x * data->info.moveSpeed;
		if (data->info.map[(int)(data->info.player.x)][(int)(data->info.player.y
				- data->info.dir.y * data->info.moveSpeed)] == '0')
			data->info.player.y -= data->info.dir.y * data->info.moveSpeed;
		cub3d_exec(data);
		return ;
	}
	ft_movement2(keysym, data);
}

void	ft_movement2(int keysym, t_data *data)
{
	if (keysym == 97)
	{
		if (data->info.map[(int)(data->info.player.x - data->info.plane.x
				* data->info.moveSpeed)][(int)data->info.player.y] == '0')
			data->info.player.x -= data->info.plane.x * data->info.moveSpeed;
		if (data->info.map[(int)(data->info.player.x)][(int)(data->info.player.y
				- data->info.plane.y * data->info.moveSpeed)] == '0')
			data->info.player.y -= data->info.plane.y * data->info.moveSpeed;
		cub3d_exec(data);
		return ;
	}
	if (keysym == 100)
	{
		if (data->info.map[(int)(data->info.player.x + data->info.plane.x
				* data->info.moveSpeed)][(int)data->info.player.y] == '0')
			data->info.player.x += data->info.plane.x * data->info.moveSpeed;
		if (data->info.map[(int)(data->info.player.x)][(int)(data->info.player.y
				+ data->info.plane.y * data->info.moveSpeed)] == '0')
			data->info.player.y += data->info.plane.y * data->info.moveSpeed;
		cub3d_exec(data);
		return ;
	}
}

void	ft_turn(t_data *data, double speed)
{
	double	oldDir;
	double	oldPlane;

	oldDir = data->info.dir.x;
	oldPlane = data->info.plane.x;
	data->info.dir.x = data->info.dir.x * cos(speed) - data->info.dir.y
		* sin(speed);
	data->info.dir.y = oldDir * sin(speed) + data->info.dir.y * cos(speed);
	data->info.plane.x = data->info.plane.x * cos(speed) - data->info.plane.y
		* sin(speed);
	data->info.plane.y = oldPlane * sin(speed) + data->info.plane.y
		* cos(speed);
}
