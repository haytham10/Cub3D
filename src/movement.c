/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:32:21 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/05/25 12:03:08 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	move_sides(void)
{
	if (g_game.move.m_left == 1)
	{
		if (!ft_strchr("1 ", g_game.data.map[(int)(g_game.player.x \
			- g_game.plane_x * SPEED)][(int)g_game.player.y]))
				g_game.player.x -= g_game.plane_x * SPEED;
		if (!ft_strchr("1 ", g_game.data.map[(int)g_game.player.x] \
			[(int)(g_game.player.y - g_game.plane_y * SPEED)]))
				g_game.player.y -= g_game.plane_y * SPEED;
	}
	else if (g_game.move.m_right == 1)
	{
		if (!ft_strchr("1 ", g_game.data.map[(int)(g_game.player.x \
			+ g_game.plane_x * SPEED)][(int)g_game.player.y]))
				g_game.player.x += g_game.plane_x * SPEED;
		if (!ft_strchr("1 ", g_game.data.map[(int)g_game.player.x] \
			[(int)(g_game.player.y + g_game.plane_y * SPEED)]))
				g_game.player.y += g_game.plane_y * SPEED;
	}
}

void	check_move(void)
{
	if (g_game.move.forward == 1)
	{
		if (!ft_strchr("1 ", g_game.data.map[(int)(g_game.player.x \
			+ g_game.dir_x * SPEED)][(int)g_game.player.y]))
			g_game.player.x += g_game.dir_x * SPEED;
		if (!ft_strchr("1 ", g_game.data.map[(int)g_game.player.x] \
			[(int)(g_game.player.y + g_game.dir_y * SPEED)]))
			g_game.player.y += g_game.dir_y * SPEED;
	}
	else if (g_game.move.backward == 1)
	{
		if (!ft_strchr("1 ", g_game.data.map[(int)(g_game.player.x \
			- g_game.dir_x * SPEED)][(int)g_game.player.y]))
				g_game.player.x -= g_game.dir_x * SPEED;
		if (!ft_strchr("1 ", g_game.data.map[(int)g_game.player.x] \
			[(int)(g_game.player.y - g_game.dir_y * SPEED)]))
				g_game.player.y -= g_game.dir_y * SPEED;
	}
	move_sides();
}

void	rotate_right(float tmp)
{
	tmp = g_game.dir_x;
	g_game.dir_x = g_game.dir_x * cos(-g_game.player.angle) - g_game.dir_y
		* sin(-g_game.player.angle);
	g_game.dir_y = tmp * sin(-g_game.player.angle) + g_game.dir_y
		* cos(-g_game.player.angle);
	tmp = g_game.plane_x;
	g_game.plane_x = g_game.plane_x * cos(-g_game.player.angle) - g_game.plane_y
		* sin(-g_game.player.angle);
	g_game.plane_y = tmp * sin(-g_game.player.angle) + g_game.plane_y
		* cos(-g_game.player.angle);
}

void	rotate_left(float tmp)
{
	tmp = g_game.dir_x;
	g_game.dir_x = g_game.dir_x * cos(g_game.player.angle) - g_game.dir_y
		* sin(g_game.player.angle);
	g_game.dir_y = tmp * sin(g_game.player.angle) + g_game.dir_y
		* cos(g_game.player.angle);
	tmp = g_game.plane_x;
	g_game.plane_x = g_game.plane_x * cos(g_game.player.angle) - g_game.plane_y
		* sin(g_game.player.angle);
	g_game.plane_y = tmp * sin(g_game.player.angle) + g_game.plane_y
		* cos(g_game.player.angle);
}

void	check_rotation(void)
{
	float	tmp;

	tmp = 0;
	if (g_game.move.right == 1)
		rotate_right(tmp);
	else if (g_game.move.left == 1)
		rotate_left(tmp);
}
