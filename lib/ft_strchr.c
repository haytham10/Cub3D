/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:18:07 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/13 00:19:41 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	ch;
	char	*tmp;

	i = 0;
	ch = (char)c;
	tmp = (char *)str;
	while (tmp[i] != '\0' && tmp[i] != ch)
		i++;
	if (tmp[i] == '\0')
	{
		if (ch == '\0')
			return (tmp + i);
		return (NULL);
	}
	tmp = tmp + i;
	return (tmp);
}
