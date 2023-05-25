/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:07:37 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/04/28 17:11:28 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	get_next_line(int fd, char **line)
{
	static char	*stock[300];
	int			ret;
	char		*buffer;
	char		*tmp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || line == NULL || BUFFER_SIZE < 0 || !buffer)
		return (-1);
	*line = ft_strdup("");
	if (stock[fd] != NULL)
		stock[fd] = get_copy(stock, line, fd);
	if (stock[fd] != NULL)
		return (fr_ptr(buffer, 1));
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		stock[fd] = get_go(buffer, line, ret);
		if (stock[fd] != NULL)
			return (fr_ptr(buffer, 1));
		tmp = *line;
		*line = ft_strjoin(*line, buffer);
		free(tmp);
	}
	free(stock[fd]);
	return (fr_ptr(buffer, ret));
}

char	*get_go(char *buffer, char **line, int ret)
{
	char	*stock;
	char	*res;
	char	*tmp;

	buffer[ret] = '\0';
	stock = ft_strchr(buffer, '\n');
	if (stock != NULL)
	{
		*stock = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buffer);
		free(tmp);
		res = ft_strdup(stock + 1);
		return (res);
	}
	return (NULL);
}

int	fr_ptr(char *buffer, int ret)
{
	free(buffer);
	return (ret);
}

char	*get_copy(char **stock, char **line, int fd)
{
	char	*remember;
	char	*tmp;
	char	*res;

	remember = ft_strchr(stock[fd], '\n');
	if (remember != NULL)
	{
		*remember = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, stock[fd]);
		free(tmp);
		res = ft_strdup(remember + 1);
		free(stock[fd]);
		return (res);
	}
	tmp = *line;
	*line = ft_strjoin(*line, stock[fd]);
	free(tmp);
	free(stock[fd]);
	return (NULL);
}
