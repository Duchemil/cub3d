/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:45:24 by lduchemi          #+#    #+#             */
/*   Updated: 2024/07/03 16:26:34 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strnlen(char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	return (i);
}

void	nullify_map(t_data *data, t_parse *parse)
{
	int	i;

	i = 0;
	while (i < parse->max_height)
	{
		data->info.map[i] = NULL;
		i++;
	}
}

char	*ft_strdup_line(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc(sizeof(*s2) * ft_strnlen((char *)s1, '\n') + 1);
	if (!s2)
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	init_map(t_data *data, char *map, t_parse *parse)
{
	int	i;

	parse->index = 0;
	i = 0;
	data->info.map = malloc(sizeof(char *) * (parse->max_height + 1));
	nullify_map(data, parse);
	if (data->info.map == NULL)
		return (printf("Error\nMalloc map failed\n"), -1);
	while (map[parse->index])
	{
		while (map[parse->index] && map[parse->index] != '\n')
			parse->index++;
		if (map[parse->index] == '\n')
			parse->index++;
		else
			break ;
		data->info.map[i] = ft_strdup_line(map + parse->index);
		if (!data->info.map[i])
			return (printf("Error\nMalloc returned an error\n"), -1);
		i++;
	}
	return (0);
}
