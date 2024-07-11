/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:06:28 by lduchemi          #+#    #+#             */
/*   Updated: 2024/07/11 17:51:22 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(t_data *data, char *argv)
{
	t_parse	*parse;
	int		bytes;
	char	map[100000 + 1];

	bytes = 1;
	parse = malloc(sizeof(t_parse));
	if (!parse)
		return (free_all(data), -1);
	data->parse_init = 1;
	parse->fd = open(argv, O_RDONLY);
	if (!parse || !parse->fd)
		return (printf("Error\nError whilst opening the map\n"), -1);
	if (ft_cub(argv) == 0)
		return (printf("Error\nMap isn't in .cub format\n"), -1);
	if (get_textures(data, parse->fd) != 0)
		return (-1);
	bytes = read(parse->fd, map, 100000);
	if (bytes == -1)
		return (printf("Error\nError whilst opening the map\n"), -1);
	if (bytes >= 100000)
		return (printf("Error\nMap is too big\n"), -1);
	map[bytes] = '\0';
	data->parse = parse;
	return (parsing2(data, map, parse));
}

int	parsing2(t_data *data, char *map, t_parse *parse)
{
	if (ft_check_comps(map) != 0)
		return (-1);
	find_big_line(map, parse);
	if (init_map(data, map, parse) != 0)
		return (-1);
	init_player(data);
	return (duplicate_map(data));
}

int	duplicate_map(t_data *data)
{
	char	**new_map;
	int		i;
	int		j;
	int		error;

	new_map = malloc_new_map(&error, data);
	if (error == -1)
	{
		free_array(new_map);
		return (-1);
	}
	i = -1;
	while (data->info.map && data->info.map[++i])
	{
		j = -1;
		while (data->info.map[i][++j])
			new_map[i][j] = data->info.map[i][j];
		new_map[i][j] = '\0';
	}
	new_map[i][0] = '\0';
	new_map[data->parse->max_height] = NULL;
	error = ft_winnable(data, new_map, data->info.player.y,
			data->info.player.x);
	free_array(new_map);
	return (error);
}

int	arg_check(t_data *data, char **argv)
{
	data->init = 0;
	data->NO.init = 0;
	data->SO.init = 0;
	data->EA.init = 0;
	data->WE.init = 0;
	data->anim1.init = 0;
	data->anim2.init = 0;
	data->door.init = 0;
	data->floor_color = -1;
	data->ceiling_color = -1;
	if (parsing(data, argv[1]) != 0)
		return (-1);
	return (0);
}

char	**malloc_new_map(int *error, t_data *data)
{
	int		i;
	char	**new_map;

	i = 0;
	*error = -1;
	new_map = malloc(sizeof(char *) * (data->parse->max_height + 1));
	if (!new_map)
		return (NULL);
	while (i < data->parse->max_height)
	{
		new_map[i] = malloc(sizeof(char) * (data->parse->big_line + 1));
		if (!new_map[i++])
			return (new_map);
	}
	*error = 0;
	return (new_map);
}
