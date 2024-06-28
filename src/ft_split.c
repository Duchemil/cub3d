/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:45:43 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/28 15:14:19 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_split(int i, char c, int *index, char *s)
{
	if (s[i] != c && *index < 0)
	{
		*index = i;
		if (i == ft_strlen(s) - 1)
			return (1);
		return (0);
	}
	else if ((i == ft_strlen(s) - 1 || s[i] == c) && *index >= 0)
		return (1);
	return (0);
}

static int	count_word(char *s, char c)
{
	int		nb_word;
	int		is_new_word;
	int		i;

	nb_word = 0;
	i = 0;
	is_new_word = 1;
	while (i < ft_strlen(s))
	{
		if (is_new_word == 1 && (s[i] != c
				|| (i == ft_strlen(s) - 1 && s[i] != c)))
		{
			is_new_word = 0;
			nb_word++;
		}
		else if (is_new_word == 0 && s[i] == c)
			is_new_word = 1;
		i++;
	}
	return (nb_word);
}

static void	init_split(int *i, int *index, int *indice)
{
	*index = -1;
	*indice = 0;
	*i = 0;
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		nb_c;
	int		i;
	int		index;
	int		indice;
	char	**tab;

	init_split(&i, &index, &indice);
	nb_c = count_word(s, c);
	tab = malloc((nb_c + 1) * sizeof(*tab));
	if (!tab)
		return (NULL);
	while (i < ft_strlen(s))
	{
		if (check_split(i, c, &index, s) == 1)
		{
			if (i == ft_strlen(s) - 1 && s[i] != c)
				i++;
			tab[indice] = ft_substr(s, index, i - index);
			indice++;
			index = -1;
		}
		i++;
	}
	tab[indice] = NULL;
	return (tab);
}
