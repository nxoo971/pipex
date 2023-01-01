/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explain_specification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 02:04:09 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/16 20:47:15 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	explain_specification(const char *start, const char *end, va_list *param)
{
	struct s_spec_info		s;
	static const t_action	actions[256] = {
	['c'] = & exec_char,
	['s'] = & exec_string,
	['p'] = & exec_pointer,
	['d'] = & exec_integer,
	['i'] = & exec_integer,
	['u'] = & exec_unsigned,
	['x'] = & exec_lowerhexa,
	['X'] = & exec_upperhexa,
	['f'] = & exec_double,
	['o'] = & exec_octal,
	['b'] = & exec_binary,
	['%'] = & exec_percent,
	};

	s = extract_spec_info(start, end);
	if (actions[(unsigned)s.current_type] != NULL)
		return (actions[(unsigned)s.current_type](param, &s));
	return (0);
}
