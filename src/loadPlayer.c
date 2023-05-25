/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadPlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:09:19 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/04/28 16:55:12 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	init_direction(char c)
{
	if (c == 'S')
	{
		g_game.dir_x = 1;
		g_game.dir_y = 0;
		g_game.plane_x = 0;
		g_game.plane_y = 0.66;
		g_game.player.angle = -0.1;
	}
	else if (c == 'W')
	{	
		g_game.dir_x = 0;
		g_game.dir_y = 1;
		g_game.plane_x = 0.66;
		g_game.plane_y = 0;
		g_game.player.angle = 0.1;
	}
	else if (c == 'E')
	{
		g_game.dir_x = 0;
		g_game.dir_y = -1;
		g_game.plane_x = 0.66;
		g_game.plane_y = 0;
		g_game.player.angle = -0.1;
	}
}

void	north_dir(void)
{
	g_game.dir_x = -1;
	g_game.dir_y = 0;
	g_game.plane_x = 0;
	g_game.plane_y = 0.66;
	g_game.player.angle = 0.1;
}

void	load_player(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_game.data.map[i++] != NULL)
	{
		j = 0;
		while (g_game.data.map[i - 1][j++] != '\0')
		{
			if (ft_strchr("NSWE", g_game.data.map[i - 1][j - 1]) != NULL)
			{
				g_game.player.x = i - 1 + 0.5;
				g_game.player.y = j - 1 + 0.5;
				if (g_game.data.map[i - 1][j - 1] == 'N')
					north_dir();
				init_direction(g_game.data.map[i - 1][j - 1]);
			}
		}
	}
}
