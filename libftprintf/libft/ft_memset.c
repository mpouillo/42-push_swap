/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:02:20 by mpouillo          #+#    #+#             */
/*   Updated: 2025/11/09 12:22:31 by mpouillo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*p;
	unsigned char	b;

	p = (char *)s;
	b = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		p[i] = b;
		i++;
	}
	return (s);
}
