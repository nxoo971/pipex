/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:35:55 by nxoo              #+#    #+#             */
/*   Updated: 2023/03/02 08:13:54 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static bool	color_exist(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n-- > 0)
	{
		if (*s1 != ft_toupper(*s2))
			return (false);
		s1++;
		s2++;
	}
	return (true);
}

#define PRE_COLOR	"\e["
#define END_COLOR	"m"

static bool	print_color(const char *start, const char *end, \
								const char *const scolor[100])
{
	int	is_bg;
	int	i;

	is_bg = 0;
	if (ft_tolower(start[1]) == 'b' && ft_tolower(start[2]) == 'g')
		is_bg = 1;
	i = 0;
	while (i < 100)
	{
		if (scolor[i])
		{
			if (color_exist(scolor[i], \
				start + (is_bg * 2) + 1, end - (start + (is_bg * 2) + 1) - 1))
			{
				if (is_bg)
					i += 10;
				ft_printf("%s%d%s", PRE_COLOR, i, END_COLOR);
				return (true);
			}
		}
		i++;
	}
	return (false);
}

bool	explain_color(const char *start, const char *end)
{
	static const char *const	scolor[100] = {
	[0] = "RESET",
	[30] = "BLACK",
	[31] = "LIGHTRED",
	[32] = "LIGHTGREEN",
	[33] = "LIGHTYELLOW",
	[34] = "LIGHTBLUE",
	[35] = "LIGHTMAGENTA",
	[36] = "LIGHTCYAN",
	[90] = "LIGHTGRAY",
	[39] = "DEFAULT",
	[97] = "WHITE",
	[91] = "RED",
	[92] = "GREEN",
	[93] = "YELLOW",
	[94] = "BLUE",
	[95] = "MAGENTA",
	[96] = "CYAN",
	[37] = "GRAY",
	};

	return (print_color(start, end, scolor));
}
