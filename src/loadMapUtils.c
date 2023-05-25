/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadMapUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:42:13 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/05/02 15:19:46 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	nbr_char(char *line)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (line[i] != '\0')
	{
		if (ft_strchr("01NSEW ", line[i]) != NULL)
			nbr++;
		else if (line[i] != ' ')
			ft_error("Error\nInvalid map\n");
		i++;
	}
	return (nbr);
}

void	cpy_valid_char(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (ft_strchr("01NSEW ", src[i]) != NULL)
			dest[j++] = src[i];
		i++;
	}
	dest[j] = '\0';
}

int	valid_char(char a, char b, char *line)
{
	if (b != 't')
	{
		if (line[0] == a && line[1] == b && line[2] == ' ')
		{
			g_game.flag += 1;
			return (1);
		}
	}
	else if (line[0] == a && line[1] == ' ')
	{
		g_game.flag += 1;
		return (1);
	}
	return (0);
}

void	valid_text(char *line)
{
	int		i;

	i = 0;
	if (count_words(line) != 1)
		ft_error("Error\nInvalid text\n");
	while (line[i] != '\0' && line[i] != '.')
	{
		if (ft_strchr(line, 'N') != ft_strrchr(line, 'N'))
			ft_error("Error\nInvalid text\n");
		else if (ft_strchr(line, 'S') != ft_strrchr(line, 'S'))
			ft_error("Error\nInvalid text\n");
		else if (ft_strchr(line, 'W') != ft_strrchr(line, 'W'))
			ft_error("Error\nInvalid text\n");
		else if (ft_strchr(line, 'E') != ft_strrchr(line, 'E'))
			ft_error("Error\nInvalid text\n");
		else if (ft_strchr("NOSWEA ", line[i]) == NULL)
			ft_error("Error\nInvalid text\n");
		i++;
	}
}

char	*get_text(char *line)
{
	int		i;
	int		j;
	int		rest;
	char	*text;

	i = 0;
	valid_text(line);
	while (line[i] != '\0' && line[i] != '.')
		i++;
	rest = i;
	j = 0;
	while (line[i] != '\0' && line[i] != ' ')
	{
		i++;
		j++;
	}
	text = (char *)malloc(j + 1);
	if (text == NULL)
		ft_error("Error\nMalloc failed\n");
	i = 0;
	while (line[rest] != '\0' && line[rest] != ' ')
		text[i++] = line[rest++];
	text[i] = '\0';
	return (text);
}
