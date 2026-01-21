/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chafonta <chafonta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 03:12:19 by chafonta          #+#    #+#             */
/*   Updated: 2025/11/28 03:12:19 by chafonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen_gnl(const char *str);
char	*get_next_line(int fd);
char	*put_error(char **s1, char **s2);
char	*ft_strldup(const char *s, int l);
char	*ft_strljoin(char *dest, char const *src, int l);

#endif
