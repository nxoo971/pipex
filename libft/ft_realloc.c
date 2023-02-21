/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:37:54 by jewancti          #+#    #+#             */
/*   Updated: 2023/01/30 02:10:34 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_realloc(char **dst, const char *src)
{
	char	*res;
	int		i;

	if (*dst && **dst)
	{
		i = 0;
		while ((*dst)[i])
			i++;
		res = malloc(ft_strlen(src) + i + 1);
		if (res)
		{
			ft_strcpy(res, *dst);
			ft_strcpy(res + i, src);
			ft_memdel((void **)& *dst);
			*dst = res;
		}
		return ;
	}
	if (*dst && !**dst)
		ft_memdel((void **)& *dst);
	*dst = ft_strdup(src);
}
