/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:20:17 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/04/30 23:07:28 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

float	resume_render(float wallX, float *wallDist)
{
	if (g_game.ray.hit == 0)
		*wallDist = (g_game.ray.map_x - g_game.player.x + \
		(1 - g_game.ray.step_x) / 2) / g_game.ray.ray_x;
	else
		*wallDist = (g_game.ray.map_y - g_game.player.y + \
		(1 - g_game.ray.step_y) / 2) / g_game.ray.ray_y;
	if (g_game.ray.hit == 0)
		wallX = g_game.player.y + *wallDist * g_game.ray.ray_y;
	else
		wallX = g_game.player.x + *wallDist * g_game.ray.ray_x;
	wallX -= floor(wallX);
	return (wallX);
}

void	render_image(int i, int c, int color)
{
	int		*dst;
	int		j;
	int		size_line;

	if (c < 0 || c >= g_game.data.res.x || i < 0 || i >= g_game.data.res.y)
		return ;
	dst = (int *)mlx_get_data_addr(g_game.mlx.img, &j, &size_line, &j);
	dst[i * (size_line / 4) + c] = color;
}

void	render_floor(int c, int renderS, int renderE, int TexX)
{
	int	i;
	int	tex_y;

	i = 0;
	while (i < renderS)
		render_image(i++, c, g_game.data.ceiling);
	while (i < renderE)
	{
		tex_y = ((i - (g_game.data.res.y / 2 - g_game.ray.height / 2)) \
			* TAILE_SIZE) / (g_game.ray.height + 0.5);
		if (g_game.ray.hit == 0 && g_game.ray.ray_x > 0)
			render_image(i++, c, g_game.south[tex_y * TAILE_SIZE + TexX]);
		if (g_game.ray.hit == 0 && g_game.ray.ray_x <= 0)
			render_image(i++, c, g_game.north[tex_y * TAILE_SIZE + TexX]);
		if (g_game.ray.hit == 1 && g_game.ray.ray_y > 0)
			render_image(i++, c, g_game.east[tex_y * TAILE_SIZE + TexX]);
		if (g_game.ray.hit == 1 && g_game.ray.ray_y <= 0)
			render_image(i++, c, g_game.west[tex_y * TAILE_SIZE + TexX]);
	}
	while (i < g_game.data.res.y)
		render_image(i++, c, g_game.data.floor);
}

void	render_wall(int c)
{
	float	wall_dist;
	int		render_start;
	int		render_end;
	int		tex_x;
	float	wall_x;

	wall_x = 0;
	wall_x = resume_render(wall_x, &wall_dist);
	tex_x = (wall_x * TAILE_SIZE);
	if ((g_game.ray.hit == 0 && g_game.ray.ray_x > 0) || \
	(g_game.ray.hit == 1 && g_game.ray.ray_y < 0))
		tex_x = TAILE_SIZE - tex_x - 1;
	if (wall_dist == 0)
		wall_dist = 0.5;
	g_game.ray.height = (int)(g_game.data.res.y / wall_dist);
	render_start = (g_game.data.res.y / 2) - (g_game.ray.height / 2);
	if (render_start < 0)
		render_start = 0;
	render_end = (g_game.data.res.y / 2) + (g_game.ray.height / 2);
	if (render_end >= g_game.data.res.y)
		render_end = g_game.data.res.y - 1;
	g_game.ray_buffer[c] = wall_dist;
	render_floor(c, render_start, render_end, tex_x);
}

int	render(void)
{
	int		i;
	float	c;

	mlx_destroy_image(g_game.mlx.mlx, g_game.mlx.img);
	g_game.mlx.img = mlx_new_image(g_game.mlx.mlx, (int)g_game.data.res.x, \
		(int)g_game.data.res.y);
	check_move();
	check_rotation();
	i = 0;
	g_game.ray_buffer = malloc(sizeof(float) * g_game.data.res.x);
	if (g_game.ray_buffer == NULL)
		ft_error("Error\nMalloc failed");
	while (i < (int)g_game.data.res.x)
	{
		c = (2 * i / g_game.data.res.x) - 1;
		extra_render(c);
		check_ray(&g_game.ray);
		wall_hit();
		render_wall(i);
		i++;
	}
	mlx_put_image_to_window(g_game.mlx.mlx, g_game.mlx.win,
		g_game.mlx.img, 0, 0);
	free(g_game.ray_buffer);
	return (1);
}
