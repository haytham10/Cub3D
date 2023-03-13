/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:39:25 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/17 03:42:23 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_tab(char *res, size_t nbr, size_t len)
{
	while (nbr > 0)
	{
		res[len--] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	return (res);
}

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	size_t	nbr;
	int		s;

	s = 1;
	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		s *= -1;
		nbr = n * -1;
		res[0] = '-';
	}
	else
		nbr = n;
	res = ft_tab(res, nbr, len);
	return (res);
}
