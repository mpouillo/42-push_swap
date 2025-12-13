/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:54:59 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:31:36 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SUCCESS	1
# define ERROR		-1

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_data
{
	va_list	args;
	int		dash;
	int		dot;
	int		error;
	int		hash;
	int		is_neg;
	int		plus;
	int		prec;
	int		ret;
	int		space;
	int		width;
	int		zpad;
}	t_data;

int		ft_printf(const char *format, ...);
void	print_char(t_data *tab);
void	print_string(t_data *tab);
void	print_pointer(t_data *tab);
void	print_int(t_data *tab);
void	print_hex(t_data *tab, const char *format, int pos);
void	print_unsigned(t_data *tab);
void	print_percent(t_data *tab);

// 		format_parsing.c
int		eval_flags(t_data *tab, const char *format, int pos);
int		eval_width(t_data *tab, const char *format, int pos);
int		eval_precision(t_data *tab, const char *format, int pos);
int		eval_specifier(t_data *tab, const char *format, int pos);

//		utils_padding.c
char	*apply_padding(t_data *tab, char *s, int buf, char c);
char	*apply_precision(char *s, int buf);

//		utils_priting.c
int		putstrl(t_data *tab, char *s, size_t sz);
int		error_putstrl(t_data *tab, char *s, size_t headpos);

//		utils_flags.c
char	*apply_hash(t_data *tab, char *s, unsigned long arg, int caps);
char	*apply_width(t_data *tab, char *s);
char	*handle_zero_nullprec(t_data *tab, unsigned long arg, char *s);

//		utils_count.c
int		get_size_base(unsigned long long n, size_t base);
char	*n_base_to_str(unsigned long long n, size_t base, int caps);
int		no_overflow_atoui(const char *nptr);

//		utils_sign.c
char	*apply_neg(t_data *tab, char *s);
char	*apply_plus(t_data *tab, char *s);
char	*apply_space(t_data *tab, char *s);

//		utils_compare.c
long	get_abs(long a);
int		get_max(int a, int b);
int		get_min(int a, int b);

#endif