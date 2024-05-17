/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:42:22 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/17 17:19:14 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_info_map
{
	char	**map;
	int		rows;
	int		cols;
	t_pos	exit;
	t_pos	start;
	t_pos	player;
	t_pos	movement;
	t_pos	dir;
	t_pos	plane;
	int		fd;
	int		size;
	int		off_x;
	int		off_y;
	int		map_reset;
}			t_info;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	t_info	info;
}			t_data;

/*				MAIN			*/

int			main(int argc, char **argv);
void		ft_init(t_data *data);

/*				ON_DESTROY		*/

int			on_destroy(t_data *data);
int			on_keypress(int keysym, t_data *data);

/*				CHECK			*/

int			ft_cub(char *filename);

#endif
