/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:26:39 by jewancti          #+#    #+#             */
/*   Updated: 2023/03/02 08:39:33 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_list(t_pipex pipex)
{
	t_plist	*lst;
	int		i;

	lst = pipex.plist;
	while (lst)
	{
		ft_printf("{cyan}Command{reset}:\t%s\n", lst->command);
		i = -1;
		while (lst->option[++i])
			ft_printf("{red}Option{reset}:\t\t%s\n", lst->option[i]);
		ft_printf("{magenta}Act{reset}:\t\t%p\n", lst);
		ft_printf("{yellow}Prev{reset}:\t\t%p\n\n", lst->prev);
		lst = lst->prev;
	}
}

void	print_head(t_pipex pipex)
{
	t_head	*head;

	head = pipex.head;
	if (!head)
		return ;
	ft_printf("{magenta}First{reset}:\t\t%p\n", head->first);
	ft_printf("{yellow}Last{reset}:\t\t%p\n", head->last);
	ft_printf("{bgred}Length{reset}:\t%d\n", head->length);
}

void	print_tfile(t_file file[2])
{
	ft_printf("{red}IN [%d]{reset}:\n", IN);
	ft_printf("{blue}Filename{reset}:\t\t%s\n", file[IN].filename);
	ft_printf("{blue}Content{reset}:\t\t%s\n", file[IN].content);
	ft_printf("{blue}Fd{reset}:\t\t\t%d\n", file[IN].fd);
	ft_printf("{red}OUT [%d]{reset}:\n", OUT);
	ft_printf("{blue}Filename{reset}:\t\t%s\n", file[OUT].filename);
	ft_printf("{blue}Content{reset}:\t\t%s\n", file[OUT].content);
	ft_printf("{blue}Fd{reset}:\t\t\t%d\n", file[OUT].fd);
}
