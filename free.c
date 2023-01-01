/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:54:56 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/13 08:10:46 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipex(t_pipex pipex)
{
	t_plist	*lst;
	t_plist	*tmp;
	t_head	*head;

	lst = pipex.plist;
	head = pipex.head;
	while (lst)
	{
		tmp = lst->prev;
		ft_memdel((void **)& lst->command);
		ft_memdel((void **)& lst->option);
		ft_memdel((void **)& lst);
		lst = tmp;
	}
	ft_memdel((void **)& head);
}
