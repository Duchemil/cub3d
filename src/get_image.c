/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:02:13 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/10 15:19:10 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_no_img(t_data *data, char *path)
{
	t_img	*no;

	if (data->no.init != 0)
		return (write(2, "Error\nMore than one north texture in map\n", 42));
	no = &data->no;
	no->img_m = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->size_tex,
			&data->size_tex);
	if (!no->img_m)
		return (write(2, "Error\nNorth texture doesn't exist\n", 35), -1);
	no->addr = mlx_get_data_addr(no->img_m, &no->bits_per_pixel,
			&no->line_length, &no->endian);
	data->verif[0] = 1;
	data->no.init = 1;
	return (0);
}

int	get_so_img(t_data *data, char *path)
{
	t_img	*so;

	if (data->so.init != 0)
		return (write(2, "Error\nMore than one south texture in map\n", 42));
	so = &data->so;
	so->img_m = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->size_tex,
			&data->size_tex);
	if (!so->img_m)
		return (write(2, "Error\nSouth texture doesn't exist\n", 35), -1);
	so->addr = mlx_get_data_addr(so->img_m, &so->bits_per_pixel,
			&so->line_length, &so->endian);
	data->verif[1] = 1;
	data->so.init = 1;
	return (0);
}

int	get_ea_img(t_data *data, char *path)
{
	t_img	*ea;

	if (data->ea.init != 0)
		return (write(2, "Error\nMore than one east texture in map\n", 41));
	ea = &data->ea;
	ea->img_m = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->size_tex,
			&data->size_tex);
	if (!ea->img_m)
		return (write(2, "Error\nEast texture doesn't exist\n", 34), -1);
	ea->addr = mlx_get_data_addr(ea->img_m, &ea->bits_per_pixel,
			&ea->line_length, &ea->endian);
	data->verif[2] = 1;
	data->ea.init = 1;
	return (0);
}

int	get_we_img(t_data *data, char *path)
{
	t_img	*we;

	if (data->we.init != 0)
		return (write(2, "Error\nMore than one west texture in map\n", 41));
	we = &data->we;
	we->img_m = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->size_tex,
			&data->size_tex);
	if (!we->img_m)
		return (write(2, "Error\nWest texture doesn't exist\n", 34), -1);
	we->addr = mlx_get_data_addr(we->img_m, &we->bits_per_pixel,
			&we->line_length, &we->endian);
	data->verif[3] = 1;
	data->we.init = 1;
	return (0);
}

int	get_ceil_color(t_data *data, char *path)
{
	int		r;
	int		g;
	int		b;
	char	**color;

	if (data->ceiling_color != -1)
		return (write(2, "Error\nMore than one ceiling color in map\n", 42));
	color = ft_split(path, ',');
	if (!color || color[0] == NULL || color[1] == NULL || color[2] == NULL
		|| ft_isnum(color[0]) == 1 || ft_isnum(color[1]) == 1
		|| ft_isnum(color[2]) == 1)
	{
		free_array(color);
		return (write(2, "Error\nCeiling color isn't numerical\n", 37), -1);
	}
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	free_array(color);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		return (write(2, "Error\nCeiling color value not within 0 - 255\n", 46),
			-1);
	data->ceiling_color = (r << 16 | g << 8 | b);
	data->verif[4] = 1;
	return (0);
}
