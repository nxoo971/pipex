/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2023/03/02 08:13:01 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static \
int	_exec_unsigned(struct s_spec_info *s, va_list *param, \
					int base, bool lower)
{
	uintptr_t	n;

	n = va_arg(*param, unsigned int);
	s->current_size = len_unsigned(n, base);
	s->is_null = n == 0;
	if (s->sharp && !s->is_null)
		s->current_size += 2;
	return (print_algo_flag(s, n, base, lower));
}

int	exec_unsigned(va_list *param, struct s_spec_info *s)
{
	return (_exec_unsigned(s, param, 10, false));
}

int	exec_lowerhexa(va_list *param, struct s_spec_info *s)
{
	return (_exec_unsigned(s, param, 16, true));
}

int	exec_upperhexa(va_list *param, struct s_spec_info *s)
{
	return (_exec_unsigned(s, param, 16, false));
}

int	exec_pointer(va_list *param, struct s_spec_info *s)
{
	uintptr_t	n;

	n = (uintptr_t)va_arg(*param, void *);
	s->current_size = len_unsigned(n, 16) + 2;
	if (s->plus)
		s->plus = false;
	if (s->precision > 0 && s->with_leading_zeroes)
		s->current_size -= 2;
	if (n == 0)
		return (ft_putnstr_fd("(nil)", 5, 2));
	return (print_algo_flag(s, n, 16, true));
}
