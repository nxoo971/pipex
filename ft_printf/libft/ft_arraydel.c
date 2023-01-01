/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 05:59:02 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/08 03:23:42 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(void **ptr)
{
	int		i;

	i = -1;
	if (!ptr)
		return ;
	while ((unsigned char **)ptr[++i])
		ft_memdel(ptr + i);
	free(ptr);
}
