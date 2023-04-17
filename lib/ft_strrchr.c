/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 01:56:27 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/14 21:35:43 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	char	*tmp;
	char	*ptr_res;

	tmp = (char *)str;
	ptr_res = NULL;
	ch = (char)c;
	while (*tmp != '\0')
	{
		if (*tmp == ch)
			ptr_res = tmp;
		tmp++;
	}
	if (ch == '\0')
		return (tmp);
	return (ptr_res);
}
