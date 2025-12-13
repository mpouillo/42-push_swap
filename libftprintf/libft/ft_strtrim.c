/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:02:16 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/13 08:56:38 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	set_occ(char const *s1, char const *set)
{
	size_t			i;
	size_t			count;
	const size_t	len_s = ft_strlen(s1);

	count = 0;
	while (s1[count] && ft_strchr(set, s1[count]) && s1[count])
		count++;
	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]) && count < len_s)
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	buf;
	char	*new_s;

	if (!s1 || !set)
		return (NULL);
	buf = ft_strlen(s1) - set_occ(s1, set) + 1;
	new_s = ft_calloc(buf, sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	ft_strlcpy(new_s, s1 + i, buf);
	return (new_s);
}
