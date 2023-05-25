/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getTexture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:21:26 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/05/02 15:39:56 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	val_t(char c)
{
	if (c == 'n' && g_game.textures.no != NULL)
		ft_error("Error\nDuplicate texture");
	else if (c == 's' && g_game.textures.so != NULL)
		ft_error("Error\nDuplicate texture");
	else if (c == 'w' && g_game.textures.we != NULL)
		ft_error("Error\nDuplicate texture");
	else if (c == 'e' && g_game.textures.ea != NULL)
		ft_error("Error\nDuplicate texture");
	return (1);
}

void	get_texture(void)
{
	int		line;
	void	*file;

	file = mlx_xpm_file_to_image(g_game.mlx.mlx, g_game.textures.no,
			&line, &line);
	if (file == NULL)
		ft_error("Error\nInvalid texture path\n");
	g_game.north = (int *)mlx_get_data_addr(file, &line, &line, &line);
	file = mlx_xpm_file_to_image(g_game.mlx.mlx, g_game.textures.so,
			&line, &line);
	if (file == NULL)
		ft_error("Error\nInvalid texture path\n");
	g_game.south = (int *)mlx_get_data_addr(file, &line, &line, &line);
	file = mlx_xpm_file_to_image(g_game.mlx.mlx, g_game.textures.we,
			&line, &line);
	if (file == NULL)
		ft_error("Error\nInvalid texture path\n");
	g_game.west = (int *)mlx_get_data_addr(file, &line, &line, &line);
	file = mlx_xpm_file_to_image(g_game.mlx.mlx, g_game.textures.ea,
			&line, &line);
	if (file == NULL)
		ft_error("Error\nInvalid texture path\n");
	g_game.east = (int *)mlx_get_data_addr(file, &line, &line, &line);
}
