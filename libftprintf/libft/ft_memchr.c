/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:48:36 by mpouillo          #+#    #+#             */
/*   Updated: 2025/11/09 16:14:36 by mpouillo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*mem;

	mem = (char *) s;
	i = 0;
	while (i < n)
	{
		if (mem[i] == (unsigned char) c)
			return ((void *) &mem[i]);
		i++;
	}
	return (NULL);
}
