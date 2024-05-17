/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:47:57 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/17 17:44:46 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init(t_data *data)
{
	data->info.exit.x = -1;
	data->info.exit.y = -1;
	data->info.start.x = -1;
	data->info.start.y = -1;
	data->info.rows = -1;
	data->info.movement.x = 0;
	data->info.movement.y = 0;
	data->info.size = 32;
	data->info.map = NULL;
	data->info.map_reset = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 2)
		return (printf("Error, args aren't correct\n"));
	if (ft_cub(argv[1]) == 0)
		return (printf("Error, map isn't correct\n"));
	ft_init(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 32 * 16,
			32 * 16, "cube3D");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, (1L << 17), &on_destroy, &data);
	//mlx_loop_hook(ft_print);
	mlx_loop(data.mlx_ptr);
	return (0);
}
