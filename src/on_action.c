/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:54:39 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/10 15:19:10 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	on_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info.rows)
	{
		free(data->info.map[i]);
		i++;
	}
	free(data->info.map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->no.img_m);
	mlx_destroy_image(data->mlx_ptr, data->so.img_m);
	mlx_destroy_image(data->mlx_ptr, data->ea.img_m);
	mlx_destroy_image(data->mlx_ptr, data->we.img_m);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 53 || keysym == 65307)
		free_all(data);
	if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
		ft_movement(keysym, data);
	if (keysym == 65363 || keysym == 65361)
	{
		if (keysym == 65363)
			ft_turn(data, -0.03);
		else
			ft_turn(data, 0.03);
	}
	if (keysym == 101 || keysym == 32)
	{
		if (data->d_status == 1)
			data->d_status = 0;
		else
			data->d_status = 1;
	}
	return (0);
}

int	on_mouse(int x, int y, t_data *data)
{
	if (x == data->info.screen.x / 2)
		return (0);
	else if (x > data->info.screen.x / 2)
		ft_turn(data, ((double)x - data->info.screen.x) / 12000.0);
	else if (x < data->info.screen.x / 2)
		ft_turn(data, (data->info.screen.x - (double)x) / 12000.0);
	x = data->info.screen.x / 2;
	y = data->info.screen.y / 2;
	mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
	return (0);
}
