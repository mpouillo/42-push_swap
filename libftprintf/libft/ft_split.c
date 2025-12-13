/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:02:35 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/13 08:52:47 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**free_all(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**alloc_arr(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	sz;

	i = 0;
	j = 0;
	while (s[i])
	{
		sz = 0;
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		while (s[i + sz] != c && s[i + sz])
			sz++;
		arr[j] = ft_calloc(sz + 1, sizeof(char));
		if (!arr[j])
			return (free_all(arr, j));
		ft_strlcpy(arr[j], &s[i], sz + 1);
		j++;
		i += sz;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = ft_calloc(get_size(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	arr = alloc_arr(arr, s, c);
	return (arr);
}
