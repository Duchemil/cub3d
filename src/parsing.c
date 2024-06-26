/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:06:28 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/26 16:33:10 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(t_data *data, int ac, char *argv)
{
	t_parse	*parse;
	int		bytes;
	char	map[100000 + 1];

	parse = malloc(sizeof(t_parse));
	parse->fd = open(argv[1], O_RDONLY);
	if (!parse)
		return (1);
	data->parse = parse;
	if (ac != 2)
		return (printf("Error, args aren't correct\n"));
	if (ft_cub(argv[1]) == 0)
		return (printf("Error, map isn't correct\n"));
	if (get_textures(data, argv) != 0)
		return (1);
	return (0);
}

int	parsing2(t_data *data, int ac, char *argv)

