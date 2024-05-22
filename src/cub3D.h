/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:42:22 by lduchemi          #+#    #+#             */
/*   Updated: 2024/05/22 18:03:30 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_info_map
{
	char	**map;
	int		rows;
	int		cols;
	t_pos	start;
	t_pos	player;
	t_pos	box;
	t_pos	movement;
	t_pos	dir;
	t_pos	plane;
	t_pos	screen;
	t_pos	raydir;
	t_pos	deltaDist;
	t_pos	sideDist;
	t_pos	camera;
	t_pos	step;
	double	perpWallDist;
	double	moveSpeed;
	int		fd;
	int		side;
	int		hit;
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

/*				ON_ACTION		*/

int			on_destroy(t_data *data);
int			on_keypress(int keysym, t_data *data);

/*				MOVEMENT		*/

void		ft_movement(int keysym, t_data *data);
void		ft_movement2(int keysym, t_data *data);

/*				CHECK			*/

int			ft_cub(char *filename);

/*				UTILS			*/

double		abs_val(double nb);

/*				EXEC			*/

int			cub3d_exec(t_data *data);
void		cub3d_exec2(t_data *data, int x);
void		cub3d_exec3(t_data *data, int x);
void		cub3d_exec4(t_data *data, int x);

/*				PRINT			*/

void		verticalLine(t_data *data, int x, double drawStart, double drawEnd,
				int color);

#endif
