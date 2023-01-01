/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:33:51 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 03:05:25 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t const n)
{
	size_t			i;
	unsigned char	*cur_a;
	unsigned char	*cur_b;
	unsigned char	tmp;

	i = 0;
	while (i < n)
	{
		cur_a = a + i;
		cur_b = b + i;
		tmp = *cur_a;
		*cur_a = *cur_b;
		*cur_b = tmp;
		i++;
	}
}
