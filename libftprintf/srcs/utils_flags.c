/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 08:57:20 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:43:09 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*apply_hash(t_data *tab, char *s, unsigned long arg, int caps)
{
	char	*new_s;

	if (!s)
		return (NULL);
	if (tab->hash && arg != 0)
	{
		if (caps)
			new_s = ft_strjoin("0X", s);
		else
			new_s = ft_strjoin("0x", s);
		free(s);
		return (new_s);
	}
	else
		return (s);
}

char	*apply_width(t_data *tab, char *s)
{
	int	buf;

	if (!s)
		return (NULL);
	buf = get_max(tab->width, ft_strlen(s));
	s = apply_padding(tab, s, buf, ' ');
	return (s);
}

char	*handle_zero_nullprec(t_data *tab, unsigned long arg, char *s)
{
	char	*new_s;

	if (!s)
		return (NULL);
	if (tab->dot && tab->prec == 0 && arg == 0)
	{
		free(s);
		new_s = ft_strdup("");
	}
	else
		new_s = s;
	return (new_s);
}
