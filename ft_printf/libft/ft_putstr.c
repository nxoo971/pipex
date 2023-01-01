/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:02:29 by nxoo              #+#    #+#             */
/*   Updated: 2022/11/11 13:50:36 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr(const char *s)
{
	ssize_t	written;

	if (s)
	{
		written = ft_strlen(s);
		return (write(1, s, written));
	}
	return (0);
}
