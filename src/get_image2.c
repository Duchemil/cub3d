/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:17:18 by lduchemi          #+#    #+#             */
/*   Updated: 2024/09/23 15:26:34 by agilles          ###   ########.fr       */
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
	color = ft_split(path, ',');
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
	data->floor_color = (r << 16 | g << 8 | b);
	data->verif[5] = 1;
	return (0);
}

int	get_door_img(t_data *data, char *path)
{
	t_img	*door;

	if (data->door.init != 0)
		return (write(2, "Error\nMore than one door texture in map\n", 34));
	door = &data->door;
	door->img_m = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->size_tex,
			&data->size_tex);
	if (!door->img_m)
		return (write(2, "Error\nDoor texture doesn't exist\n", 34), -1);
	door->addr = mlx_get_data_addr(door->img_m, &door->bits_per_pixel,
			&door->line_length, &door->endian);
	data->verif[6] = 1;
	data->door.init = 1;
	return (0);
}

int	get_anim1_img(t_data *data, char *path)
{
	t_img	*anim1;

	if (data->anim1.init != 0)
		return (write(2, "Error\nMore than one Anim1 texture in map\n", 41));
	anim1 = &data->anim1;
	anim1->img_m = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->size_tex,
			&data->size_tex);
	if (!anim1->img_m)
		return (write(2, "Error\nAnim1 texture doesn't exist\n", 35), -1);
	anim1->addr = mlx_get_data_addr(anim1->img_m, &anim1->bits_per_pixel,
			&anim1->line_length, &anim1->endian);
	data->verif[7] = 1;
	data->anim1.init = 1;
	return (0);
}

int	get_anim2_img(t_data *data, char *path)
{
	t_img	*anim2;

	if (data->anim2.init != 0)
		return (write(2, "Error\nMore than one Anim2 texture in map\n", 41));
	anim2 = &data->anim2;
	anim2->img_m = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->size_tex,
			&data->size_tex);
	if (!anim2->img_m)
		return (write(2, "Error\nAnim2 texture doesn't exist\n", 35), -1);
	anim2->addr = mlx_get_data_addr(anim2->img_m, &anim2->bits_per_pixel,
			&anim2->line_length, &anim2->endian);
	data->verif[8] = 1;
	data->anim2.init = 1;
	return (0);
}
