/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getColor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:02:45 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/04/17 15:32:34 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	get_number(char *line, int *i)
{
	int		nbr;
	char	*str;
	int		j;
	int		res;

	nbr = 0;
	j = *i;
	while ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '-')
	{
		if (line[*i] == '-')
			ft_error("Error\nInvalid resolution");
		*i += 1;
		nbr += 1;
	}
	str = (char *)malloc(nbr + 1);
	if (str == NULL)
		ft_error("Error\nMalloc failed");
	*i = j;
	nbr = 0;
	while (line[*i] >= '0' && line[*i] <= '9')
		str[nbr++] = line[(*i)++];
	str[nbr] = '\0';
	res = ft_atoi(str);
	free(str);
	return (res);
}

void	check_dup_color(char *line)
{
	if (g_game.data.floor != -1 && ft_strchr(line, 'F'))
		ft_error("Error\nDuplicate color");
	else if (g_game.data.ceiling != -1 && ft_strchr(line, 'C'))
		ft_error("Error\nDuplicate color");
}

int	get_color2(char *line, int i, int *color, int *colorNbr)
{
	int	tmp;

	if ((line[i] >= '0' && line[i] <= '9' && *colorNbr == 2 && (*colorNbr)++)
		|| line[i] == '-')
	{
		tmp = get_number(line, &i);
		if (tmp > 255)
			ft_error("Error\nInvalid color");
		*color += tmp * pow(16, 2);
	}
	else if ((line[i] >= '0' && line[i] <= '9' && \
		*colorNbr == 3 && (*colorNbr)++)
		|| line[i] == '-')
	{
		tmp = get_number(line, &i);
		if (tmp > 255)
			ft_error("Error\nInvalid color");
		*color += tmp;
	}
	return (i);
}

void	check_color(int color, char *line, t_data *data, int colorNbr)
{
	int	com_nbr;
	int	i;

	i = 0;
	com_nbr = 0;
	while (line[i++] != '\0')
	{
		if (line[i - 1] == ',')
			com_nbr += 1;
		else if (ft_strchr("FC,0123456789 ", line[i - 1]) == NULL)
			ft_error("Error\nInvalid color");
		else if (ft_strchr(line, 'F') != ft_strrchr(line, 'F'))
			ft_error("Error\nInvalid color");
		else if (ft_strchr(line, 'C') != ft_strrchr(line, 'C'))
			ft_error("Error\nInvalid color");
	}
	if (colorNbr < 4 || com_nbr != 2)
		ft_error("Error\nInvalid color");
	if (ft_strchr(line, 'F') != NULL)
		data->floor = color;
	else
		data->ceiling = color;
}

void	get_color(t_data *data, char *line)
{
	int		color;
	int		i;
	int		tmp;
	int		color_nbr;

	i = 0;
	color_nbr = 1;
	check_dup_color(line);
	while (line[i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9' && color_nbr == 1 && color_nbr++)
			|| line[i] == '-')
		{
			tmp = get_number(line, &i);
			if (tmp > 255)
				ft_error("Error\nInvalid color");
			color = tmp * pow(16, 4);
		}
		else
			i = get_color2(line, i, &color, &color_nbr);
		if (line[i] == '\0')
			break ;
		i++;
	}
	check_color(color, line, data, color_nbr);
}
