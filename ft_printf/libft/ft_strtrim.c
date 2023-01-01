/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooxn <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:42:51 by ooxn              #+#    #+#             */
/*   Updated: 2022/09/11 22:42:53 by ooxn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char *set, char c)
{
	while (*set && *set != c)
		set++;
	return (*set != '\0');
}

static char	*ft_strsub(char const *str, unsigned int start, unsigned int end)
{
	char		*res;
	char		*s;
	size_t		size;
	int			i;

	size = end - start;
	res = malloc(size + 1);
	if (!res)
		return (res);
	s = (char *)str + start;
	i = 0;
	while (*s && end-- > start)
		res[i++] = *s++;
	res[i] = 0;
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*s;

	if (!s1 || !set)
		return (NULL);
	s = (char *)s1;
	while (*s && is_set(set, *s))
		s++;
	if (!*s)
		return (ft_strdup(s));
	start = s;
	while (*s)
		s++;
	while (is_set(set, *--s))
		;
	return (ft_strsub(start, 0, ++s - start));
}
