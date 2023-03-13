/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:29:24 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/03/12 16:38:26 by hmokhtar         ###   ########.fr       */
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
# include "../libft/libft.h"

# define BUFFER_SIZE 1000

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	int			**map;
	int			map_width;
	int			map_height;
	int			floor_color;
	int			ceiling_color;
	int			**texture;
	int			*texture_width;
	int			*texture_height;
	int			*texture_addr;
	int			*texture_bits_per_pixel;
	int			*texture_line_length;
	int			*texture_endian;
	int			sprite;

}				t_data;

typedef struct	s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct	s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
}				t_ray;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
}				t_sprite;

typedef struct	s_all
{
	t_data		data;
	t_player	player;
	t_ray		ray;
	t_sprite	*sprite;
	int			num_sprite;
	int			*sprite_order;
	double		*sprite_distance;
	int			save;
}				t_all;

int				get_next_line(int fd, char **line);

#endif