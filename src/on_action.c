/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:54:39 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/22 18:03:12 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	on_destroy(t_data *data)
{
	for (int i = 0; i < data->info.rows; i++)
		free(data->info.map[i]);
	free(data->info.map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 53 || keysym == 65307)
		on_destroy(data);
	if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
	{
		// mlx_clear_window(data->mlx_ptr, data->win_ptr);
		ft_movement(keysym, data);
	}
	return (0);
}
