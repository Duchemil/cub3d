/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:37:05 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/10 15:19:10 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_all(t_data *data)
{
	if (data->init && (data->verif[5] == 1 && data->verif[6] == 1))
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->parse_init)
		free(data->parse);
	destroy_images(data);
	if (data->info.map)
		free_array(data->info.map);
	free(data->mlx_ptr);
	exit(0);
}

void	destroy_images(t_data *data)
{
	if (data->no.init == 1)
		mlx_destroy_image(data->mlx_ptr, data->no.img_m);
	if (data->so.init == 1)
		mlx_destroy_image(data->mlx_ptr, data->so.img_m);
	if (data->ea.init == 1)
		mlx_destroy_image(data->mlx_ptr, data->ea.img_m);
	if (data->we.init == 1)
		mlx_destroy_image(data->mlx_ptr, data->we.img_m);
	if (data->anim1.init == 1)
		mlx_destroy_image(data->mlx_ptr, data->anim1.img_m);
	if (data->anim2.init == 1)
		mlx_destroy_image(data->mlx_ptr, data->anim2.img_m);
	if (data->door.init == 1)
		mlx_destroy_image(data->mlx_ptr, data->door.img_m);
	mlx_destroy_display(data->mlx_ptr);
}
