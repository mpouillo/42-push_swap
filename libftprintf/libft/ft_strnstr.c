/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:57:47 by mpouillo          #+#    #+#             */
/*   Updated: 2025/11/11 08:59:21 by mpouillo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	char			*haystack;
	char			*needle;
	const size_t	needle_len = ft_strlen(little);

	haystack = (char *) big;
	needle = (char *) little;
	if (needle_len == 0)
		return (haystack);
	i = 0;
	while (haystack[i] && i + needle_len <= len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return (&haystack[i]);
		i++;
	}
	return (NULL);
}
