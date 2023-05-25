/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:33:59 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/05/01 18:44:04 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	extra_render(float c)
{
	g_game.ray.ray_x = g_game.dir_x + g_game.plane_x * c;
	g_game.ray.ray_y = g_game.dir_y + g_game.plane_y * c;
	g_game.ray.delta_x = sqrt (1 + ((g_game.ray.ray_y * g_game.ray.ray_y) \
		/ (g_game.ray.ray_x * g_game.ray.ray_x)));
	g_game.ray.delta_y = sqrt (1 + ((g_game.ray.ray_x * g_game.ray.ray_x) \
		/ (g_game.ray.ray_y * g_game.ray.ray_y)));
}

void	check_ray(t_ray *ray)
{
	ray->map_x = (int)g_game.player.x;
	ray->map_y = (int)g_game.player.y;
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (g_game.player.x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1 - g_game.player.x) * ray->delta_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (g_game.player.y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1 - g_game.player.y) * ray->delta_y;
	}
}

void	wall_hit(void)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (g_game.ray.side_x < g_game.ray.side_y)
		{
			g_game.ray.map_x += g_game.ray.step_x;
			g_game.ray.side_x += g_game.ray.delta_x;
			g_game.ray.hit = 0;
		}
		else
		{
			g_game.ray.map_y += g_game.ray.step_y;
			g_game.ray.side_y += g_game.ray.delta_y;
			g_game.ray.hit = 1;
		}
		if (g_game.data.map[g_game.ray.map_x][g_game.ray.map_y] == '1' \
			|| g_game.data.map[g_game.ray.map_x][g_game.ray.map_y] == ' ')
			hit = 1;
	}
}
