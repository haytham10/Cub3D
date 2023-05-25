/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapChecks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:21:01 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/05/01 18:43:59 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	count_words(char *line)
{
	int	i;
	int	nbr;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			nbr = 1;
		else if (nbr == 1)
		{
			nbr = 0;
			count++;
		}
		i++;
	}
	return (count);
}

void	check_multiplayer(int width)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (g_game.data.map[i] != NULL)
	{
		j = 0;
		while (g_game.data.map[i][j] != '\0')
		{
			if (ft_strchr("NSWE", g_game.data.map[i][j]) != NULL)
				flag++;
			if (flag > 1)
				ft_error("Error\nInvalid map: Multiple players");
			j++;
		}
		if (i == 0)
			width = j;
		i++;
	}
	if (flag == 0)
		ft_error("Error\nInvalid map: No player");
}

void	check_border(int x, int y, int height, int width)
{
	if (x == 0 || x == height - 1 || y == 0 || y == width - 1)
	{
		if (g_game.data.map[x][y] != '1' && g_game.data.map[x][y] != ' ')
			ft_error("Error\nInvalid map: Invalid border");
	}
	else if (g_game.data.map[x][y] == '0')
	{
		if (g_game.data.map[x][y + 1] == 0 || g_game.data.map[x][y - 1] == \
				0 || g_game.data.map[x + 1][y] == 0 || \
				g_game.data.map[x - 1][y] == 0)
			ft_error("Error\nInvalid map: Invalid border");
	}
	else if (g_game.data.map[x][y] != '1' && g_game.data.map[x][y] != '0' \
			&& g_game.data.map[x][y] != 'N' && g_game.data.map[x][y] != 'S' \
			&& g_game.data.map[x][y] != 'W' && g_game.data.map[x][y] != 'E' \
			&& g_game.data.map[x][y] != ' ')
		ft_error("Error\nInvalid map: Invalid character in map");
}

void	valid_map(void)
{
	int	x;
	int	y;
	int	height;
	int	width;

	x = 0;
	y = 0;
	if (g_game.flag < 6)
		ft_error("Error\nInvalid map: Missing elements");
	else if (g_game.data.map[x] == NULL)
		ft_error("Error\nInvalid map: Empty map");
	while (g_game.data.map[x++] != NULL)
		height = x;
	while (g_game.data.map[0][y++] != '\0')
		width = y;
	check_multiplayer(width);
	x = -1;
	while (++x < height)
	{
		width = ft_strlen(g_game.data.map[x]);
		y = -1;
		while (++y < width)
			check_border(x, y, height, width);
	}
	get_res(width, height);
}
