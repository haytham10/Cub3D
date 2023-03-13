/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:57:39 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/12 23:59:45 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *)dest;
	s2 = (char *)src;
	if (dest > src)
	{
		i = n - 1;
		while (n--)
		{
			s1[i] = s2[i];
			i--;
		}
	}
	else if (dest < src)
		ft_memcpy(dest, src, n);
	return (dest);
}
