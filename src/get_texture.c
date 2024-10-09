/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:03:50 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/09 17:44:10 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_textures(t_data *data, int fd)
{
	char	buff[2];
	char	str[1024];
	int		bytes;

	bytes = 1;
	ft_bzero(str, 1024);
	while (1)
	{
		bytes = read(fd, &buff, 1);
		if (bytes <= 0)
			break ;
		buff[bytes] = '\0';
		if (check_read(buff, str, data) != 0)
			return (-1);
		if (data->verif[0] == 1 && data->verif[1] == 1 && data->verif[2] == 1
			&& data->verif[3] == 1 && data->verif[4] == 1
			&& data->verif[5] == 1
			&& data->verif[6] == 1
			&& data->verif[7] == 1 && data->verif[8] == 1
			)
			break ;

	}
	return (0);
}

int	check_read(char	*buff, char *str, t_data *data)
{
	int	error;

	if (buff[0] == '\n')
	{
		if (ft_strlen(str) == 0)
			error = assign_text(data, "\n");
		else
		{
			str[ft_strlen(str)] = '\0';
			error = assign_text(data, str);
		}
		if (error != 0)
			return (-1);
		ft_bzero(str, 1024);
	}
	else
		str[ft_strlen(str)] = buff[0];
	return (0);
}

int	assign_text(t_data *data, char *str)
{
	int		error;
	char	**tab;

	tab = ft_split(str, ' ');
	error = 0;
	if (tab[0] == NULL || (tab[0] && tab[0][0] != '\n' && tab[1] == NULL))
	{
		free_array(tab);
		return (-1);
	}
	if (tab && tab[0] && tab[1] && tab[2])
	{
		free_array(tab);
		return (-1);
	}
	check_line_name(tab, data, &error);
	if (error == -1)
	{
		free_array(tab);
		return (-1);
	}
	free_array(tab);
	return (0);
}

void	check_line_name(char **tab, t_data *data, int *error)
{
	if (tab[0][0] == 'N' && tab[0][1] == 'O' && !tab[0][2])
		*error = get_no_img(data, tab[1]);
	else if (tab[0][0] == 'S' && tab[0][1] == 'O' && !tab[0][2])
		*error = get_so_img(data, tab[1]);
	else if (tab[0][0] == 'E' && tab[0][1] == 'A' && !tab[0][2])
		*error = get_ea_img(data, tab[1]);
	else if (tab[0][0] == 'W' && tab[0][1] == 'E' && !tab[0][2])
		*error = get_we_img(data, tab[1]);
	else if (tab[0][0] == 'D' && tab[0][1] == 'O' && !tab[0][2])
		*error = get_door_img(data, tab[1]);
	else if (tab[0][0] == 'A' && tab[0][1] == '1' && !tab[0][2])
		*error = get_anim1_img(data, tab[1]);
	else if (tab[0][0] == 'A' && tab[0][1] == '2' && !tab[0][2])
		*error = get_anim2_img(data, tab[1]);
	else if (tab[0][0] == 'C' && !tab[0][1])
		*error = get_ceil_color(data, tab[1]);
	else if (tab[0][0] == 'F' && !tab[0][1])
		*error = get_floor_color(data, tab[1]);
	else if (tab[0][0] != '\n')
		*error = -1;
}
