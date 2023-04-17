/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:30:45 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/04/17 20:18:02 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	close_window(void *arg)
{
	(void)arg;
	free_vars();
	exit(SUCCESS);
}

int	key_release(int key, void *arg)
{
	(void)arg;
	if (key == W)
		g_game.move.forward = 0;
	else if (key == S)
		g_game.move.backward = 0;
	else if (key == LEFT)
		g_game.move.left = 0;
	else if (key == RIGHT)
		g_game.move.right = 0;
	else if (key == A)
		g_game.move.m_left = 0;
	else if (key == D)
		g_game.move.m_right = 0;
	return (key);
}

int	key_press(int key)
{
	if (key == ESC)
	{
		free_vars();
		exit(SUCCESS);
	}
	else if (key == W)
		g_game.move.forward = 1;
	else if (key == S)
		g_game.move.backward = 1;
	else if (key == A)
		g_game.move.m_left = 1;
	else if (key == D)
		g_game.move.m_right = 1;
	else if (key == LEFT)
		g_game.move.left = 1;
	else if (key == RIGHT)
		g_game.move.right = 1;
	return (SUCCESS);
}
