/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 05:59:02 by jewancti          #+#    #+#             */
/*   Updated: 2023/01/16 05:18:15 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_arraydel(char **ptr)
{
	int		i;

	i = -1;
	if (!ptr)
		return ;
	while (ptr[++i])
		ft_memdel((void **)& ptr[i]);
	free(ptr);
}
