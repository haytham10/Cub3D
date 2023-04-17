/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:15:03 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/04/17 16:07:53 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	ft_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	exit(FAIL);
}

void	check_valid(void)
{
	if (g_game.data.res.x < 0 || g_game.data.res.y < 0)
		ft_error("Error\nResolution not set");
	if (g_game.data.floor < 0 || g_game.data.ceiling < 0)
		ft_error("Error\nFloor or ceiling not set");
}

void	mlx_fail(void)
{
	if (!g_game.mlx.mlx || !g_game.mlx.win)
	{
		free_vars();
		ft_error("Error\nMlx failed");
	}
	else if (!g_game.mlx.img)
	{
		mlx_destroy_window(g_game.mlx.mlx, g_game.mlx.win);
		free_vars();
		ft_error("Error\nMlx failed");
	}
}

void	extra_main(void)
{
	mlx_put_image_to_window(g_game.mlx.mlx, g_game.mlx.win,
		g_game.mlx.img, 0, 0);
	mlx_hook(g_game.mlx.win, 2, 0, &key_press, NULL);
	mlx_hook(g_game.mlx.win, 3, 0, &key_release, NULL);
	mlx_hook(g_game.mlx.win, 17, 0, &close_window, NULL);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		ft_error("Error\nWrong number of arguments");
	fd = open_map(av);
	init_vars();
	g_game.data.map = load_map(fd);
	load_player();
	check_valid();
	g_game.mlx.mlx = mlx_init();
	g_game.mlx.win = mlx_new_window(g_game.mlx.mlx, (int)g_game.data.res.x, \
		(int)g_game.data.res.y, "Cub3D");
	get_texture();
	g_game.mlx.img = mlx_new_image(g_game.mlx.mlx, (int)g_game.data.res.x, \
		(int)g_game.data.res.y);
	mlx_fail();
	extra_main();
	mlx_loop_hook(g_game.mlx.mlx, render, NULL);
	mlx_loop(g_game.mlx.mlx);
}
