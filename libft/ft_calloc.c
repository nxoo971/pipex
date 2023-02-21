/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:35:29 by ooxn              #+#    #+#             */
/*   Updated: 2022/12/31 13:11:54 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#define MAXV	18446744073709551615UL

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count >= MAXV || size >= MAXV)
		return (NULL);
	s = malloc(count * size);
	if (s)
		ft_bzero(s, count * size);
	return (s);
}
