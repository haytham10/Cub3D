/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getRes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:01:32 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/04/17 15:32:34 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	get_res(int width, int height)
{
	g_game.data.res.x = width * TAILE_SIZE;
	g_game.data.res.y = height * TAILE_SIZE;
	if (g_game.data.res.x > 2560)
		g_game.data.res.x = 2560;
	if (g_game.data.res.y > 1440)
		g_game.data.res.y = 1440;
}
