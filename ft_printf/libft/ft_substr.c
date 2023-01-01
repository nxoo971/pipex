/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooxn <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:48:57 by ooxn              #+#    #+#             */
/*   Updated: 2022/09/09 22:43:23 by ooxn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char		*temp;
	char		*res;
	size_t		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && i < start)
		i++;
	if (!str[i] || i != start)
		return (ft_strdup(""));
	temp = malloc(len + 1);
	if (!temp)
		return (temp);
	i = 0;
	while (str[start + i] != '\0' && i < len)
	{
		temp[i] = str[start + i];
		i++;
	}
	temp[i] = '\0';
	res = ft_strdup(temp);
	free(temp);
	return (res);
}
