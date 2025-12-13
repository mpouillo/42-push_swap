/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:37:17 by mpouillo          #+#    #+#             */
/*   Updated: 2025/11/19 12:05:20 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*match;

	i = 0;
	match = NULL;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			match = (char *) &s[i];
		i++;
	}
	if (s[i] == (unsigned char) c)
		match = (char *) &s[i];
	return (match);
}
