/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:46:23 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/10 14:52:44 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_info_hit(t_data *data)
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
	if (data->info.map[(int)data->info.box.x][(int)data->info.box.y] == 'D')
	{
		if (data->d_status == 1)
			data->info.hit = 2;
		else
			data->info.hit = 0;
	}
	if (data->info.map[(int)data->info.box.x][(int)data->info.box.y] == 'A')
		data->info.hit = 3;
}
