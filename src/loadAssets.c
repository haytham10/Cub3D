/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadAssets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:05:37 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/04/17 16:05:42 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	load_color(t_data *data, char *tmp)
{
	if (valid_char('F', 't', tmp) && g_game.flag == 5 && \
		count_words(tmp) == 1)
		get_color(data, tmp);
	else if (valid_char('C', 't', tmp) && g_game.flag == 6 && \
		count_words(tmp) == 1)
		get_color(data, tmp);
}

void	load_textures(t_data *data, char *line)
{
	char	*tmp;

	tmp = ft_strdup(line);
	if (valid_char('N', 'O', tmp) && valid_texture('n')
		&& g_game.flag == 1)
		g_game.textures.no = get_text(tmp);
	else if (valid_char('S', 'O', tmp) && valid_texture('s')
		&& g_game.flag == 2)
		g_game.textures.so = get_text(tmp);
	else if (valid_char('W', 'E', tmp) && valid_texture('w')
		&& g_game.flag == 3)
		g_game.textures.we = get_text(tmp);
	else if (valid_char('E', 'A', tmp) && valid_texture('e')
		&& g_game.flag == 4)
		g_game.textures.ea = get_text(tmp);
	else if (data->ceiling == -1 || data->floor == -1)
		load_color(data, tmp);
	else if (*tmp != '\0' && !ft_strchr("01 ", *tmp))
	{
		free(tmp);
		ft_error("Error\nInvalid line");
	}
	free(tmp);
}
