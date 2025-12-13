/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:58:10 by mpouillo          #+#    #+#             */
/*   Updated: 2025/11/29 15:52:29 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*apply_padding(t_data *tab, char *s, int buf, char c)
{
	char	*padding;
	char	*new_s;

	if (!s)
		return (NULL);
	padding = ft_calloc(buf + 1, sizeof(char));
	if (!padding)
	{
		free(s);
		return (NULL);
	}
	ft_memset(padding, c, buf - ft_strlen(s));
	if (tab->dash)
		new_s = ft_strjoin(s, padding);
	else
		new_s = ft_strjoin(padding, s);
	free(padding);
	free(s);
	if (!new_s)
		return (NULL);
	return (new_s);
}

char	*apply_precision(char *s, int buf)
{
	char	*padding;
	char	*new_s;

	if (!s)
		return (NULL);
	padding = ft_calloc(buf + 1, sizeof(char));
	if (!padding)
	{
		free(s);
		return (NULL);
	}
	ft_memset(padding, '0', buf);
	new_s = ft_strjoin(padding, s);
	free(padding);
	free(s);
	if (!new_s)
		return (NULL);
	return (new_s);
}
