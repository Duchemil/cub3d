/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:35:03 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/10 15:04:41 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_img(t_data *data)
{
	data->d_status = 1;
	data->anim_status = 0;
	data->anim_delay = get_current_time();
	data->img_ptr = mlx_new_image(data->mlx_ptr, 720, 480);
	if (!data->img_ptr)
		return (on_destroy(data), 1);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		return (on_destroy(data), 1);
	data->init = 1;
	return (0);
}

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->info.map[j])
	{
		i = 0;
		while (data->info.map[j][i] != '\0')
		{
			if (data->info.map[j][i] == 'N' || data->info.map[j][i] == 'S'
				|| data->info.map[j][i] == 'E' || data->info.map[j][i] == 'W')
			{
				data->info.player.x = j + 0.5;
				data->info.player.y = i + 0.5;
				data->info.player_dir = data->info.map[j][i];
				data->info.map[j][i] = '0';
				break ;
			}
			i++;
		}
		if (data->info.player.x != -1)
			break ;
		j++;
	}
}

void	init_orientation(t_data *data)
{
	if (data->info.player_dir == 'E' || data->info.player_dir == 'W')
	{
		data->info.dir.x = 0;
		data->info.dir.y = 1;
		data->info.plane.x = 0.66;
		data->info.plane.y = 0;
		if (data->info.player_dir == 'W')
		{
			data->info.dir.y *= -1;
			data->info.plane.x *= -1;
		}
	}
	if (data->info.player_dir == 'N' || data->info.player_dir == 'S')
	{
		data->info.dir.x = -1;
		data->info.dir.y = 0;
		data->info.plane.x = 0;
		data->info.plane.y = 0.66;
		if (data->info.player_dir == 'S')
		{
			data->info.dir.x *= -1;
			data->info.plane.y *= -1;
		}
	}
}

int	ft_gnl_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s)
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
