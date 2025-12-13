/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 09:05:55 by mpouillo          #+#    #+#             */
/*   Updated: 2025/11/19 13:07:25 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*c_dst;
	char	*c_src;

	if (n && !dest && !src)
		return (dest);
	c_dst = (char *) dest;
	c_src = (char *) src;
	if (c_dst > c_src && &c_src[n] > c_dst)
	{
		while (n > 0)
		{
			c_dst[n - 1] = c_src[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
