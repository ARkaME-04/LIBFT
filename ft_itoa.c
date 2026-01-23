/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 07:50:06 by rhrandri          #+#    #+#             */
/*   Updated: 2026/01/23 09:35:42 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	long	num;

	num = n;
	len = int_len(n);
	res = (char *) ft_calloc(sizeof(char), (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (--len >= 0 && res[len] != '-')
	{
		res[len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
