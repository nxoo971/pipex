/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:06:24 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/17 21:31:50 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	accept_flag_char(struct s_spec_info *s, char c)
{
	if (c == '#')
		s->sharp = vrai;
	else if (c == '-')
		s->is_left_aligned = vrai;
	else if (c == '+')
		s->plus = vrai;
	else if (c == ' ' && !s->plus)
		s->space = vrai;
	else if (c == '0')
		s->with_leading_zeroes = vrai;
	else
		return (c == ' ');
	return (vrai);
}

t_bool	accept_width_char(struct s_spec_info *s, char c)
{
	if (ft_isdigit(c))
	{
		s->width_is_specified = vrai;
		s->width = 10 * s->width + c - '0';
		return (vrai);
	}
	return (faux);
}

t_bool	accept_precision_char(struct s_spec_info *s, char c)
{
	if (ft_isdigit(c))
	{
		if (s->precision == -1)
			s->precision = 0;
		s->precision = 10 * s->precision + c - '0';
		return (vrai);
	}
	return (faux);
}

t_bool	accept_type_char(struct s_spec_info *s, char c)
{
	if (c == 'h')
		s->half_count++;
	else if (c == 'l')
		s->long_count++;
	else if (c == 'z')
		s->is_size_t++;
	else
		return (faux);
	return (vrai);
}
