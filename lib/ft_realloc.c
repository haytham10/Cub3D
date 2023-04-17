/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:12:22 by hmokhtar          #+#    #+#             */
/*   Updated: 2023/04/17 15:34:09 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *optr, size_t osize, size_t nsize)
{
	void	*nptr;

	if (nsize == 0)
		return (free(optr), NULL);
	else if (optr == NULL)
	{
		nptr = malloc(nsize);
		if (nptr == NULL)
			perror("Error\nMalloc failed");
		return (nptr);
	}
	else if (osize >= nsize)
		return (optr);
	else
	{
		nptr = malloc(nsize);
		if (nptr == NULL)
			perror("Error\nMalloc failed");
		ft_memcpy(nptr, optr, nsize);
		free(optr);
		return (nptr);
	}
	return (optr);
}
