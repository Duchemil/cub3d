/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:42:22 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/10 15:18:05 by lduchemi         ###   ########.fr       */
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

typedef struct img
{
	void	*img_m;
	char	*addr;
	int		endian;
	int		line_length;
}			t_img;

typedef struct s_info_map
{
	char	**map;
	int		rows;
	int		cols;
	t_img	ttp;
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
	t_pos	text;
	double	line_step;
	double	text_pos;
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
	void	*img_ptr;
	char	*addr;
	int		line_length;
	int		endian;
	int		coord_texture;
	int		size_tex;
	int		bits_per_pixel;
	t_img	NO;
	t_img	SO;
	t_img	EA;
	t_img	WE;
	t_info	info;
	int		floor_color;
	int		ceiling_color;
}			t_data;

/*				MAIN			*/

int			parsing(t_data *data, char *argv);
int			main(int argc, char **argv);
void		ft_init(t_data *data);

/*				ON_ACTION		*/

int			on_destroy(t_data *data);
int			on_keypress(int keysym, t_data *data);
int			on_mouse(int x, int y, t_data *data);

/*				MOVEMENT		*/

void		ft_movement(int keysym, t_data *data);
void		ft_movement2(int keysym, t_data *data);
void		ft_turn(t_data *data, double speed);

/*				CHECK			*/

int			ft_cub(char *filename);
int			init_img(t_data *data);

/*				GNL				*/

void		get_next_line(int fd, int line, t_info *map);
void		buff_erase(char *buff);
char		*test(char *s1, char *dest);
char		*ft_gnl_strjoin(char *s1, char *s2);
int			ft_strlen(char *s, int j);
int			ft_gnl_strchr(char *s);

/*				PARSING			*/

int			parsing(t_data *data, char *argv);
void		trim_newline(char *str);
int			get_textures(t_data *data, char *argv);

/*				UTILS			*/

double		abs_val(double nb);

/*				EXEC			*/

int			cub3d_exec(t_data *data);
void		cub3d_exec2(t_data *data, int x);
void		cub3d_exec3(t_data *data, int x);
void		cub3d_exec4(t_data *data, int x);

/*				PRINT			*/

void		verticalLine(t_data *data, int x, double drawStart, double drawEnd);
void		print_texture(t_data *data, int x, int y, int color);
void		choose_texture(t_data *data);

#endif
