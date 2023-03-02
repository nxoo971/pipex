/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:48 by jewancti          #+#    #+#             */
/*   Updated: 2023/03/02 08:18:37 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	update(t_head **head, t_plist *first, t_plist *last)
{
	if (!*head)
	{
		*head = malloc(sizeof(t_head));
		if (!*head)
			return ;
		(*head)->length = 0;
		(*head)->first = 0;
		(*head)->last = 0;
	}
	if (first)
		(*head)->first = first;
	if (last)
		(*head)->last = last;
	(*head)->length++;
}

t_plist	*create_elem(const char *command, const char **option, t_head **head)
{
	t_plist	*plist;

	plist = malloc(sizeof(t_plist));
	if (plist)
	{
		plist->command = command;
		plist->option = option;
		plist->prev = 0;
	}
	update(head, plist, plist);
	return (plist);
}

void	add_elem_by_node(t_plist **list, t_plist *toadd, t_head **head)
{
	t_plist	*tmp;

	if (!*list)
	{
		*list = create_elem(toadd->command, toadd->option, head);
		return ;
	}
	tmp = (*head)->last;
	tmp->prev = toadd;
	update(head, 0, tmp->prev);
}

void	add_elem(t_head **head, t_plist **list, \
					const char *command, const char **option)
{
	t_plist	*tmp;

	if (!*list)
	{
		*list = create_elem(command, option, head);
		return ;
	}
	tmp = (*head)->last;
	tmp->prev = malloc(sizeof(t_plist));
	if (!tmp->prev)
		return ;
	tmp->prev->command = command;
	tmp->prev->option = option;
	update(head, 0, tmp->prev);
	tmp->prev->prev = 0;
}
