/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:21:49 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/17 01:07:57 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char charset)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	if (charset == 0)
		return (*str != 0);
	if (str[0] == 0)
		return (0);
	while (str[i] == charset)
		i++;
	while (str[i])
	{
		if (str[i] == charset)
		{
			c++;
			while (str[i] && str[i] == charset)
				i++;
		}
		else
			i++;
	}
	if (str[i - 1] != charset)
		return (c + 1);
	return (c);
}

static int	ft_count_char(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

static char	*my_strcpy(const char *src, int size)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * size);
	if (!dest)
		return (NULL);
	dest[size - 1] = 0;
	while (--size)
	{
		dest[size - 1] = src[size - 1];
	}
	return (dest);
}

static void	*free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_split(const char *str, char charset)
{
	char	**res;
	int		i;
	int		count;
	int		n;

	i = 0;
	if (!str)
		return (NULL);
	count = ft_count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	while (i < count)
	{
		while (*str && *str == charset)
			str++;
		if (!(*str))
			return (free(res), NULL);
		n = ft_count_char(str, charset);
		res[i++] = my_strcpy(str, (n + 1));
		if (!res[i - 1])
			return (free_tab(res));
		str += n;
	}
	return (res[i] = NULL, res);
}
