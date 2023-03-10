/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:37:14 by jewancti          #+#    #+#             */
/*   Updated: 2023/03/02 08:41:42 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/wait.h>
# include <errno.h>
# include "./../libft/includes/libft.h"

# define IN		0
# define OUT	1

typedef struct s_plist
{
	const char		*command;
	const char		**option;
	struct s_plist	*prev;
}	t_plist;

typedef struct s_head
{
	t_plist	*first;
	t_plist	*last;
	int		length;
}	t_head;

typedef struct s_file
{
	const char	*filename;
	const char	*content;
	int			fd;
}	t_file;

typedef struct s_info
{
	int			ac;
	char		**av;

	int			fd[2];
	pid_t		pids[1024];
	int			prev_pipes;

	const char	**env;
	int			env_size;

	int			heredoc[2];
	const char	*limiter;

	int			status;
}	t_info;

typedef struct s_pipex
{
	t_plist	*plist;
	t_head	*head;
	t_file	file;
	t_info	info;
}	t_pipex;

//	list.c
t_plist		*create_elem(const char *command, const char **option, \
					t_head **head);
void		update(t_head **head, t_plist *first, t_plist *last);
void		add_elem_by_node(t_plist **list, t_plist *toadd, t_head **head);
void		add_elem(t_head **head, t_plist **list, \
						const char *command, const char **option);
//	get_paths.c
const char	**env_paths_to_string(char **env, int *size);
int			valid_command(const char *cmd, t_info info);
//	parse.c
void		parse_av(int ac, char **av, t_pipex *pipex, t_file file[2]);
//	exec.c
void		exec_cmd(t_plist *list, t_info *info);
void		exec(t_plist *lst, t_pipex *pipex, t_file **file, int index);
//	file.c
void		readfile(t_file *file, t_pipex pipex);
void		writefile(t_file *file, t_pipex pipex);
//	free.c
void		free_pipex(t_pipex pipex);
//	print.c
void		print_list(t_pipex pipex);
void		print_head(t_pipex pipex);
void		print_tfile(t_file file[2]);
//	main.c
void		close_pipe(t_info *info);

#endif
