/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:47:57 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/10 15:20:11 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init(t_data *data)
{
	data->info.rows = -1;
	data->info.camera.x = 0;
	data->info.camera.y = 0;
	data->info.hit = 0;
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->verif[0] = 0;
	data->verif[1] = 0;
	data->verif[2] = 0;
	data->verif[3] = 0;
	data->verif[4] = 0;
	data->verif[5] = 0;
	data->verif[6] = 0;
	data->verif[7] = 0;
	data->verif[8] = 0;
	data->info.movespeed = 0.099;
}

int	init_mlx(t_data *data)
{
	data->bits_per_pixel = 32;
	data->init = 0;
	data->info.map = NULL;
	data->parse_init = 0;
	data->info.screen.x = 720;
	data->info.screen.y = 480;
	data->info.player.x = -1;
	data->info.player.y = -1;
	data->info.dir.x = 0;
	data->info.dir.y = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free(data), -1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->info.screen.x,
			data->info.screen.y, "cub3D");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		return (free(data->mlx_ptr), -1);
	}
	return (0);
}

int	main(int ac, char **argv)
{
	t_data	data;

	if (ac != 2)
		return (printf("Error\nWrong number of args\n"), -1);
	if (init_mlx(&data) != 0)
		return (-1);
	ft_init(&data);
	if (arg_check(&data, argv) != 0)
		return (free_all(&data), -1);
	init_orientation(&data);
	init_img(&data);
	mlx_hook(data.win_ptr, MotionNotify, PointerMotionMask, &on_mouse, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, (1L << 17), &on_destroy, &data);
	mlx_loop_hook(data.mlx_ptr, &cub3d_exec, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
