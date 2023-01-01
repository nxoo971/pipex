/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooxn <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:09:02 by ooxn              #+#    #+#             */
/*   Updated: 2022/09/06 22:09:04 by ooxn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*copy;
	unsigned char	*copy2;

	copy = (unsigned char *)s1;
	copy2 = (unsigned char *)s2;
	while ((*copy || *copy2) && n-- > 0)
	{
		if (*copy != *copy2)
			return (*copy - *copy2);
		copy++;
		copy2++;
	}
	return (0);
}
