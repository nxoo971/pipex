/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:33:49 by nxoo              #+#    #+#             */
/*   Updated: 2022/12/02 15:09:51 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnendl_fd(const char *s, size_t len, int fd)
{
	if (s)
		return (ft_putnstr_fd(s, len, fd) + write(fd, "\n", 1));
	return (0);
}
