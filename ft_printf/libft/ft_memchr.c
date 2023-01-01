/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooxn <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:13:53 by ooxn              #+#    #+#             */
/*   Updated: 2022/09/06 22:13:54 by ooxn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*copy;
	unsigned char	ch;

	copy = (unsigned char *)s;
	ch = (unsigned char)c;
	while (len-- > 0)
	{
		if (*copy == ch)
			return ((void *)copy);
		copy++;
	}
	return (NULL);
}
