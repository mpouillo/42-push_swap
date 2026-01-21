/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:39:10 by chafonta          #+#    #+#             */
/*   Updated: 2026/01/21 17:49:28 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/bonus_checker.h"

char	*put_error(char **s1, char **s2)
{
	if (s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

int	ft_strlen_gnl(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strldup(const char *s, int l)
{
	int		i;
	char	*dest;

	if (!s)
		return (NULL);
	dest = malloc(sizeof(char) * l + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && i <= l)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strljoin(char *dest, char const *src, int l)
{
	char	*result;
	int		i;
	int		j;

	if (!src)
		return (NULL);
	result = malloc(sizeof(char) * l + ft_strlen_gnl(dest) + 1);
	if (!result)
		return (put_error(&dest, NULL));
	i = 0;
	if (dest)
	{
		i = -1;
		while (dest[++i])
			result[i] = dest[i];
	}
	j = -1;
	while (src[++j] && j < l)
		result[i + j] = src[j];
	result[i + j] = '\0';
	free(dest);
	return (result);
}
