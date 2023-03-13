/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:54:55 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/13 02:21:37 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
