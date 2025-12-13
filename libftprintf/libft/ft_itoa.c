/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:02:53 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/13 08:50:05 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long n)
{
	size_t	c;

	c = 0;
	if (n < 0)
	{
		c++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		c++;
		n /= 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	long	nbr;

	nbr = (long) n;
	len = count(nbr);
	s = ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	if (nbr < 0)
	{
		s[0] = '-';
		nbr = -nbr;
	}
	else if (nbr == 0)
		s[0] = '0';
	while (nbr > 0)
	{
		s[(len--) - 1] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (s);
}
