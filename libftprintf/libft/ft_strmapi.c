/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:03:10 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/13 08:35:18 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	size_t			len_s;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	new_s = ft_calloc(len_s + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		new_s[i] = f(i, (char) s[i]);
		i++;
	}
	return (new_s);
}
