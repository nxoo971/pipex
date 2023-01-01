/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooxn <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:12:18 by ooxn              #+#    #+#             */
/*   Updated: 2022/09/06 23:12:19 by ooxn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*copy;
	unsigned char	*copy2;

	copy = (unsigned char *)s1;
	copy2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*copy != *copy2)
			return (*copy - *copy2);
		copy++;
		copy2++;
	}
	return (0);
}
