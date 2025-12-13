/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 09:02:25 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 09:29:18 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_size_base(unsigned long long n, size_t base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*n_base_to_str(unsigned long long n, size_t base, int caps)
{
	static const char	*hexmap = "0123456789abcdef";
	char				*new_s;
	size_t				len;

	len = get_size_base(n, base);
	new_s = ft_calloc(len + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	if (n == 0)
		new_s[0] = '0';
	while (n > 0)
	{
		if (base == 10)
			new_s[len - 1] = n % base + '0';
		else if (base == 16)
		{
			if (caps && n % base > 9)
				new_s[len - 1] = hexmap[n % base] - 'a' + 'A';
			else
				new_s[len - 1] = hexmap[n % base];
		}
		n /= base;
		len--;
	}
	return (new_s);
}

int	no_overflow_atoui(const char *nptr)
{
	size_t	i;
	long	res;

	res = 0;
	i = 0;
	while (nptr[i] && ft_strchr("\f\n\r\t\v ", nptr[i]))
		i++;
	while (ft_isdigit(nptr[i]))
	{
		res = (res * 10) + nptr[i] - '0';
		if (res > INT_MAX)
			return (ERROR);
		i++;
	}
	return (res);
}
