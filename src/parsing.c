/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:06:28 by lduchemi          #+#    #+#             */
/*   Updated: 2024/07/03 16:51:40 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(t_data *data, char *argv)
{
	t_parse	*parse;
	int		bytes;
	char	map[100000 + 1];

	parse = malloc(sizeof(t_parse));
	parse->fd = open(argv[1], O_RDONLY);
	if (!parse || !parse->fd)
		return (printf("Error\nError whilst opening the map\n"), -1);
	if (ft_cub(argv[1]) == 0)
		return (printf("Error\nMap isn't in .cub format\n"), -1);
	if (get_textures(data, parse->fd) != 0)
		return (-1);
	bytes = read(parse->fd, map, 100000);
	if (bytes == -1)
		return (printf("Error\nError whilst opening the map\n"), -1);
	if (bytes >= 100000)
		return (printf("Error\nMap is too big\n"), -1);
	map[bytes] = '\0';
	if (ft_check_comps(data) != 0)
		return (-1);
	find_big_line(map, parse);
	if (parsing2(data, map, parse) != 0)
		return (-1);
	return (0);
}

int	parsing2(t_data *data, char *map, t_parse *parse)
{
	if (init_map(data, map, parse) != 0)
		return (-1);
	data->parse = parse;

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
	error = ft_winnable(new_map, data->info.player.y, data->info.player.x);
	free_array(new_map);
	return (error);
}

