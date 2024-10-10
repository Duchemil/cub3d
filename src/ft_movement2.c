/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:36:15 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/10 14:36:34 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_turn(t_data *data, double speed)
{
	double	olddir;
	double	oldplane;

	olddir = data->info.dir.x;
	oldplane = data->info.plane.x;
	data->info.dir.x = data->info.dir.x * cos(speed) - data->info.dir.y
		* sin(speed);
	data->info.dir.y = olddir * sin(speed) + data->info.dir.y * cos(speed);
	data->info.plane.x = data->info.plane.x * cos(speed) - data->info.plane.y
		* sin(speed);
	data->info.plane.y = oldplane * sin(speed) + data->info.plane.y
		* cos(speed);
}
