/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:03:19 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/17 17:12:25 by lduchemi         ###   ########.fr       */
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
