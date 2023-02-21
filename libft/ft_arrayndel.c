/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayndel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 05:59:02 by jewancti          #+#    #+#             */
/*   Updated: 2023/01/31 19:20:19 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_arrayndel(char **ptr, size_t stop)
{
	size_t	i;

	i = -1;
	if (!ptr)
		return ;
	while (++i < stop && ptr[i])
		ft_memdel((void **)& ptr[i]);
	free(ptr);
}
