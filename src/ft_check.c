/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:03:19 by lduchemi          #+#    #+#             */
/*   Updated: 2024/07/03 16:51:29 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_cub(char *filename)
{
	int		len;
	int		fd;
	char	c;
	int		x;

	len = 0;
	x = 0;
	while (filename[len])
		len++;
	if (len < 4)
		return (0);
	if (filename[len - 4] == '.' && filename[len - 3] == 'c' && filename[len
		- 2] == 'u' && filename[len - 1] == 'b')
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (0);
		while (read(fd, &c, 1) > 0)
		{
			if (c != '\n')
				x++;
		}
		return (x);
	}
	return (0);
}

int	ft_check_comps(t_data *data)
{
	int	x;
	int	y;
	int	p;

	x = 0;
	p = 0;
	while (x < data->info.rows)
	{
		y = 0;
		while (data->info.map[x][y] != '\n')
		{
			if (valid_comp(data->info.map[x][y]) == 1)
				p++;
			else if (valid_comp(data->info.map[x][y]) == -1)
				return (printf("Error\nWrong characters in map\n") - 1);
			y++;
		}
		x++;
	}
	if (p == 0 || p > 1)
		return (printf("Error\nToo many/Not enough spawn in map\n") - 1);
	return (0);
}

int	valid_comp(char c)
{
	if (c == '0' || c == '1' || c == 'A' || c == 'D')
		return (0);
	else if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (-1);
}

int	ft_winnable(t_data *data, char **map, int y, int x)
{
	if ((map[y][x] != '0' && map[y][x] != '1' && map[y][x] != '9'
			&& map[y][x] != 'D' && map[y][x] == 'A') || y == 0 || x == 0
		|| y == data->parse->max_height || x == data->parse->big_line)
		return (-1);
	map[y][x] = '9';
	if (map[y][x] != '1' && map[y][x] != '9' && map[y][x] != 'A')
	{
		if (ft_winnable(data, map, y + 1, x) == 1 || ft_winnable(data, map, y, x
				+ 1) == 1 || ft_winnable(data, map, y - 1, x) == 1
			|| ft_winnable(data, map, y, x - 1) == 1)
			return (1);
		return (0);
	}
	return (0);
}

void	find_big_line(char *map, t_parse *parse)
{
	int	count_tmp;
	int	i;

	i = 0;
	count_tmp = 0;
	parse->max_height = 1;
	parse->big_line = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (parse->big_line < count_tmp)
				parse->big_line = count_tmp;
			count_tmp = 0;
			i++;
			parse->max_height++;
		}
		else
		{
			count_tmp++;
			i++;
		}
	}
}
