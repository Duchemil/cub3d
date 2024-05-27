/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:06:28 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/27 16:46:14 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(t_data *data, char *argv)
{
	if (get_textures(data, argv) != 0)
		return (1);
	printf("Text [0] : %s\n", data->textures[0]);
	return (0);
}

void	trim_newline(char *str)
{
	size_t	len;

	len = strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

int	get_textures(t_data *data, char *argv)
{
	int		fd;
	int		bytes;
	char	buffer[4096];
	char	*line_start;
	char	*line_end;

	bytes = 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (printf("Error opening file\n"));
	printf("Ah\n");
	while (bytes > 0)
	{
		bytes = read(fd, buffer, sizeof(buffer - 1));
		printf("uh\n");
		line_start = buffer;
		line_end = '\0';
		trim_newline(line_start);
		if (strncmp(line_start, "NO ", 3) == 0)
			strcpy(data->textures[0], line_start + 3);
		else if (strncmp(line_start, "SO ", 3) == 0)
			strcpy(data->textures[1], line_start + 3);
		else if (strncmp(line_start, "WE ", 3) == 0)
			strcpy(data->textures[2], line_start + 3);
		else if (strncmp(line_start, "EA ", 3) == 0)
			strcpy(data->textures[3], line_start + 3);
		line_start = line_end + 1;
	}
	return (0);
}
