/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:40:21 by rhrandri          #+#    #+#             */
/*   Updated: 2026/01/19 10:45:35 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memmove copies n bytes from memory area src to memory
	area dst. The memory areas may overlap: if the dst pointer is found
	to be between the src pointer and the index n, copying will be done
	back to front to prevent data being modified before being copied.
	Otherwise it will be done front to back	to preserve data.

	RETURN VALUE :
	A pointer to dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dp;
	const char	*sp;

	if (src == dst)
		return (dst);
	dp = (char *)dst;
	sp = (const char *)src;
	if (sp < dp && sp + len > dp)
		while (len--)
			*(dp + len) = *(sp + len);
	else
	{
		while (len--)
		{
			*dp = *sp;
			sp++;
			dp++;
		}
	}
	return (dst);
}
