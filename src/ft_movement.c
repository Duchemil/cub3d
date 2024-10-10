/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:23:58 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/10 14:35:35 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_movement(int keysym, t_data *data)
{
	if (keysym == 119)
		ft_movement_up(keysym, data);
	else if (keysym == 115)
		ft_movement_down(keysym, data);
	else if (keysym == 97)
		ft_movement_left(keysym, data);
	else if (keysym == 100)
		ft_movement_right(keysym, data);
}

void	ft_movement_up(int keysym, t_data *data)
{
	if (keysym == 119)
	{
		if (data->info.map[(int)(data->info.player.x + data->info.dir.x
				* data->info.moveSpeed)][(int)data->info.player.y] == '0' ||
			(data->info.map[(int)(data->info.player.x + data->info.dir.x
					* data->info.moveSpeed)][(int)data->info.player.y] == 'D'
					&& data->d_status == 0))
			data->info.player.x += data->info.dir.x * data->info.moveSpeed;
		if (data->info.map[(int)(data->info.player.x)][(int)(data->info.player.y
				+ data->info.dir.y * data->info.moveSpeed)] == '0' ||
			(data->info.map[(int)(data->info.player.x)]
					[(int)(data->info.player.y + data->info.dir.y
					* data->info.moveSpeed)] == 'D'
					&& data->d_status == 0))
			data->info.player.y += data->info.dir.y * data->info.moveSpeed;
		cub3d_exec(data);
		return ;
	}
}

void	ft_movement_down(int keysym, t_data *data)
{
	if (keysym == 115)
	{
		if (data->info.map[(int)(data->info.player.x - data->info.dir.x
				* data->info.moveSpeed)][(int)data->info.player.y] == '0' ||
			(data->info.map[(int)(data->info.player.x - data->info.dir.x
					* data->info.moveSpeed)][(int)data->info.player.y] == 'D'
					&& data->d_status == 0))
			data->info.player.x -= data->info.dir.x * data->info.moveSpeed;
		if (data->info.map[(int)(data->info.player.x)][(int)(data->info.player.y
				- data->info.dir.y * data->info.moveSpeed)] == '0' ||
			(data->info.map[(int)(data->info.player.x)]
					[(int)(data->info.player.y - data->info.dir.y
					* data->info.moveSpeed)] == 'D'
					&& data->d_status == 0))
			data->info.player.y -= data->info.dir.y * data->info.moveSpeed;
		cub3d_exec(data);
		return ;
	}
}

void	ft_movement_left(int keysym, t_data *data)
{
	if (keysym == 97)
	{
		if (data->info.map[(int)(data->info.player.x - data->info.plane.x
				* data->info.moveSpeed)][(int)data->info.player.y] == '0' ||
			(data->info.map[(int)(data->info.player.x - data->info.plane.x
					* data->info.moveSpeed)][(int)data->info.player.y] == 'D'
					&& data->d_status == 0))
			data->info.player.x -= data->info.plane.x * data->info.moveSpeed;
		if (data->info.map[(int)(data->info.player.x)][(int)(data->info.player.y
				- data->info.plane.y * data->info.moveSpeed)] == '0' ||
			(data->info.map[(int)(data->info.player.x)]
					[(int)(data->info.player.y - data->info.plane.y
					* data->info.moveSpeed)] == 'D'
					&& data->d_status == 0))
			data->info.player.y -= data->info.plane.y * data->info.moveSpeed;
		cub3d_exec(data);
		return ;
	}
}

void	ft_movement_right(int keysym, t_data *data)
{
	if (keysym == 100)
	{
		if (data->info.map[(int)(data->info.player.x + data->info.plane.x
				* data->info.moveSpeed)][(int)data->info.player.y] == '0' ||
			(data->info.map[(int)(data->info.player.x + data->info.plane.x
					* data->info.moveSpeed)][(int)data->info.player.y] == 'D'
					&& data->d_status == 0))
			data->info.player.x += data->info.plane.x * data->info.moveSpeed;
		if (data->info.map[(int)(data->info.player.x)][(int)(data->info.player.y
				+ data->info.plane.y * data->info.moveSpeed)] == '0' ||
			(data->info.map[(int)(data->info.player.x)]
					[(int)(data->info.player.y + data->info.plane.y
					* data->info.moveSpeed)] == 'D' && data->d_status == 0))
			data->info.player.y += data->info.plane.y * data->info.moveSpeed;
		cub3d_exec(data);
		return ;
	}
}
