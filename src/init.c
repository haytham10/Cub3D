/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:25:33 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/04/17 15:32:34 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	init_vars(void)
{
	g_game.data.res.x = -1;
	g_game.data.res.y = -1;
	g_game.data.floor = -1;
	g_game.data.ceiling = -1;
	g_game.data.map = NULL;
	g_game.textures.no = NULL;
	g_game.textures.so = NULL;
	g_game.textures.we = NULL;
	g_game.textures.ea = NULL;
	g_game.mlx.mlx = NULL;
	g_game.mlx.win = NULL;
	g_game.mlx.img = NULL;
}
