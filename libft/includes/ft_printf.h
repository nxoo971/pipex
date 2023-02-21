/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 01:05:34 by nxoo              #+#    #+#             */
/*   Updated: 2023/02/18 05:42:33 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "./libft.h"

# define BASE		"0123456789ABCDEF"
# define LOWERBASE	"0123456789abcdef"

struct s_spec_info {
	bool	is_left_aligned;
	bool	with_leading_zeroes;
	bool	plus;
	bool	space;
	bool	sharp;
	bool	all;

	bool	width_is_specified;
	int		width;

	bool	precision_is_specified;
	int		precision;

	int		half_count;
	int		long_count;
	bool	is_size_t;

	char	current_type;
	int		current_size;
	bool	is_negative;
	bool	is_null;
};

typedef int			(*t_action)(va_list *, struct s_spec_info *s);

int					ft_printf(const char *format, ...);
int					explain_specification(const char *start, const char *end, \
											va_list *param);
// s_spec_info.c
struct s_spec_info	extract_spec_info(const char *start, const char *end);
// accept.c
bool				accept_flag_char(struct s_spec_info *s, char c);
bool				accept_width_char(struct s_spec_info *s, char c);
bool				accept_precision_char(struct s_spec_info *s, char c);
bool				accept_type_char(struct s_spec_info *s, char c);
// algo_flag.c
int					print_algo_flag(const struct s_spec_info *s, \
										uintptr_t n, int base, bool lower);
int					precision_is_not_specified(const struct s_spec_info *s, \
									uintptr_t n, int base, bool lower);
// print.c
int					print_prefix(const struct s_spec_info *s);
int					print_sign(const struct s_spec_info *s);
int					print_width(int width, int c);
// exec_integer.c
int					exec_integer(va_list *param, struct s_spec_info *s);
// exec_octal.c
int					exec_octal(va_list *param, struct s_spec_info *s);
// exec_binary.c
int					exec_binary(va_list *param, struct s_spec_info *s);
// exec_unsigned.c
int					exec_pointer(va_list *param, struct s_spec_info *s);
int					exec_unsigned(va_list *param, struct s_spec_info *s);
int					exec_lowerhexa(va_list *param, struct s_spec_info *s);
int					exec_upperhexa(va_list *param, struct s_spec_info *s);
// exec_float.c
int					exec_double(va_list *param, struct s_spec_info *s);
// exec_string.c
int					exec_char(va_list *param, struct s_spec_info *s);
int					exec_percent(va_list *param, struct s_spec_info *s);
int					exec_string(va_list *param, struct s_spec_info *s);
// operations.c
int					print_n_base(uintptr_t n, int base, bool lower);
// calc_len.c
int					len_unsigned(uintptr_t nb, const int base);
int					len_integer(intptr_t nb, const int base);
// color.c
bool				explain_color(const char *start, const char *end);

#endif
