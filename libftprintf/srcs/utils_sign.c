/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 09:49:16 by mpouillo          #+#    #+#             */
/*   Updated: 2025/11/29 15:04:32 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*apply_neg(t_data *tab, char *s)
{
	char	*new_s;

	if (tab->is_neg)
	{
		new_s = ft_strjoin("-", s);
		free(s);
	}
	else
		new_s = s;
	return (new_s);
}

char	*apply_plus(t_data *tab, char *s)
{
	char	*new_s;

	if (!s)
		return (NULL);
	if (!tab->plus || tab->is_neg)
		return (s);
	new_s = ft_strjoin("+", s);
	free(s);
	return (new_s);
}

char	*apply_space(t_data *tab, char *s)
{
	char	*new_s;

	if (!s || !tab->space || tab->is_neg || tab->plus)
		return (s);
	new_s = ft_strjoin(" ", s);
	if (!new_s)
		return (NULL);
	free(s);
	return (new_s);
}
