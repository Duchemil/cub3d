/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:17:18 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/28 15:32:51 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_floor_color(t_data *data, char *path)
{
	int		r;
	int		g;
	int		b;
	char	**color;

	if (data->floor_color != -1)
		return (write(2, "Error\nMore than one floor color in map\n", 40));
	color = ft_split(path, ' ');
	if (!color || color[0] == NULL || color[1] == NULL || color[2] == NULL
		|| ft_isnum(color[0]) == 1 || ft_isnum(color[1]) == 1
		|| ft_isnum(color[2]) == 1)
	{
		free_array(color);
		return (write(2, "Error\nFloor color isn't numerical\n", 35), -1);
	}
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	free_array(color);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		return (write(2, "Error\nFloor color value not within 0 - 255\n", 44),
			-1);
	data->floor_color = (r << 16 | g << 8 || b);
	data->verif[4];
	return (0);
}
