/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:25:53 by ooxn              #+#    #+#             */
/*   Updated: 2022/12/10 04:53:29 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	strjoin = malloc(size_s1 + size_s2 + 1);
	if (strjoin)
	{
		*strjoin = 0;
		ft_strcat(strjoin, s1);
		ft_strcat(strjoin, s2);
	}
	return (strjoin);
}
