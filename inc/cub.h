/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:51:15 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/05/02 15:39:42 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <mlx.h>
# include "../lib/libft.h"

# define BUFFER_SIZE 4096
# define SPEED 0.1
# define FAIL 0
# define SUCCESS 1
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define TAILE_SIZE 64

typedef struct s_point
{
	float		x;
	float		y;
}	t_point;

typedef struct s_data
{
	t_point		res;
	int			floor;
	int			ceiling;
	char		**map;
}	t_data;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
}	t_player;

typedef struct s_textures
{
	void		*no;
	void		*so;
	void		*we;
	void		*ea;
}	t_textures;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
}	t_mlx;

typedef struct s_move
{
	int			forward;
	int			backward;
	int			m_left;
	int			m_right;
	int			left;
	int			right;
}	t_move;

typedef struct s_ray
{
	float	ray_x;
	float	ray_y;
	int		map_x;
	int		map_y;
	float	side_x;
	float	side_y;
	float	delta_x;
	float	delta_y;
	int		step_x;
	int		step_y;
	int		height;
	int		hit;
}	t_ray;

typedef struct s_g_game
{
	t_data		data;
	t_player	player;
	t_textures	textures;
	t_mlx		mlx;
	t_move		move;
	t_ray		ray;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	int			*north;
	int			*south;
	int			*west;
	int			*east;
	int			*ray_buffer;
	int			flag;
}	t_game;
////////////////////////
t_game		g_game;
////////////////////////
// PARSING FUNCTIONS
////////////////////////
int			get_next_line(int fd, char **line);
char		*get_go(char *buffer, char **line, int ret);
int			fr_ptr(char *buffer, int ret);
char		*get_copy(char **stock, char **line, int fd);
int			ft_error(char *str);
int			open_map(char **av);
void		init_vars(void);
char		**load_map(int fd);
char		**fill_map(char **map, int *i, char *line);
void		load_textures(t_data *data, char *line);
void		load_color(t_data *data, char *tmp);
int			valid_char(char a, char b, char *line);
int			count_words(char *line);
void		lid_char(char *dest, char *src);
int			nbr_char(char *line);
void		cpy_valid_char(char *dest, char *src);
void		get_res(int width, int height);
void		resCheck(char *line);
int			get_number(char *line, int *i);
void		get_texture(void);
void		get_color(t_data *data, char *line);
void		check_color(int color, char *line, t_data *data, int colorNbr);
int			get_color2(char *line, int i, int *color, int *colorNbr);
void		check_dup_color(char *line);
char		*get_text(char *line);
void		valid_text(char *line);
char		**fill_map2(char **map, int *i, char *line);
void		valid_map(void);
void		checkHorizontal(char **map, int j, int i);
void		checkVertical(char **map, int i, int j);
void		check_multiplayer(int height);
void		load_player(void);
void		north_dir(void);
void		init_direction(char c);
void		check_valid(void);
int			val_t(char c);
void		mlx_fail(void);
void		extra_main(void);
int			key_press(int key);
int			key_release(int key, void *arg);
int			close_window(void *arg);
void		free_vars(void);
void		free_map(void);
////////////////////////
// RENDERING FUNCTIONS
////////////////////////
int			render(void);
void		check_move(void);
void		check_rotation(void);
void		extra_render(float c);
void		check_ray(t_ray *ray);
void		wall_hit(void);
void		render_wall(int c);
float		resume_render(float wallX, float *wallDist);
void		render_floor(int c, int renderS, int renderE, int TexX);
void		render_image(int i, int c, int color);

#endif
