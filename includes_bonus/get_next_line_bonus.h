/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 03:12:19 by chafonta          #+#    #+#             */
/*   Updated: 2026/01/31 12:36:41 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

//		get_next_line_bonus.c
char	*get_next_line(int fd);

//		get_next_line_utils_bonus.c
int		ft_strlen_gnl(const char *str);
char	*put_error(char **s1, char **s2);
char	*ft_strldup(const char *s, int l);
char	*ft_strljoin(char *dest, char const *src, int l);

#endif
