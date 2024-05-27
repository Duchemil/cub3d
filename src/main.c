/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:47:57 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/27 18:17:15 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init(t_data *data)
{
	data->info.rows = -1;
	data->info.movement.x = 0;
	data->info.movement.y = 0;
	data->info.map = NULL;
	data->info.screen.x = 720;
	data->info.screen.y = 480;
	data->info.raydir.x = 0;
	data->info.raydir.y = 0;
	data->info.sideDist.x = 0;
	data->info.sideDist.y = 0;
	data->info.deltaDist.x = 0;
	data->info.deltaDist.y = 0;
	data->info.camera.x = 0;
	data->info.camera.y = 0;
	data->info.hit = 0;
}

#define MAP_ROWS 15
#define MAP_COLS 16 // One extra for the null terminator '\0'

void	init_map(t_data *data)
{
	char new_map[MAP_ROWS][MAP_COLS] = {
		"111111111111111",
		"100101010000001",
		"100000010000001",
		"101000000000001",
		"101000111000001",
		"101011100000001",
		"101000100111111",
		"101000100100001",
		"101000100100001",
		"101000100100001",
		"101000100100001",
		"101000100100001",
		"101111111100001",
		"100000000000001",
		"111111111111111"};
	data->info.map = malloc(MAP_ROWS * sizeof(char *));
	if (data->info.map == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	// Copy the strings from new_map to data->info.map
	for (int i = 0; i < MAP_ROWS; i++)
	{
		data->info.map[i] = malloc(MAP_COLS * sizeof(char));
		if (data->info.map[i] == NULL)
		{
			perror("Failed to allocate memory");
			exit(EXIT_FAILURE);
		}
		strcpy(data->info.map[i], new_map[i]);
	}
	data->info.rows = MAP_ROWS;
	data->info.cols = MAP_COLS - 1;
	data->info.start.x = 3.5; // hardcode start + player pos + dir cam + size
	data->info.start.y = 3.5;
	data->info.box.x = 4;
	data->info.box.y = 4;
	data->info.dir.x = -1;
	data->info.dir.y = 0;
	data->info.player.x = 3;
	data->info.player.y = 4;
	data->info.moveSpeed = 0.099;
	data->info.plane.x = 0;
	data->info.plane.y = 0.66;
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
	data.win_ptr = mlx_new_window(data.mlx_ptr, 720, 480, "cub3D");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	init_map(&data);
	// parsing(&data, argv[1]);
	printf("Map:\n");
	for (int i = 0; i < data.info.rows; i++)
	{
		printf("%s\n", data.info.map[i]);
	}
	mlx_hook(data.win_ptr, MotionNotify, PointerMotionMask, &on_mouse, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, (1L << 17), &on_destroy, &data);
	// cub3d_exec(&data);
	mlx_loop_hook(data.mlx_ptr, &cub3d_exec, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
