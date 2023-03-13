/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:48:08 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/13 19:17:24 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (void *)str;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
