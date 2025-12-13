/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:34:33 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/13 08:37:44 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*new_s;
	const size_t	len = ft_strlen(s);

	new_s = ft_calloc(len + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s, len + 1);
	return (new_s);
}
