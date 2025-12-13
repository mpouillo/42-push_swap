/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:00:32 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/13 08:34:06 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		len = 0;
		start = len_s;
	}
	else if (start + len > len_s)
		len = len_s - start;
	new_s = ft_calloc(len + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s + start, len + 1);
	return (new_s);
}
