/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:03:19 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/10 15:19:43 by lduchemi         ###   ########.fr       */
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

int	init_img(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, 720, 480);
	if (!data->img_ptr)
		return (on_destroy(data), 1);
	printf("Ici\n");
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length,
			&data->endian);
	printf("dah\n");
	if (!data->addr)
		return (on_destroy(data), 1);
	return (0);
}
