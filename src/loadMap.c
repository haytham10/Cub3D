/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:17:13 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/04/28 17:18:39 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	g_in_map = 0;
int	g_newline = 0;

char	**fill_map(char **map, int *i, char *line)
{
	if ((line[0] == '1' || line[0] == ' ') && g_game.flag == 6)
	{
		map = (char **)ft_realloc(map, *i * sizeof(char *),
				(*i + 1) * sizeof(char *));
		map[*i] = (char *)malloc(nbr_char(line) + 1);
		if (map[*i] == NULL)
			ft_error("Error\nCan't allocate memory");
		cpy_valid_char(map[(*i)++], line);
		g_in_map = 1;
		if (g_newline == 1)
			ft_error("Error\nInvalid map");
	}
	else if (g_in_map == 1)
		g_newline = 1;
	return (map);
}

char	**fill_map2(char **map, int *i, char *line)
{
	if (line[0] != '\0')
	{
		map = (char **)ft_realloc(map, *i * sizeof(char *),
				((*i) + 1) * sizeof(char *));
		map[*i] = (char *)malloc(nbr_char(line) + 1);
		if (map[*i] == NULL)
			ft_error("Error\nCan't allocate memory");
		cpy_valid_char(map[(*i)++], line);
	}
	return (map);
}

char	**load_map(int fd)
{
	char	*line;
	int		i;

	i = 0;
	g_game.data.map = (char **)malloc(1 * sizeof(char *));
	if (g_game.data.map == NULL)
		ft_error("Error\nCan't allocate memory");
	while (get_next_line(fd, &line) > 0)
	{
		load_textures(&g_game.data, line);
		g_game.data.map = fill_map(g_game.data.map, &i, line);
		if (line != NULL)
			free(line);
	}
	g_game.data.map = fill_map2(g_game.data.map, &i, line);
	g_game.data.map = (char **)ft_realloc(g_game.data.map,
			i * sizeof(char*), (i + 1) * sizeof(char*));
	g_game.data.map[i] = NULL;
	valid_map();
	if (line != NULL)
		free(line);
	return (g_game.data.map);
}

int	open_map(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error\nCan't open file");
	return (fd);
}
