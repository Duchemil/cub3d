/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:42:22 by lduchemi          #+#    #+#             */
/*   Updated: 2024/06/28 15:35:02 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
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
	int		bits_per_pixel;
	int		init;
}			t_img;

typedef struct s_parsing
{
	char	map[5000 + 1];
	int		fd;
	int		j;
	int		index;
	int		line;
	int		big_line;
	int		init;
	int		max_height;
}			t_parse;

typedef struct s_info_map
{
	char	**map;
	int		rows;
	int		cols;
	t_img	*ttp;
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
	t_pos	wall_dir;
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
	int		verif[8];
	t_parse	parse;
	t_img	NO;
	t_img	SO;
	t_img	EA;
	t_img	WE;
	t_info	info;
	int		floor_color;
	int		ceiling_color;
}			t_data;

/*				MAIN			*/

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
int			ft_strlen_gnl(char *s, int j);
int			ft_gnl_strchr(char *s);

/*				PARSING			*/

int			parsing(t_data *data, int ac, char *argv);

/*				SPLIT			*/

static int	check_split(int i, char c, int *index, char *s);
static int	count_word(char *s, char c);
static void	init_split(int *i, int *index, int *indice);
char		*ft_substr(char *s, int start, int len);
char		**ft_split(char *s, char c);

/*				GET_TEXT		*/

int			get_textures(t_data *data, char *argv);
int			check_read(char *buff, char *str, t_data *data);
int			assign_text(t_data *data, char *str);
void		check_line_name(char **tab, t_data *data, int *error);

/*				GET_IMG			*/

int			get_no_img(t_data *data, char *path);
int			get_so_img(t_data *data, char *path);
int			get_ea_img(t_data *data, char *path);
int			get_we_img(t_data *data, char *path);
int			get_ceil_color(t_data *data, char *path);
int			get_floor_color(t_data *data, char *path);
int			get_anim_img(t_data *data, char *path);
int			get_anim2_img(t_data *data, char *path);
int			get_door_img(t_data *data, char *path);

/*				UTILS			*/

double		abs_val(double nb);
void		ft_bzero(void *s, size_t n);
void		free_array(char **tab);
int			ft_atoi(const char *str);
int			ft_isnum(char *str);

int			ft_strlen(char *str);

/*				EXEC			*/

int			cub3d_exec(t_data *data);
void		cub3d_exec2(t_data *data, int x);
void		cub3d_exec3(t_data *data, int x);
void		cub3d_exec4(t_data *data, int x);

/*				PRINT			*/

void		verticalLine(t_data *data, int x, double drawStart, double drawEnd);
void		print_texture(t_data *data, int x, int y, int color);
void		choose_texture(t_data *data);
int			get_pixel_color(t_img *img, int x, int y);

/*				MINIMAP			*/

void		print_minimap(t_data *data);
void		minimap_pixel(t_data *data, int map_x, int map_y, char type);

#endif
