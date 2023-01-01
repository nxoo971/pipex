/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooxn <ooxn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:31:59 by ooxn              #+#    #+#             */
/*   Updated: 2022/09/25 18:09:47 by ooxn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*s;

	length = ft_strlen(s1);
	s = malloc(length + 1);
	if (s)
	{
		while (*s1)
			*s++ = *s1++;
		*s = 0;
		s -= length;
	}
	return (s);
}
