/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:09:28 by lduchemi          #+#    #+#             */
/*   Updated: 2024/10/10 15:04:37 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_next_line(int fd, int line, t_info *map)
{
	static char	buff[10];
	int			byte;
	char		*dest;

	dest = NULL;
	byte = 1;
	if (fd < 0)
		return ;
	if (ft_gnl_strchr(buff) == 1)
	{
		buff_erase(buff);
		dest = ft_gnl_strjoin(dest, buff);
	}
	while (byte > 0 && ft_gnl_strchr(dest) == 0)
	{
		byte = read(fd, buff, 9);
		if (byte <= 0)
			map->map[line] = dest;
		buff[byte] = '\0';
		dest = ft_gnl_strjoin(dest, buff);
	}
	map->map[line] = dest;
}

void	buff_erase(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] != '\n')
		i++;
	i++;
	while (j < ft_s_gnl(buff, 0) - i)
	{
		buff[j] = buff[i + j];
		j++;
	}
	buff[j] = '\0';
}

char	*test(char *s1, char *dest)
{
	free(s1);
	if (dest)
	{
		if (dest[0] == '\0')
		{
			free(dest);
			dest = NULL;
		}
	}
	return (dest);
}

int	ft_s_gnl(char *s, int j)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	if (j == 1)
		c = '\n';
	while (s && s[i] && s[i] != c)
		i++;
	if (c == '\n' && s && s[i] && s[i] == '\n')
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		t;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ((ft_s_gnl(s1, 1) + ft_s_gnl(s2, 0)) + 1));
	if (dest)
	{
		while (s1 && s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		t = 0;
		while (s2 && s2[t] && s2[t] != '\n')
		{
			dest[i + t] = s2[t];
			t++;
		}
		dest[i + t] = '\n';
		if (s2 && s2[t] && s2[t] == '\n')
			t++;
		dest[i + t] = '\0';
	}
	return (test(s1, dest));
}
