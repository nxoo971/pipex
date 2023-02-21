/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:58:57 by nxoo              #+#    #+#             */
/*   Updated: 2022/12/31 13:11:54 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnrchr(const char *s, int c, int len)
{
	char	*s1;

	s1 = NULL;
	while (*s && len-- > 0)
	{
		if (*s == (char)c)
			s1 = (char *)s;
		s++;
	}
	if (*s == (char)c)
		s1 = (char *)s;
	return (s1);
}
